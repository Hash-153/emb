/**
 * @file titan_control_pid.c
 * @brief PID Loop Execution with Clamping and Smooth Filtered Derivative
 */

#include "dsp/titan_control_pid.h"
#include "core/titan_defs.h"

titan_status_t titan_pid_init(titan_pid_t *pid, f32_t kp, f32_t ki, f32_t kd, f32_t kf, f32_t out_min, f32_t out_max, f32_t dt)
{
    if (!pid || dt <= 0.0f || out_min >= out_max) return TITAN_ERROR_INVALID_ARGUMENT;

    pid->kp = kp;
    pid->ki = ki;
    pid->kd = kd;
    pid->kf = kf;
    pid->out_min = out_min;
    pid->out_max = out_max;
    pid->integral_max = (ki > 0.0f) ? (out_max / ki) : out_max;
    pid->d_filter_alpha = 0.8f; /* 80% smoothing */

    titan_pid_reset(pid);
    return TITAN_OK;
}

f32_t titan_pid_update(titan_pid_t *pid, f32_t setpoint, f32_t measurement, f32_t dt)
{
    if (!pid || dt <= 0.0f) return 0.0f;

    f32_t error = setpoint - measurement;

    /* Proportional term */
    f32_t p_term = pid->kp * error;

    /* Integral term with anti-windup clamping */
    pid->integral_accum += error * dt;
    pid->integral_accum = TITAN_CLAMP(pid->integral_accum, -pid->integral_max, pid->integral_max);
    f32_t i_term = pid->ki * pid->integral_accum;

    /* Derivative term with low-pass filtering */
    f32_t raw_derivative = (error - pid->prev_error) / dt;
    f32_t filtered_derivative = pid->d_filter_alpha * pid->prev_derivative + (1.0f - pid->d_filter_alpha) * raw_derivative;
    pid->prev_derivative = filtered_derivative;
    pid->prev_error = error;
    f32_t d_term = pid->kd * filtered_derivative;

    /* Feedforward term */
    f32_t f_term = pid->kf * setpoint;

    /* Saturated total control effort */
    f32_t total = p_term + i_term + d_term + f_term;
    return TITAN_CLAMP(total, pid->out_min, pid->out_max);
}

void titan_pid_reset(titan_pid_t *pid)
{
    if (pid) {
        pid->integral_accum = 0.0f;
        pid->prev_error = 0.0f;
        pid->prev_derivative = 0.0f;
    }
}
