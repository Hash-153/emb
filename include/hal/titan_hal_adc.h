/**
 * @file titan_hal_adc.h
 * @brief 12/16-Bit Multi-Channel ADC Sequencer with Hardware Oversampling & DMA
 */

#ifndef TITAN_HAL_ADC_H
#define TITAN_HAL_ADC_H

#include "core/titan_types.h"
#include "core/titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    TITAN_ADC_1 = 0,
    TITAN_ADC_2,
    TITAN_ADC_3,
    TITAN_ADC_COUNT
} titan_adc_id_t;

#define TITAN_ADC_MAX_CHANNELS 16

typedef struct {
    titan_adc_id_t id;
    u8_t           channels[TITAN_ADC_MAX_CHANNELS];
    u8_t           channel_count;
    u16_t         *dma_dest_buffer;
    mem_size_t     dma_buffer_samples;
    u8_t           oversample_ratio; /* 2x, 4x, 8x, 16x */
} titan_adc_config_t;

titan_status_t titan_hal_adc_init(const titan_adc_config_t *cfg);
titan_status_t titan_hal_adc_start_conversion(titan_adc_id_t id);
titan_status_t titan_hal_adc_read_channel_mv(titan_adc_id_t id, u8_t channel_idx, f32_t *voltage_mv);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_HAL_ADC_H */
