/**
 * @file titan_motor_foc.c
 * @brief High Frequency Vector Current Loop Transformation and Voltage Vector Synthesizer
 */

#include "dsp/titan_motor_foc.h"
#include "core/titan_math.h"
#include "core/titan_defs.h"

#define SQRT3_OVER_2 (0.86602540378f)
#define ONE_OVER_SQRT3 (0.57735026919f)

titan_status_t titan_foc_init(titan_foc_controller_t *foc, f32_t v_bus, f32_t dt)
{
    if (!foc || v_bus <= 0.0f || dt <= 0.0f) return TITAN_ERROR_INVALID_ARGUMENT;
    foc->v_bus = v_bus;
    foc->rotor_angle_rad = 0.0f;
    titan_pid_init(&foc->pid_id, 5.0f, 100.0f, 0.0f, 0.0f, -v_bus, v_bus, dt);
    titan_pid_init(&foc->pid_iq, 5.0f, 100.0f, 0.0f, 0.0f, -v_bus, v_bus, dt);
    return TITAN_OK;
}

void titan_foc_clarke_transform(const titan_foc_phase_curr_t *in, titan_foc_alphabeta_t *out)
{
    if (!in || !out) return;
    out->alpha = in->i_a;
    out->beta = ONE_OVER_SQRT3 * (in->i_a + 2.0f * in->i_b);
}

void titan_foc_park_transform(const titan_foc_alphabeta_t *in, f32_t theta, titan_foc_dq_t *out)
{
    if (!in || !out) return;
    f32_t s = titan_fast_sin(theta);
    f32_t c = titan_fast_cos(theta);
    out->d = in->alpha * c + in->beta * s;
    out->q = -in->alpha * s + in->beta * c;
}

void titan_foc_inv_park_transform(const titan_foc_dq_t *in, f32_t theta, titan_foc_alphabeta_t *out)
{
    if (!in || !out) return;
    f32_t s = titan_fast_sin(theta);
    f32_t c = titan_fast_cos(theta);
    out->alpha = in->d * c - in->q * s;
    out->beta  = in->d * s + in->q * c;
}

void titan_foc_svpwm(const titan_foc_alphabeta_t *in, f32_t v_bus, titan_foc_pwm_t *pwm)
{
    if (!in || !pwm || v_bus <= 0.0f) return;

    /* Space Vector Modulation duty cycle calculation */
    f32_t v_alpha = in->alpha;
    f32_t v_beta = in->beta;

    f32_t v_a = v_alpha;
    f32_t v_b = -0.5f * v_alpha + SQRT3_OVER_2 * v_beta;
    f32_t v_c = -0.5f * v_alpha - SQRT3_OVER_2 * v_beta;

    f32_t v_max = TITAN_MAX(v_a, TITAN_MAX(v_b, v_c));
    f32_t v_min = TITAN_MIN(v_a, TITAN_MIN(v_b, v_c));
    f32_t v_com = 0.5f * (v_max + v_min);

    pwm->duty_a = TITAN_CLAMP((v_a - v_com) / v_bus + 0.5f, 0.0f, 1.0f);
    pwm->duty_b = TITAN_CLAMP((v_b - v_com) / v_bus + 0.5f, 0.0f, 1.0f);
    pwm->duty_c = TITAN_CLAMP((v_c - v_com) / v_bus + 0.5f, 0.0f, 1.0f);
}
