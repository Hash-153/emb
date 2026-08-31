/**
 * @file titan_drv_bms_thermal_model.c
 * @brief BMS Thermal Model Implementation
 */
#include "drivers/titan_drv_bms_thermal_model.h"
#include "core/titan_defs.h"
#include <string.h>

titan_status_t titan_bms_thermal_init(titan_bms_thermal_monitor_t *mon)
{
    if (!mon) return TITAN_ERROR_NULL_POINTER;
    memset(mon, 0, sizeof(titan_bms_thermal_monitor_t));
    mon->ambient_temp_c = 25.0f;
    mon->coolant_inlet_temp_c = 22.0f;
    mon->cell_max_temp_c = 26.5f;
    mon->thermal_runaway_threshold_c = 60.0f;
    mon->isolation_resistance_kohm = 2500.0f; /* 2.5 Mohm isolation */
    return TITAN_OK;
}

titan_status_t titan_bms_thermal_step(titan_bms_thermal_monitor_t *mon, f32_t current_a, f32_t dt)
{
    if (!mon || dt <= 0.0f) return TITAN_ERROR_INVALID_ARGUMENT;
    /* Joule heating: Q = I^2 * R_int * dt */
    f32_t heat_gen = (current_a * current_a * 0.0015f) * dt;
    mon->cell_max_temp_c += (heat_gen * 0.05f) - ((mon->cell_max_temp_c - mon->coolant_inlet_temp_c) * 0.02f * dt);
    mon->thermal_alarm = (mon->cell_max_temp_c >= mon->thermal_runaway_threshold_c);
    mon->isolation_fault = (mon->isolation_resistance_kohm < 500.0f);
    return TITAN_OK;
}

bool_t titan_bms_is_thermal_safe(const titan_bms_thermal_monitor_t *mon)
{
    if (!mon) return FALSE;
    return (!mon->thermal_alarm && !mon->isolation_fault);
}

titan_status_t titan_bms_broadcast_canfd(const titan_bms_thermal_monitor_t *mon, u8_t *can_frame, mem_size_t *frame_len) {
    if (!mon || !can_frame || !frame_len) return TITAN_ERROR_NULL_POINTER;
    can_frame[0] = (u8_t)(mon->cell_max_temp_c * 2.0f);
    can_frame[1] = (u8_t)(mon->coolant_inlet_temp_c * 2.0f);
    can_frame[2] = (u8_t)(mon->thermal_alarm ? 0xFF : 0x00);
    can_frame[3] = (u8_t)(mon->isolation_fault ? 0xFF : 0x00);
    *frame_len = 4;
    return TITAN_OK;
}
