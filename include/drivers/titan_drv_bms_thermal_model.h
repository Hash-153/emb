/**
 * @file titan_drv_bms_thermal_model.h
 * @brief High-Voltage Battery Thermal Dissipation & Isolation Monitoring
 */
#ifndef TITAN_DRV_BMS_THERMAL_MODEL_H
#define TITAN_DRV_BMS_THERMAL_MODEL_H

#include "core/titan_types.h"
#include "core/titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    f32_t ambient_temp_c;
    f32_t coolant_inlet_temp_c;
    f32_t coolant_outlet_temp_c;
    f32_t cell_max_temp_c;
    f32_t thermal_runaway_threshold_c;
    f32_t isolation_resistance_kohm;
    bool_t thermal_alarm;
    bool_t isolation_fault;
} titan_bms_thermal_monitor_t;

titan_status_t titan_bms_thermal_init(titan_bms_thermal_monitor_t *mon);
titan_status_t titan_bms_thermal_step(titan_bms_thermal_monitor_t *mon, f32_t current_a, f32_t dt);
bool_t         titan_bms_is_thermal_safe(const titan_bms_thermal_monitor_t *mon);

#ifdef __cplusplus
}
#endif
#endif
