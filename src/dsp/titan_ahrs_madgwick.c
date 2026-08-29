/**
 * @file titan_ahrs_madgwick.c
 * @brief Optimized Quaternion Gradient Descent Step Calculations
 */

#include "dsp/titan_ahrs_madgwick.h"

titan_status_t titan_madgwick_init(titan_ahrs_madgwick_t *ahrs, f32_t sample_rate_hz, f32_t beta)
{
    if (!ahrs || sample_rate_hz <= 0.0f) return TITAN_ERROR_INVALID_ARGUMENT;
    titan_quat_identity(&ahrs->quat);
    ahrs->beta = beta;
    ahrs->sample_period_s = 1.0f / sample_rate_hz;
    return TITAN_OK;
}

void titan_madgwick_update_6dof(titan_ahrs_madgwick_t *ahrs, const titan_vec3_t *accel, const titan_vec3_t *gyro)
{
    if (!ahrs || !accel || !gyro) return;

    f32_t q0 = ahrs->quat.w, q1 = ahrs->quat.x, q2 = ahrs->quat.y, q3 = ahrs->quat.z;
    f32_t gx = gyro->x, gy = gyro->y, gz = gyro->z;
    f32_t ax = accel->x, ay = accel->y, az = accel->z;

    /* Rate of change of quaternion from gyroscope */
    f32_t qDot1 = 0.5f * (-q1 * gx - q2 * gy - q3 * gz);
    f32_t qDot2 = 0.5f * ( q0 * gx + q2 * gz - q3 * gy);
    f32_t qDot3 = 0.5f * ( q0 * gy - q1 * gz + q3 * gx);
    f32_t qDot4 = 0.5f * ( q0 * gz + q1 * gy - q2 * gx);

    /* Normalize accelerometer measurement */
    f32_t a_norm_sq = ax * ax + ay * ay + az * az;
    if (a_norm_sq > 0.0f) {
        f32_t recipNorm = titan_fast_inv_sqrt(a_norm_sq);
        ax *= recipNorm;
        ay *= recipNorm;
        az *= recipNorm;

        /* Auxiliary variables */
        f32_t _2q0 = 2.0f * q0;
        f32_t _2q1 = 2.0f * q1;
        f32_t _2q2 = 2.0f * q2;
        f32_t _2q3 = 2.0f * q3;
        f32_t _4q0 = 4.0f * q0;
        f32_t _4q1 = 4.0f * q1;
        f32_t _4q2 = 4.0f * q2;
        f32_t _8q1 = 8.0f * q1;
        f32_t _8q2 = 8.0f * q2;
        f32_t q0q0 = q0 * q0;
        f32_t q1q1 = q1 * q1;
        f32_t q2q2 = q2 * q2;
        f32_t q3q3 = q3 * q3;

        /* Gradient descent algorithm step */
        f32_t s0 = _4q0 * q2q2 + _2q2 * ax + _4q0 * q1q1 - _2q1 * ay;
        f32_t s1 = _4q1 * q3q3 - _2q3 * ax + 4.0f * q0q0 * q1 - _2q0 * ay - _4q1 + _8q1 * q1q1 + _8q1 * q2q2 + _4q1 * az;
        f32_t s2 = 4.0f * q0q0 * q2 + _2q0 * ax + _4q2 * q3q3 - _2q3 * ay - _4q2 + _8q2 * q1q1 + _8q2 * q2q2 + _4q2 * az;
        f32_t s3 = 4.0f * q1q1 * q3 - _2q1 * ax + 4.0f * q2q2 * q3 - _2q2 * ay;

        f32_t s_norm_sq = s0 * s0 + s1 * s1 + s2 * s2 + s3 * s3;
        recipNorm = titan_fast_inv_sqrt(s_norm_sq);
        s0 *= recipNorm;
        s1 *= recipNorm;
        s2 *= recipNorm;
        s3 *= recipNorm;

        /* Apply feedback step */
        qDot1 -= ahrs->beta * s0;
        qDot2 -= ahrs->beta * s1;
        qDot3 -= ahrs->beta * s2;
        qDot4 -= ahrs->beta * s3;
    }

    /* Integrate rate of change of quaternion */
    q0 += qDot1 * ahrs->sample_period_s;
    q1 += qDot2 * ahrs->sample_period_s;
    q2 += qDot3 * ahrs->sample_period_s;
    q3 += qDot4 * ahrs->sample_period_s;

    /* Normalize quaternion */
    f32_t q_norm_sq = q0 * q0 + q1 * q1 + q2 * q2 + q3 * q3;
    f32_t recipNorm = titan_fast_inv_sqrt(q_norm_sq);
    ahrs->quat.w = q0 * recipNorm;
    ahrs->quat.x = q1 * recipNorm;
    ahrs->quat.y = q2 * recipNorm;
    ahrs->quat.z = q3 * recipNorm;
}

void titan_madgwick_get_euler(const titan_ahrs_madgwick_t *ahrs, titan_euler_t *euler)
{
    if (!ahrs || !euler) return;
    titan_quat_to_euler((const titan_quat_t *)&ahrs->quat, euler);
}
