/**
 * @file titan_dsp_fft.c
 * @brief Butterfly Computation and Bit-Reversal Indexing for Spectral Analysis
 */

#include "dsp/titan_dsp_fft.h"
#include "core/titan_math.h"
#include "core/titan_bitops.h"
#include <math.h>

titan_status_t titan_fft_radix2(titan_complex_t *data, u16_t n, bool_t inverse)
{
    if (!data || (n & (n - 1)) != 0 || n < 2) return TITAN_ERROR_INVALID_ARGUMENT;

    /* Bit-reversal permutation */
    u16_t log2n = 0;
    while ((1U << log2n) < n) log2n++;

    for (u16_t i = 0; i < n; ++i) {
        u16_t rev = (u16_t)(titan_bit_reverse16(i) >> (16 - log2n));
        if (rev > i) {
            titan_complex_t tmp = data[i];
            data[i] = data[rev];
            data[rev] = tmp;
        }
    }

    /* Cooley-Tukey butterfly stages */
    for (u16_t s = 1; s <= log2n; ++s) {
        u16_t m = 1U << s;
        u16_t m2 = m >> 1;
        f32_t theta = (inverse ? TITAN_TWO_PI : -TITAN_TWO_PI) / (f32_t)m;
        f32_t w_real_step = cosf(theta);
        f32_t w_imag_step = sinf(theta);

        for (u16_t k = 0; k < n; k += m) {
            f32_t wr = 1.0f;
            f32_t wi = 0.0f;
            for (u16_t j = 0; j < m2; ++j) {
                titan_complex_t *u = &data[k + j];
                titan_complex_t *v = &data[k + j + m2];

                f32_t tr = wr * v->real - wi * v->imag;
                f32_t ti = wr * v->imag + wi * v->real;

                v->real = u->real - tr;
                v->imag = u->imag - ti;
                u->real = u->real + tr;
                u->imag = u->imag + ti;

                f32_t next_wr = wr * w_real_step - wi * w_imag_step;
                wi = wr * w_imag_step + wi * w_real_step;
                wr = next_wr;
            }
        }
    }

    if (inverse) {
        f32_t inv_n = 1.0f / (f32_t)n;
        for (u16_t i = 0; i < n; ++i) {
            data[i].real *= inv_n;
            data[i].imag *= inv_n;
        }
    }

    return TITAN_OK;
}

void titan_fft_magnitude_spectrum(const titan_complex_t *fft_data, f32_t *mag_out, u16_t half_n)
{
    if (!fft_data || !mag_out) return;
    for (u16_t i = 0; i < half_n; ++i) {
        mag_out[i] = titan_fast_sqrt(fft_data[i].real * fft_data[i].real + fft_data[i].imag * fft_data[i].imag);
    }
}

f32_t titan_fft_find_peak_frequency(const f32_t *mag_spectrum, u16_t half_n, f32_t sample_rate_hz)
{
    if (!mag_spectrum || half_n == 0 || sample_rate_hz <= 0.0f) return 0.0f;
    u16_t peak_bin = 1;
    f32_t max_mag = mag_spectrum[1];

    for (u16_t i = 2; i < half_n; ++i) {
        if (mag_spectrum[i] > max_mag) {
            max_mag = mag_spectrum[i];
            peak_bin = i;
        }
    }
    return (f32_t)peak_bin * (sample_rate_hz / (f32_t)(half_n * 2));
}
