/**
 * @file titan_motor_foc.h
 * @brief Field Oriented Control (FOC): Clarke, Park, Inverse Park & Space Vector PWM (SVPWM)
 */

#ifndef TITAN_MOTOR_FOC_H
#define TITAN_MOTOR_FOC_H

#include "core/titan_types.h"
#include "core/titan_status.h"
#include "dsp/titan_control_pid.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    f32_t i_a;
    f32_t i_b;
    f32_t i_c;
} titan_foc_phase_curr_t;

typedef struct {
    f32_t alpha;
    f32_t beta;
} titan_foc_alphabeta_t;

typedef struct {
    f32_t d;
    f32_t q;
} titan_foc_dq_t;

typedef struct {
    f32_t duty_a;
    f32_t duty_b;
    f32_t duty_c;
} titan_foc_pwm_t;

typedef struct {
    titan_pid_t pid_id;
    titan_pid_t pid_iq;
    f32_t       rotor_angle_rad;
    f32_t       v_bus;
} titan_foc_controller_t;

titan_status_t titan_foc_init(titan_foc_controller_t *foc, f32_t v_bus, f32_t dt);
void           titan_foc_clarke_transform(const titan_foc_phase_curr_t *in, titan_foc_alphabeta_t *out);
void           titan_foc_park_transform(const titan_foc_alphabeta_t *in, f32_t theta, titan_foc_dq_t *out);
void           titan_foc_inv_park_transform(const titan_foc_dq_t *in, f32_t theta, titan_foc_alphabeta_t *out);
void           titan_foc_svpwm(const titan_foc_alphabeta_t *in, f32_t v_bus, titan_foc_pwm_t *pwm);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_MOTOR_FOC_H */
