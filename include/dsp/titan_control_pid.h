/**
 * @file titan_control_pid.h
 * @brief Industrial PID Controller with Anti-Windup Clamping & Derivative Low-Pass
 */

#ifndef TITAN_CONTROL_PID_H
#define TITAN_CONTROL_PID_H

#include "core/titan_types.h"
#include "core/titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    f32_t kp;                   /**< Proportional gain */
    f32_t ki;                   /**< Integral gain */
    f32_t kd;                   /**< Derivative gain */
    f32_t kf;                   /**< Feedforward gain */
    
    f32_t integral_accum;       /**< Accumulated integral state */
    f32_t prev_error;           /**< Error at step k-1 */
    f32_t prev_derivative;      /**< Filtered derivative state */
    f32_t d_filter_alpha;       /**< Derivative low-pass filter smoothing coefficient */
    
    f32_t out_min;              /**< Lower saturation bound */
    f32_t out_max;              /**< Upper saturation bound */
    f32_t integral_max;         /**< Anti-windup limit */
} titan_pid_t;

titan_status_t titan_pid_init(titan_pid_t *pid, f32_t kp, f32_t ki, f32_t kd, f32_t kf, f32_t out_min, f32_t out_max, f32_t dt);
f32_t          titan_pid_update(titan_pid_t *pid, f32_t setpoint, f32_t measurement, f32_t dt);
void           titan_pid_reset(titan_pid_t *pid);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_CONTROL_PID_H */
