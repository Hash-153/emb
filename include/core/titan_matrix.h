/**
 * @file titan_matrix.h
 * @brief Matrix Operations (3x3, 4x4, NxM) and Inversion for Kalman Filters
 */

#ifndef TITAN_MATRIX_H
#define TITAN_MATRIX_H

#include "titan_types.h"
#include "titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    u16_t rows;
    u16_t cols;
    f32_t *data;
} titan_mat_t;

typedef struct {
    f32_t m[3][3];
} titan_mat3_t;

typedef struct {
    f32_t m[4][4];
} titan_mat4_t;

/* Generic Matrix Operations */
titan_status_t titan_mat_init(titan_mat_t *mat, u16_t rows, u16_t cols, f32_t *storage);
titan_status_t titan_mat_identity(titan_mat_t *mat);
titan_status_t titan_mat_zero(titan_mat_t *mat);
titan_status_t titan_mat_add(const titan_mat_t *a, const titan_mat_t *b, titan_mat_t *out);
titan_status_t titan_mat_sub(const titan_mat_t *a, const titan_mat_t *b, titan_mat_t *out);
titan_status_t titan_mat_mult(const titan_mat_t *a, const titan_mat_t *b, titan_mat_t *out);
titan_status_t titan_mat_transpose(const titan_mat_t *src, titan_mat_t *dst);
titan_status_t titan_mat_scale(titan_mat_t *mat, f32_t scalar);
titan_status_t titan_mat_inv_gauss_jordan(const titan_mat_t *src, titan_mat_t *dst, f32_t *work_buf);

/* Fast 3x3 Specialized Operations */
void titan_mat3_identity(titan_mat3_t *m);
void titan_mat3_mult(const titan_mat3_t *a, const titan_mat3_t *b, titan_mat3_t *out);
void titan_mat3_mult_vec3(const titan_mat3_t *m, const titan_vec3_t *v, titan_vec3_t *out);
f32_t titan_mat3_det(const titan_mat3_t *m);
bool_t titan_mat3_inverse(const titan_mat3_t *src, titan_mat3_t *dst);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_MATRIX_H */
