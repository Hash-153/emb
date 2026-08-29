/**
 * @file titan_ahrs_madgwick.h
 * @brief Gradient Descent 9-DOF Quaternion Attitude and Heading Reference System (AHRS)
 */

#ifndef TITAN_AHRS_MADGWICK_H
#define TITAN_AHRS_MADGWICK_H

#include "core/titan_math.h"
#include "core/titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    titan_quat_t quat;
    f32_t        beta;      /**< Filter gain parameter */
    f32_t        sample_period_s;
} titan_ahrs_madgwick_t;

titan_status_t titan_madgwick_init(titan_ahrs_madgwick_t *ahrs, f32_t sample_rate_hz, f32_t beta);
void           titan_madgwick_update_6dof(titan_ahrs_madgwick_t *ahrs, const titan_vec3_t *accel, const titan_vec3_t *gyro);
void           titan_madgwick_update_9dof(titan_ahrs_madgwick_t *ahrs, const titan_vec3_t *accel, const titan_vec3_t *gyro, const titan_vec3_t *mag);
void           titan_madgwick_get_euler(const titan_ahrs_madgwick_t *ahrs, titan_euler_t *euler);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_AHRS_MADGWICK_H */
