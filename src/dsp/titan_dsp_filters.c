/**
 * @file titan_dsp_filters.c
 * @brief Discrete Time Biquad Filter Coefficients & Direct Form Processing
 */

#include "dsp/titan_dsp_filters.h"
#include "core/titan_math.h"
#include <string.h>
#include <math.h>

titan_status_t titan_biquad_init(titan_biquad_t *filter, titan_biquad_type_t type, f32_t sample_rate, f32_t cutoff_freq, f32_t q_factor)
{
    if (!filter || sample_rate <= 0.0f || cutoff_freq <= 0.0f || q_factor <= 0.0f) {
        return TITAN_ERROR_INVALID_ARGUMENT;
    }

    f32_t omega = TITAN_TWO_PI * cutoff_freq / sample_rate;
    f32_t sn = sinf(omega);
    f32_t cs = cosf(omega);
    f32_t alpha = sn / (2.0f * q_factor);

    f32_t a0 = 1.0f + alpha;

    switch (type) {
        case TITAN_FILTER_LOWPASS:
            filter->b0 = ((1.0f - cs) * 0.5f) / a0;
            filter->b1 = (1.0f - cs) / a0;
            filter->b2 = ((1.0f - cs) * 0.5f) / a0;
            filter->a1 = (-2.0f * cs) / a0;
            filter->a2 = (1.0f - alpha) / a0;
            break;
        case TITAN_FILTER_HIGHPASS:
            filter->b0 = ((1.0f + cs) * 0.5f) / a0;
            filter->b1 = (-(1.0f + cs)) / a0;
            filter->b2 = ((1.0f + cs) * 0.5f) / a0;
            filter->a1 = (-2.0f * cs) / a0;
            filter->a2 = (1.0f - alpha) / a0;
            break;
        case TITAN_FILTER_NOTCH:
            filter->b0 = 1.0f / a0;
            filter->b1 = (-2.0f * cs) / a0;
            filter->b2 = 1.0f / a0;
            filter->a1 = (-2.0f * cs) / a0;
            filter->a2 = (1.0f - alpha) / a0;
            break;
        default:
            return TITAN_ERROR_NOT_SUPPORTED;
    }

    filter->d1 = 0.0f;
    filter->d2 = 0.0f;
    return TITAN_OK;
}

f32_t titan_biquad_process(titan_biquad_t *filter, f32_t sample)
{
    if (!filter) return sample;
    f32_t out = filter->b0 * sample + filter->d1;
    filter->d1 = filter->b1 * sample - filter->a1 * out + filter->d2;
    filter->d2 = filter->b2 * sample - filter->a2 * out;
    return out;
}

void titan_biquad_reset(titan_biquad_t *filter)
{
    if (filter) {
        filter->d1 = 0.0f;
        filter->d2 = 0.0f;
    }
}

titan_status_t titan_moving_avg_init(titan_moving_avg_t *ma, f32_t *storage, u16_t window_size)
{
    if (!ma || !storage || window_size == 0) return TITAN_ERROR_INVALID_ARGUMENT;
    ma->buffer = storage;
    ma->window_size = window_size;
    ma->head = 0;
    ma->running_sum = 0.0f;
    ma->is_primed = FALSE;
    memset(storage, 0, sizeof(f32_t) * window_size);
    return TITAN_OK;
}

f32_t titan_moving_avg_process(titan_moving_avg_t *ma, f32_t sample)
{
    if (!ma || !ma->buffer) return sample;

    ma->running_sum -= ma->buffer[ma->head];
    ma->buffer[ma->head] = sample;
    ma->running_sum += sample;

    ma->head = (ma->head + 1) % ma->window_size;
    return ma->running_sum / (f32_t)ma->window_size;
}
