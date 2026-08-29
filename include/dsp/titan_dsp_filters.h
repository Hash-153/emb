/**
 * @file titan_dsp_filters.h
 * @brief Direct Form II Transposed Biquad IIR and Moving Average Digital Filters
 * @version 2.4.0
 * @date 2026-08-29
 */

#ifndef TITAN_DSP_FILTERS_H
#define TITAN_DSP_FILTERS_H

#include "core/titan_types.h"
#include "core/titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    TITAN_FILTER_LOWPASS = 0,
    TITAN_FILTER_HIGHPASS,
    TITAN_FILTER_BANDPASS,
    TITAN_FILTER_NOTCH
} titan_biquad_type_t;

typedef struct {
    f32_t b0, b1, b2;
    f32_t a1, a2;
    f32_t d1, d2;   /**< Delay registers */
} titan_biquad_t;

titan_status_t titan_biquad_init(titan_biquad_t *filter, titan_biquad_type_t type, f32_t sample_rate, f32_t cutoff_freq, f32_t q_factor);
f32_t          titan_biquad_process(titan_biquad_t *filter, f32_t sample);
void           titan_biquad_reset(titan_biquad_t *filter);

typedef struct {
    f32_t *buffer;
    u16_t  window_size;
    u16_t  head;
    f32_t  running_sum;
    bool_t is_primed;
} titan_moving_avg_t;

titan_status_t titan_moving_avg_init(titan_moving_avg_t *ma, f32_t *storage, u16_t window_size);
f32_t          titan_moving_avg_process(titan_moving_avg_t *ma, f32_t sample);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_DSP_FILTERS_H */
