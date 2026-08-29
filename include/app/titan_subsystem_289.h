/**
 * @file titan_subsystem_289.h
 * @brief Subsystem Telemetry & Power Distribution Unit #289
 */

#ifndef TITAN_SUBSYSTEM_289_H
#define TITAN_SUBSYSTEM_289_H

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
} titan_subsys_289_t;

titan_status_t titan_subsys_289_init(titan_subsys_289_t *sub);
titan_status_t titan_subsys_289_process(titan_subsys_289_t *sub, f32_t input, f32_t dt);
titan_status_t titan_subsys_289_enable(titan_subsys_289_t *sub, bool_t enable);
f32_t          titan_subsys_289_get_power_watts(const titan_subsys_289_t *sub);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_SUBSYSTEM_289_H */
