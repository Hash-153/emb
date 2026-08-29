/**
 * @file titan_avionics_channel_300.h
 * @brief Mission-Critical Avionics Actuation & Redundant Sensor Channel #300
 * @version 2.4.0
 * @date 2026-08-29
 */

#ifndef TITAN_AVIONICS_CHANNEL_300_H
#define TITAN_AVIONICS_CHANNEL_300_H

#include "core/titan_types.h"
#include "core/titan_status.h"
#include "core/titan_math.h"
#include "dsp/titan_control_pid.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    TITAN_CHAN_300_MODE_IDLE = 0,
    TITAN_CHAN_300_MODE_CALIBRATING,
    TITAN_CHAN_300_MODE_ACTIVE,
    TITAN_CHAN_300_MODE_FAILSAFE,
    TITAN_CHAN_300_MODE_DIAGNOSTIC
} titan_chan_300_mode_t;

typedef struct {
    u32_t                      channel_id;
    titan_chan_300_mode_t    mode;
    f32_t                      commanded_setpoint;
    f32_t                      raw_transducer_input;
    f32_t                      filtered_feedback;
    f32_t                      surface_deflection_deg;
    f32_t                      actuator_current_a;
    f32_t                      heatsink_temp_c;
    titan_pid_t                channel_pid;
    bool_t                     healthy;
    bool_t                     limit_reached;
    u32_t                      cycle_count;
    u32_t                      fault_events;
} titan_avionics_chan_300_t;

titan_status_t titan_avionics_chan_300_init(titan_avionics_chan_300_t *chan);
titan_status_t titan_avionics_chan_300_step(titan_avionics_chan_300_t *chan, f32_t setpoint, f32_t feedback, f32_t dt);
titan_status_t titan_avionics_chan_300_self_test(titan_avionics_chan_300_t *chan);
titan_status_t titan_avionics_chan_300_set_mode(titan_avionics_chan_300_t *chan, titan_chan_300_mode_t mode);
bool_t         titan_avionics_chan_300_is_healthy(const titan_avionics_chan_300_t *chan);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_AVIONICS_CHANNEL_300_H */
