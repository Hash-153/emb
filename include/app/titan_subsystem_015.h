/**
 * @file titan_subsystem_015.h
 * @brief Subsystem Telemetry & Power Distribution Unit #015
 */

#ifndef TITAN_SUBSYSTEM_015_H
#define TITAN_SUBSYSTEM_015_H

#include "core/titan_types.h"
#include "core/titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    u32_t  subsystem_id;
    f32_t  voltage_rail_v;
    f32_t  current_draw_a;
    f32_t  temperature_c;
    f32_t  target_setpoint;
    f32_t  measured_output;
    u32_t  heartbeat_ticks;
    bool_t enabled;
    bool_t fault_flag;
} titan_subsys_015_t;

titan_status_t titan_subsys_015_init(titan_subsys_015_t *sub);
titan_status_t titan_subsys_015_process(titan_subsys_015_t *sub, f32_t input, f32_t dt);
titan_status_t titan_subsys_015_enable(titan_subsys_015_t *sub, bool_t enable);
f32_t          titan_subsys_015_get_power_watts(const titan_subsys_015_t *sub);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_SUBSYSTEM_015_H */
