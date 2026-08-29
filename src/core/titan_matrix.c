/**
 * @file titan_matrix.c
 * @brief Matrix Math Implementations with Deterministic Pivoting
 */

#include "titan_matrix.h"
#include <string.h>

titan_status_t titan_mat_init(titan_mat_t *mat, u16_t rows, u16_t cols, f32_t *storage)
{
    if (!mat || !storage || rows == 0 || cols == 0) return TITAN_ERROR_INVALID_ARGUMENT;
    mat->rows = rows;
    mat->cols = cols;
    mat->data = storage;
    return TITAN_OK;
}

titan_status_t titan_mat_identity(titan_mat_t *mat)
{
    if (!mat || !mat->data || mat->rows != mat->cols) return TITAN_ERROR_INVALID_ARGUMENT;
    memset(mat->data, 0, sizeof(f32_t) * mat->rows * mat->cols);
    for (u16_t i = 0; i < mat->rows; ++i) {
        mat->data[i * mat->cols + i] = 1.0f;
    }
    return TITAN_OK;
}

titan_status_t titan_mat_zero(titan_mat_t *mat)
{
    if (!mat || !mat->data) return TITAN_ERROR_NULL_POINTER;
    memset(mat->data, 0, sizeof(f32_t) * mat->rows * mat->cols);
    return TITAN_OK;
}

titan_status_t titan_mat_add(const titan_mat_t *a, const titan_mat_t *b, titan_mat_t *out)
{
    if (!a || !b || !out) return TITAN_ERROR_NULL_POINTER;
    if (a->rows != b->rows || a->cols != b->cols || a->rows != out->rows || a->cols != out->cols) {
        return TITAN_ERROR_INVALID_ARGUMENT;
    }
    u32_t total = (u32_t)a->rows * a->cols;
    for (u32_t i = 0; i < total; ++i) {
        out->data[i] = a->data[i] + b->data[i];
    }
    return TITAN_OK;
}

titan_status_t titan_mat_sub(const titan_mat_t *a, const titan_mat_t *b, titan_mat_t *out)
{
    if (!a || !b || !out) return TITAN_ERROR_NULL_POINTER;
    if (a->rows != b->rows || a->cols != b->cols || a->rows != out->rows || a->cols != out->cols) {
        return TITAN_ERROR_INVALID_ARGUMENT;
    }
    u32_t total = (u32_t)a->rows * a->cols;
    for (u32_t i = 0; i < total; ++i) {
        out->data[i] = a->data[i] - b->data[i];
    }
    return TITAN_OK;
}

titan_status_t titan_mat_mult(const titan_mat_t *a, const titan_mat_t *b, titan_mat_t *out)
{
    if (!a || !b || !out) return TITAN_ERROR_NULL_POINTER;
    if (a->cols != b->rows || a->rows != out->rows || b->cols != out->cols) {
        return TITAN_ERROR_INVALID_ARGUMENT;
    }

    for (u16_t r = 0; r < a->rows; ++r) {
        for (u16_t c = 0; c < b->cols; ++c) {
            f32_t sum = 0.0f;
            for (u16_t k = 0; k < a->cols; ++k) {
                sum += a->data[r * a->cols + k] * b->data[k * b->cols + c];
            }
            out->data[r * out->cols + c] = sum;
        }
    }
    return TITAN_OK;
}

titan_status_t titan_mat_transpose(const titan_mat_t *src, titan_mat_t *dst)
{
    if (!src || !dst) return TITAN_ERROR_NULL_POINTER;
    if (src->rows != dst->cols || src->cols != dst->rows) return TITAN_ERROR_INVALID_ARGUMENT;

    for (u16_t r = 0; r < src->rows; ++r) {
        for (u16_t c = 0; c < src->cols; ++c) {
            dst->data[c * dst->cols + r] = src->data[r * src->cols + c];
        }
    }
    return TITAN_OK;
}

titan_status_t titan_mat_scale(titan_mat_t *mat, f32_t scalar)
{
    if (!mat || !mat->data) return TITAN_ERROR_NULL_POINTER;
    u32_t total = (u32_t)mat->rows * mat->cols;
    for (u32_t i = 0; i < total; ++i) {
        mat->data[i] *= scalar;
    }
    return TITAN_OK;
}

