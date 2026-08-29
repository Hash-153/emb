/**
 * @file titan_dsp_fft.h
 * @brief In-Place Radix-2 Decimation-in-Time Fast Fourier Transform (FFT)
 */

#ifndef TITAN_DSP_FFT_H
#define TITAN_DSP_FFT_H

#include "core/titan_types.h"
#include "core/titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    f32_t real;
    f32_t imag;
} titan_complex_t;

titan_status_t titan_fft_radix2(titan_complex_t *data, u16_t n, bool_t inverse);
void           titan_fft_magnitude_spectrum(const titan_complex_t *fft_data, f32_t *mag_out, u16_t half_n);
f32_t          titan_fft_find_peak_frequency(const f32_t *mag_spectrum, u16_t half_n, f32_t sample_rate_hz);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_DSP_FFT_H */
