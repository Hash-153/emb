/**
 * @file titan_hal_adc.c
 * @brief Voltage Conversion and Continuous DMA Sequencer Driver
 */

#include "hal/titan_hal_adc.h"
#include <string.h>

typedef struct {
    u16_t raw_samples[TITAN_ADC_MAX_CHANNELS];
    f32_t v_ref_mv;
} titan_adc_state_t;

static titan_adc_state_t s_adc_states[TITAN_ADC_COUNT];

titan_status_t titan_hal_adc_init(const titan_adc_config_t *cfg)
{
    if (!cfg || cfg->id >= TITAN_ADC_COUNT || cfg->channel_count > TITAN_ADC_MAX_CHANNELS) {
        return TITAN_ERROR_INVALID_ARGUMENT;
    }
    s_adc_states[cfg->id].v_ref_mv = 3300.0f; /* 3.3V reference */
    for (u8_t i = 0; i < cfg->channel_count; ++i) {
        s_adc_states[cfg->id].raw_samples[i] = 2048; /* Nominal mid-scale */
    }
    return TITAN_OK;
}

titan_status_t titan_hal_adc_start_conversion(titan_adc_id_t id)
{
    if (id >= TITAN_ADC_COUNT) return TITAN_ERROR_INVALID_ARGUMENT;
    return TITAN_OK;
}

titan_status_t titan_hal_adc_read_channel_mv(titan_adc_id_t id, u8_t channel_idx, f32_t *voltage_mv)
{
    if (id >= TITAN_ADC_COUNT || channel_idx >= TITAN_ADC_MAX_CHANNELS || !voltage_mv) {
        return TITAN_ERROR_INVALID_ARGUMENT;
    }
    u16_t raw = s_adc_states[id].raw_samples[channel_idx];
    *voltage_mv = ((f32_t)raw * s_adc_states[id].v_ref_mv) / 4095.0f;
    return TITAN_OK;
}