titan_status_t titan_mat_inv_gauss_jordan(const titan_mat_t *src, titan_mat_t *dst, f32_t *work_buf)
{
    if (!src || !dst || !work_buf || src->rows != src->cols) return TITAN_ERROR_INVALID_ARGUMENT;
    u16_t n = src->rows;

    /* Copy src into work_buf and initialize dst as identity */
    memcpy(work_buf, src->data, sizeof(f32_t) * n * n);
    titan_mat_identity(dst);

    for (u16_t i = 0; i < n; ++i) {
        /* Find pivot */
        u16_t max_row = i;
        f32_t max_val = TITAN_ABS(work_buf[i * n + i]);
        for (u16_t k = i + 1; k < n; ++k) {
            f32_t val = TITAN_ABS(work_buf[k * n + i]);
            if (val > max_val) {
                max_val = val;
                max_row = k;
            }
        }

        if (max_val < 1e-12f) {
            return TITAN_ERROR_INVALID_ARGUMENT; /* Singular matrix */
        }

        /* Swap rows */
        if (max_row != i) {
            for (u16_t k = 0; k < n; ++k) {
                f32_t tmp = work_buf[i * n + k];
                work_buf[i * n + k] = work_buf[max_row * n + k];
                work_buf[max_row * n + k] = tmp;

                tmp = dst->data[i * n + k];
                dst->data[i * n + k] = dst->data[max_row * n + k];
                dst->data[max_row * n + k] = tmp;
            }
        }

        /* Normalize pivot row */
        f32_t pivot = work_buf[i * n + i];
        f32_t inv_pivot = 1.0f / pivot;
        for (u16_t k = 0; k < n; ++k) {
            work_buf[i * n + k] *= inv_pivot;
            dst->data[i * n + k] *= inv_pivot;
        }

        /* Eliminate other rows */
        for (u16_t r = 0; r < n; ++r) {
            if (r != i) {
                f32_t factor = work_buf[r * n + i];
                for (u16_t k = 0; k < n; ++k) {
                    work_buf[r * n + k] -= factor * work_buf[i * n + k];
                    dst->data[r * n + k] -= factor * dst->data[i * n + k];
                }
            }
        }
    }
    return TITAN_OK;
}

void titan_mat3_identity(titan_mat3_t *m)
{
    if (!m) return;
    memset(m, 0, sizeof(titan_mat3_t));
    m->m[0][0] = 1.0f;
    m->m[1][1] = 1.0f;
    m->m[2][2] = 1.0f;
}

void titan_mat3_mult(const titan_mat3_t *a, const titan_mat3_t *b, titan_mat3_t *out)
{
    if (!a || !b || !out) return;
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            out->m[r][c] = a->m[r][0] * b->m[0][c] +
                           a->m[r][1] * b->m[1][c] +
                           a->m[r][2] * b->m[2][c];
        }
    }
}

void titan_mat3_mult_vec3(const titan_mat3_t *m, const titan_vec3_t *v, titan_vec3_t *out)
{
    if (!m || !v || !out) return;
    f32_t x = m->m[0][0] * v->x + m->m[0][1] * v->y + m->m[0][2] * v->z;
    f32_t y = m->m[1][0] * v->x + m->m[1][1] * v->y + m->m[1][2] * v->z;
    f32_t z = m->m[2][0] * v->x + m->m[2][1] * v->y + m->m[2][2] * v->z;
    out->x = x;
    out->y = y;
    out->z = z;
}

f32_t titan_mat3_det(const titan_mat3_t *m)
{
    if (!m) return 0.0f;
    return m->m[0][0] * (m->m[1][1] * m->m[2][2] - m->m[1][2] * m->m[2][1]) -
           m->m[0][1] * (m->m[1][0] * m->m[2][2] - m->m[1][2] * m->m[2][0]) +
           m->m[0][2] * (m->m[1][0] * m->m[2][1] - m->m[1][1] * m->m[2][0]);
}

bool_t titan_mat3_inverse(const titan_mat3_t *src, titan_mat3_t *dst)
{
    if (!src || !dst) return FALSE;
    f32_t det = titan_mat3_det(src);
    if (TITAN_ABS(det) < 1e-9f) return FALSE;

    f32_t inv_det = 1.0f / det;
    dst->m[0][0] = (src->m[1][1] * src->m[2][2] - src->m[1][2] * src->m[2][1]) * inv_det;
    dst->m[0][1] = (src->m[0][2] * src->m[2][1] - src->m[0][1] * src->m[2][2]) * inv_det;
    dst->m[0][2] = (src->m[0][1] * src->m[1][2] - src->m[0][2] * src->m[1][1]) * inv_det;

    dst->m[1][0] = (src->m[1][2] * src->m[2][0] - src->m[1][0] * src->m[2][2]) * inv_det;
    dst->m[1][1] = (src->m[0][0] * src->m[2][2] - src->m[0][2] * src->m[2][0]) * inv_det;
    dst->m[1][2] = (src->m[0][2] * src->m[1][0] - src->m[0][0] * src->m[1][2]) * inv_det;

    dst->m[2][0] = (src->m[1][0] * src->m[2][1] - src->m[1][1] * src->m[2][0]) * inv_det;
    dst->m[2][1] = (src->m[0][1] * src->m[2][0] - src->m[0][0] * src->m[2][1]) * inv_det;
    dst->m[2][2] = (src->m[0][0] * src->m[1][1] - src->m[0][1] * src->m[1][0]) * inv_det;

    return TRUE;
}
