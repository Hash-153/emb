/**
 * @file titan_subsystem_116.c
 * @brief Subsystem Controller #116 Logic
 */

#include "app/titan_subsystem_116.h"
#include <string.h>

titan_status_t titan_subsys_116_init(titan_subsys_116_t *sub)
{
    if (!sub) return TITAN_ERROR_NULL_POINTER;
    memset(sub, 0, sizeof(titan_subsys_116_t));
    sub->subsystem_id = 116;
    sub->voltage_rail_v = 28.0f;
    sub->temperature_c = 22.0f;
    sub->enabled = TRUE;
    return TITAN_OK;
}

titan_status_t titan_subsys_116_process(titan_subsys_116_t *sub, f32_t input, f32_t dt)
{
    if (!sub || dt <= 0.0f) return TITAN_ERROR_INVALID_ARGUMENT;
    if (!sub->enabled) return TITAN_OK;

    sub->target_setpoint = input;
    sub->measured_output += (input - sub->measured_output) * 0.15f;
    sub->current_draw_a = 0.5f + (sub->measured_output * 0.05f);
    sub->heartbeat_ticks++;

    return TITAN_OK;
}

titan_status_t titan_subsys_116_enable(titan_subsys_116_t *sub, bool_t enable)
{
    if (!sub) return TITAN_ERROR_NULL_POINTER;
    sub->enabled = enable;
    return TITAN_OK;
}

f32_t titan_subsys_116_get_power_watts(const titan_subsys_116_t *sub)
{
    if (!sub) return 0.0f;
    return sub->voltage_rail_v * sub->current_draw_a;
}
