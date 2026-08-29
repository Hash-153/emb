/**
 * @file titan_drv_bms.h
 * @brief High-Voltage Industrial Battery Management Subsystem (HV-BMS)
 */

#ifndef TITAN_DRV_BMS_H
#define TITAN_DRV_BMS_H

#include "core/titan_types.h"
#include "core/titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TITAN_BMS_MAX_CELLS 96
#define TITAN_BMS_MAX_TEMPS 32

typedef struct {
    f32_t cell_voltages_v[TITAN_BMS_MAX_CELLS];
    f32_t temperatures_c[TITAN_BMS_MAX_TEMPS];
    f32_t pack_voltage_v;
    f32_t pack_current_a;
    f32_t state_of_charge_pct;
    f32_t state_of_health_pct;
    f32_t min_cell_v;
    f32_t max_cell_v;
    f32_t cell_delta_v;
    u32_t balance_switch_mask[3]; /* 96 balancing FETs */
    bool_t overvoltage_fault;
    bool_t undervoltage_fault;
    bool_t overcurrent_fault;
    bool_t overtemperature_fault;
} titan_bms_pack_status_t;

typedef struct {
    f32_t v_cell_max_limit;
    f32_t v_cell_min_limit;
    f32_t temp_max_limit;
    f32_t balance_threshold_v;
    f32_t nominal_capacity_ah;
} titan_bms_config_t;

titan_status_t titan_bms_init(const titan_bms_config_t *cfg);
titan_status_t titan_bms_update_measurements(titan_bms_pack_status_t *status);
titan_status_t titan_bms_run_cell_balancing(titan_bms_pack_status_t *status);
titan_status_t titan_bms_estimate_soc_coulomb(titan_bms_pack_status_t *status, f32_t current_a, f32_t dt_s);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_DRV_BMS_H */
