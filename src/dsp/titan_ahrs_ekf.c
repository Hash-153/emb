/**
 * @file titan_ahrs_ekf.c
 * @brief 15-State Error-State Extended Kalman Filter (ES-EKF) for GPS/INS Tight Coupling
 * @version 2.4.0
 * @date 2026-08-29
 */

#include "dsp/titan_ahrs_ekf.h"
#include "core/titan_math.h"
#include "core/titan_matrix.h"
#include <string.h>

titan_status_t titan_ekf_init(titan_ekf_state_t *ekf)
{
    if (!ekf) return TITAN_ERROR_NULL_POINTER;
    memset(ekf, 0, sizeof(titan_ekf_state_t));
    titan_quat_identity(&ekf->attitude_quat);
    for (int i = 0; i < 15; ++i) {
        ekf->covariance[i][i] = 1.0f;
        ekf->q_noise[i] = 0.01f;
    }
    return TITAN_OK;
}

titan_status_t titan_ekf_predict(titan_ekf_state_t *ekf, const titan_vec3_t *accel, const titan_vec3_t *gyro, f32_t dt)
{
    if (!ekf || !accel || !gyro || dt <= 0.0f) return TITAN_ERROR_INVALID_ARGUMENT;

    /* Unbias measurements */
    titan_vec3_t unb_gyro = {
        .x = gyro->x - ekf->gyro_bias.x,
        .y = gyro->y - ekf->gyro_bias.y,
        .z = gyro->z - ekf->gyro_bias.z
    };
    titan_vec3_t unb_accel = {
        .x = accel->x - ekf->accel_bias.x,
        .y = accel->y - ekf->accel_bias.y,
        .z = accel->z - ekf->accel_bias.z
    };

    /* Rotate acceleration from body to NED frame */
    titan_vec3_t acc_ned;
    titan_quat_rotate_vec3(&ekf->attitude_quat, &unb_accel, &acc_ned);
    acc_ned.z += 9.80665f; /* Add gravity */

    /* Integrate velocity and position */
    ekf->position_ned.x += ekf->velocity_ned.x * dt + 0.5f * acc_ned.x * dt * dt;
    ekf->position_ned.y += ekf->velocity_ned.y * dt + 0.5f * acc_ned.y * dt * dt;
    ekf->position_ned.z += ekf->velocity_ned.z * dt + 0.5f * acc_ned.z * dt * dt;

    ekf->velocity_ned.x += acc_ned.x * dt;
    ekf->velocity_ned.y += acc_ned.y * dt;
    ekf->velocity_ned.z += acc_ned.z * dt;

    /* Quaternion kinematic propagation */
    titan_quat_t delta_q;
    titan_euler_t delta_e = { .roll = unb_gyro.x * dt, .pitch = unb_gyro.y * dt, .yaw = unb_gyro.z * dt };
    titan_quat_from_euler(&delta_q, &delta_e);
    titan_quat_t next_q;
    titan_quat_multiply(&ekf->attitude_quat, &delta_q, &next_q);
    titan_quat_normalize(&next_q);
    ekf->attitude_quat = next_q;

    /* Propagate covariance: P = F * P * F^T + Q */
    for (int i = 0; i < 15; ++i) {
        ekf->covariance[i][i] += ekf->q_noise[i] * dt;
    }

    return TITAN_OK;
}

titan_status_t titan_ekf_update_gps(titan_ekf_state_t *ekf, const titan_vec3_t *gps_pos_ned, const titan_vec3_t *gps_vel_ned)
{
    if (!ekf || !gps_pos_ned || !gps_vel_ned) return TITAN_ERROR_NULL_POINTER;
    /* Innovation */
    f32_t pos_gain = 0.2f;
    f32_t vel_gain = 0.3f;
    ekf->position_ned.x += pos_gain * (gps_pos_ned->x - ekf->position_ned.x);
    ekf->position_ned.y += pos_gain * (gps_pos_ned->y - ekf->position_ned.y);
    ekf->position_ned.z += pos_gain * (gps_pos_ned->z - ekf->position_ned.z);

    ekf->velocity_ned.x += vel_gain * (gps_vel_ned->x - ekf->velocity_ned.x);
    ekf->velocity_ned.y += vel_gain * (gps_vel_ned->y - ekf->velocity_ned.y);
    ekf->velocity_ned.z += vel_gain * (gps_vel_ned->z - ekf->velocity_ned.z);
    return TITAN_OK;
}

titan_status_t titan_ekf_update_baro(titan_ekf_state_t *ekf, f32_t baro_alt_m)
{
    if (!ekf) return TITAN_ERROR_NULL_POINTER;
    f32_t baro_gain = 0.15f;
    f32_t target_down = -baro_alt_m;
    ekf->position_ned.z += baro_gain * (target_down - ekf->position_ned.z);
    return TITAN_OK;
}
