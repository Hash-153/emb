/**
 * @file titan_hal_timer.h
 * @brief High-Resolution Advanced Timer & Complementary 3-Phase PWM Driver
 */

#ifndef TITAN_HAL_TIMER_H
#define TITAN_HAL_TIMER_H

#include "core/titan_types.h"
#include "core/titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    TITAN_TIM_1 = 0,
    TITAN_TIM_2,
    TITAN_TIM_3,
    TITAN_TIM_4,
    TITAN_TIM_COUNT
} titan_tim_id_t;

typedef enum {
    TITAN_PWM_CH_1 = 0,
    TITAN_PWM_CH_2,
    TITAN_PWM_CH_3,
    TITAN_PWM_CH_4
} titan_pwm_channel_t;

typedef struct {
    titan_tim_id_t tim_id;
    u32_t          frequency_hz;
    u16_t          dead_time_ns;
    bool_t         complementary_enabled;
} titan_timer_config_t;

titan_status_t titan_hal_timer_init(const titan_timer_config_t *cfg);
titan_status_t titan_hal_pwm_set_duty(titan_tim_id_t tim, titan_pwm_channel_t ch, f32_t duty_0_to_1);
titan_status_t titan_hal_timer_start(titan_tim_id_t tim);
titan_status_t titan_hal_timer_stop(titan_tim_id_t tim);
u32_t          titan_hal_timer_get_counter(titan_tim_id_t tim);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_HAL_TIMER_H */
