/**
 * @file titan_ahrs_ekf.h
 * @brief 15-State Extended Kalman Filter (Position, Velocity, Attitude, Gyro Bias, Accel Bias)
 */

#ifndef TITAN_AHRS_EKF_H
#define TITAN_AHRS_EKF_H

#include "core/titan_types.h"
#include "core/titan_status.h"
#include "core/titan_math.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    titan_vec3_t position_ned;      /**< States 0..2: Position in meters (North, East, Down) */
    titan_vec3_t velocity_ned;      /**< States 3..5: Velocity in m/s */
    titan_quat_t attitude_quat;     /**< States 6..9: Attitude quaternion */
    titan_vec3_t gyro_bias;         /**< States 10..12: Gyroscope bias in rad/s */
    titan_vec3_t accel_bias;        /**< States 13..15: Accelerometer bias in m/s^2 */
    f32_t        covariance[15][15];/**< Error covariance matrix P */
    f32_t        q_noise[15];       /**< Process noise diagonal */
} titan_ekf_state_t;

titan_status_t titan_ekf_init(titan_ekf_state_t *ekf);
titan_status_t titan_ekf_predict(titan_ekf_state_t *ekf, const titan_vec3_t *accel, const titan_vec3_t *gyro, f32_t dt);
titan_status_t titan_ekf_update_gps(titan_ekf_state_t *ekf, const titan_vec3_t *gps_pos_ned, const titan_vec3_t *gps_vel_ned);
titan_status_t titan_ekf_update_baro(titan_ekf_state_t *ekf, f32_t baro_alt_m);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_AHRS_EKF_H */
