/**
 * @file titan_avionics_channel_107.c
 * @brief Avionics Redundant Channel #107 Implementation
 */

#include "app/titan_avionics_channel_107.h"
#include "core/titan_defs.h"
#include <string.h>

titan_status_t titan_avionics_chan_107_init(titan_avionics_chan_107_t *chan)
{
    if (!chan) return TITAN_ERROR_NULL_POINTER;
    memset(chan, 0, sizeof(titan_avionics_chan_107_t));
    chan->channel_id = 107;
    chan->mode = TITAN_CHAN_107_MODE_IDLE;
    chan->healthy = TRUE;
    chan->heatsink_temp_c = 25.0f;
    titan_pid_init(&chan->channel_pid, 3.34f, 0.685f, 0.025f, 0.0f, -35.0f, 35.0f, 0.002f);
    return TITAN_OK;
}

titan_status_t titan_avionics_chan_107_step(titan_avionics_chan_107_t *chan, f32_t setpoint, f32_t feedback, f32_t dt)
{
    if (!chan || dt <= 0.0f) return TITAN_ERROR_INVALID_ARGUMENT;

    chan->commanded_setpoint = setpoint;
    chan->raw_transducer_input = feedback;
    chan->filtered_feedback = feedback;

    if (chan->mode == TITAN_CHAN_107_MODE_ACTIVE) {
        f32_t output = titan_pid_update(&chan->channel_pid, setpoint, feedback, dt);
        chan->surface_deflection_deg = TITAN_CLAMP(output, -35.0f, 35.0f);
        chan->limit_reached = (output > 34.9f || output < -34.9f);
    } else if (chan->mode == TITAN_CHAN_107_MODE_FAILSAFE) {
        chan->surface_deflection_deg = 0.0f;
    }

    chan->cycle_count++;
    return TITAN_OK;
}

titan_status_t titan_avionics_chan_107_self_test(titan_avionics_chan_107_t *chan)
{
    if (!chan) return TITAN_ERROR_NULL_POINTER;
    chan->healthy = (chan->fault_events == 0);
    return chan->healthy ? TITAN_OK : TITAN_ERROR_GENERIC;
}

titan_status_t titan_avionics_chan_107_set_mode(titan_avionics_chan_107_t *chan, titan_chan_107_mode_t mode)
{
    if (!chan) return TITAN_ERROR_NULL_POINTER;
    chan->mode = mode;
    return TITAN_OK;
}

bool_t titan_avionics_chan_107_is_healthy(const titan_avionics_chan_107_t *chan)
{
    if (!chan) return FALSE;
    return chan->healthy;
}
