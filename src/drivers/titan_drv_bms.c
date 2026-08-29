/**
 * @file titan_bms_cell_matrix.c
 * @brief High-Voltage 96-Cell Lithium Pack Balancing, State of Charge (SoC) & State of Health (SoH)
 * @version 2.4.0
 * @date 2026-08-29
 */

#include "drivers/titan_drv_bms.h"
#include "core/titan_math.h"
#include "core/titan_defs.h"
#include <string.h>

static titan_bms_config_t s_bms_cfg;
static f32_t s_accumulated_charge_as = 0.0f;

titan_status_t titan_bms_init(const titan_bms_config_t *cfg)
{
    if (!cfg) return TITAN_ERROR_NULL_POINTER;
    s_bms_cfg = *cfg;
    s_accumulated_charge_as = cfg->nominal_capacity_ah * 3600.0f;
    return TITAN_OK;
}

titan_status_t titan_bms_update_measurements(titan_bms_pack_status_t *status)
{
    if (!status) return TITAN_ERROR_NULL_POINTER;

    f32_t sum_v = 0.0f;
    f32_t min_v = 100.0f;
    f32_t max_v = -100.0f;

    for (int i = 0; i < TITAN_BMS_MAX_CELLS; ++i) {
        /* Nominal 3.7V Li-ion cell emulation */
        status->cell_voltages_v[i] = 3.70f + (f32_t)(i % 5) * 0.005f;
        f32_t v = status->cell_voltages_v[i];
        sum_v += v;
        if (v < min_v) min_v = v;
        if (v > max_v) max_v = v;
    }

    for (int j = 0; j < TITAN_BMS_MAX_TEMPS; ++j) {
        status->temperatures_c[j] = 28.5f + (f32_t)(j % 3) * 0.5f;
    }

    status->pack_voltage_v = sum_v;
    status->min_cell_v = min_v;
    status->max_cell_v = max_v;
    status->cell_delta_v = max_v - min_v;

    /* Check thresholds */
    status->overvoltage_fault = (max_v > s_bms_cfg.v_cell_max_limit);
    status->undervoltage_fault = (min_v < s_bms_cfg.v_cell_min_limit);

    return TITAN_OK;
}

titan_status_t titan_bms_run_cell_balancing(titan_bms_pack_status_t *status)
{
    if (!status) return TITAN_ERROR_NULL_POINTER;
    memset(status->balance_switch_mask, 0, sizeof(status->balance_switch_mask));

    for (int i = 0; i < TITAN_BMS_MAX_CELLS; ++i) {
        if (status->cell_voltages_v[i] - status->min_cell_v > s_bms_cfg.balance_threshold_v) {
            int word_idx = i / 32;
            int bit_idx = i % 32;
            status->balance_switch_mask[word_idx] |= (1UL << bit_idx);
        }
    }
    return TITAN_OK;
}

titan_status_t titan_bms_estimate_soc_coulomb(titan_bms_pack_status_t *status, f32_t current_a, f32_t dt_s)
{
    if (!status || dt_s <= 0.0f) return TITAN_ERROR_INVALID_ARGUMENT;
    s_accumulated_charge_as -= current_a * dt_s;
    f32_t total_as = s_bms_cfg.nominal_capacity_ah * 3600.0f;
    if (total_as > 0.0f) {
        status->state_of_charge_pct = TITAN_CLAMP((s_accumulated_charge_as / total_as) * 100.0f, 0.0f, 100.0f);
    }
    return TITAN_OK;
}
