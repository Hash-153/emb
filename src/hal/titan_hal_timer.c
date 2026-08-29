/**
 * @file titan_hal_timer.c
 * @brief Advanced Timer Channel & Dead-Band Generator Driver
 */

#include "hal/titan_hal_timer.h"
#include "core/titan_defs.h"
#include <string.h>

typedef struct {
    u32_t counter;
    u32_t period;
    f32_t duty[4];
    bool_t is_running;
} titan_timer_state_t;

static titan_timer_state_t s_timers[TITAN_TIM_COUNT];

titan_status_t titan_hal_timer_init(const titan_timer_config_t *cfg)
{
    if (!cfg || cfg->tim_id >= TITAN_TIM_COUNT) return TITAN_ERROR_INVALID_ARGUMENT;
    s_timers[cfg->tim_id].counter = 0;
    s_timers[cfg->tim_id].period = (cfg->frequency_hz > 0) ? (1000000 / cfg->frequency_hz) : 1000;
    s_timers[cfg->tim_id].is_running = FALSE;
    return TITAN_OK;
}

titan_status_t titan_hal_pwm_set_duty(titan_tim_id_t tim, titan_pwm_channel_t ch, f32_t duty_0_to_1)
{
    if (tim >= TITAN_TIM_COUNT || ch > TITAN_PWM_CH_4) return TITAN_ERROR_INVALID_ARGUMENT;
    s_timers[tim].duty[ch] = TITAN_CLAMP(duty_0_to_1, 0.0f, 1.0f);
    return TITAN_OK;
}

titan_status_t titan_hal_timer_start(titan_tim_id_t tim)
{
    if (tim >= TITAN_TIM_COUNT) return TITAN_ERROR_INVALID_ARGUMENT;
    s_timers[tim].is_running = TRUE;
    return TITAN_OK;
}

titan_status_t titan_hal_timer_stop(titan_tim_id_t tim)
{
    if (tim >= TITAN_TIM_COUNT) return TITAN_ERROR_INVALID_ARGUMENT;
    s_timers[tim].is_running = FALSE;
    return TITAN_OK;
}

u32_t titan_hal_timer_get_counter(titan_tim_id_t tim)
{
    if (tim >= TITAN_TIM_COUNT) return 0;
    return s_timers[tim].counter++;
}
