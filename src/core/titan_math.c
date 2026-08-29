/**
 * @file titan_math.c
 * @brief High Performance Vector, Quaternion, and Fast Approximations Implementation
 */

#include "titan_math.h"
#include <math.h>

f32_t titan_fast_sin(f32_t rad)
{
    /* Polynomial Taylor / Bhaskara I approximation */
    while (rad < -TITAN_PI) rad += TITAN_TWO_PI;
    while (rad > TITAN_PI)  rad -= TITAN_TWO_PI;

    f32_t sin_val;
    if (rad < 0) {
        sin_val = 1.27323954f * rad + 0.405284735f * rad * rad;
        if (sin_val < 0) {
            sin_val = 0.225f * (sin_val * -sin_val - sin_val) + sin_val;
        } else {
            sin_val = 0.225f * (sin_val * sin_val - sin_val) + sin_val;
        }
    } else {
        sin_val = 1.27323954f * rad - 0.405284735f * rad * rad;
        if (sin_val < 0) {
            sin_val = 0.225f * (sin_val * -sin_val - sin_val) + sin_val;
        } else {
            sin_val = 0.225f * (sin_val * sin_val - sin_val) + sin_val;
        }
    }
    return sin_val;
}

f32_t titan_fast_cos(f32_t rad)
{
    return titan_fast_sin(rad + TITAN_HALF_PI);
}

f32_t titan_fast_atan2(f32_t y, f32_t x)
{
    if (x == 0.0f) {
        if (y > 0.0f) return TITAN_HALF_PI;
        if (y < 0.0f) return -TITAN_HALF_PI;
        return 0.0f;
    }

    f32_t abs_y = TITAN_ABS(y);
    f32_t angle;
    if (x >= 0.0f) {
        f32_t r = (x - abs_y) / (x + abs_y);
        angle = 0.1963f * r * r * r - 0.9817f * r + 0.785398163f;
    } else {
        f32_t r = (x + abs_y) / (abs_y - x);
        angle = 0.1963f * r * r * r - 0.9817f * r + 2.35619449f;
    }

    return (y < 0.0f) ? -angle : angle;
}

f32_t titan_fast_inv_sqrt(f32_t val)
{
    /* Fast inverse square root (Carmack's method adapted for IEEE 754 f32) */
    union {
        f32_t f;
        u32_t i;
    } conv = { .f = val };

    f32_t xhalf = 0.5f * val;
    conv.i = 0x5f3759df - (conv.i >> 1);
    conv.f = conv.f * (1.5f - (xhalf * conv.f * conv.f));
    conv.f = conv.f * (1.5f - (xhalf * conv.f * conv.f)); /* 2nd iteration for precision */
    return conv.f;
}

f32_t titan_fast_sqrt(f32_t val)
{
    if (val <= 0.0f) return 0.0f;
    return 1.0f / titan_fast_inv_sqrt(val);
}

void titan_vec3_init(titan_vec3_t *v, f32_t x, f32_t y, f32_t z)
{
    if (!v) return;
    v->x = x;
    v->y = y;
    v->z = z;
}

void titan_vec3_add(const titan_vec3_t *a, const titan_vec3_t *b, titan_vec3_t *out)
{
    if (!a || !b || !out) return;
    out->x = a->x + b->x;
    out->y = a->y + b->y;
    out->z = a->z + b->z;
}

void titan_vec3_sub(const titan_vec3_t *a, const titan_vec3_t *b, titan_vec3_t *out)
{
    if (!a || !b || !out) return;
    out->x = a->x - b->x;
    out->y = a->y - b->y;
    out->z = a->z - b->z;
}

void titan_vec3_scale(const titan_vec3_t *v, f32_t scalar, titan_vec3_t *out)
{
    if (!v || !out) return;
    out->x = v->x * scalar;
    out->y = v->y * scalar;
    out->z = v->z * scalar;
}

f32_t titan_vec3_dot(const titan_vec3_t *a, const titan_vec3_t *b)
{
    if (!a || !b) return 0.0f;
    return (a->x * b->x) + (a->y * b->y) + (a->z * b->z);
}

void titan_vec3_cross(const titan_vec3_t *a, const titan_vec3_t *b, titan_vec3_t *out)
{
    if (!a || !b || !out) return;
    f32_t x = (a->y * b->z) - (a->z * b->y);
    f32_t y = (a->z * b->x) - (a->x * b->z);
    f32_t z = (a->x * b->y) - (a->y * b->x);
    out->x = x;
    out->y = y;
    out->z = z;
}

f32_t titan_vec3_norm(const titan_vec3_t *v)
{
    if (!v) return 0.0f;
    return titan_fast_sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
}

void titan_vec3_normalize(titan_vec3_t *v)
{
    if (!v) return;
    f32_t len_sq = (v->x * v->x) + (v->y * v->y) + (v->z * v->z);
    if (len_sq > 1e-9f) {
        f32_t inv_len = titan_fast_inv_sqrt(len_sq);
        v->x *= inv_len;
        v->y *= inv_len;
        v->z *= inv_len;
    }
}

void titan_quat_identity(titan_quat_t *q)
{
    if (!q) return;
    q->w = 1.0f;
    q->x = 0.0f;
    q->y = 0.0f;
    q->z = 0.0f;
}

void titan_quat_from_euler(titan_quat_t *q, const titan_euler_t *euler)
{
    if (!q || !euler) return;
    f32_t cr = titan_fast_cos(euler->roll * 0.5f);
    f32_t sr = titan_fast_sin(euler->roll * 0.5f);
    f32_t cp = titan_fast_cos(euler->pitch * 0.5f);
    f32_t sp = titan_fast_sin(euler->pitch * 0.5f);
    f32_t cy = titan_fast_cos(euler->yaw * 0.5f);
    f32_t sy = titan_fast_sin(euler->yaw * 0.5f);

    q->w = cr * cp * cy + sr * sp * sy;
    q->x = sr * cp * cy - cr * sp * sy;
    q->y = cr * sp * cy + sr * cp * sy;
    q->z = cr * cp * sy - sr * sp * cy;
}

void titan_quat_to_euler(const titan_quat_t *q, titan_euler_t *euler)
{
    if (!q || !euler) return;

    /* Roll (x-axis rotation) */
    f32_t sinr_cosp = 2.0f * (q->w * q->x + q->y * q->z);
    f32_t cosr_cosp = 1.0f - 2.0f * (q->x * q->x + q->y * q->y);
    euler->roll = titan_fast_atan2(sinr_cosp, cosr_cosp);

    /* Pitch (y-axis rotation) */
    f32_t sinp = 2.0f * (q->w * q->y - q->z * q->x);
    if (TITAN_ABS(sinp) >= 1.0f) {
        euler->pitch = (sinp > 0) ? TITAN_HALF_PI : -TITAN_HALF_PI;
    } else {
        euler->pitch = asinf(sinp);
    }

    /* Yaw (z-axis rotation) */
    f32_t siny_cosp = 2.0f * (q->w * q->z + q->x * q->y);
    f32_t cosy_cosp = 1.0f - 2.0f * (q->y * q->y + q->z * q->z);
    euler->yaw = titan_fast_atan2(siny_cosp, cosy_cosp);
}

void titan_quat_multiply(const titan_quat_t *a, const titan_quat_t *b, titan_quat_t *out)
{
    if (!a || !b || !out) return;
    f32_t w = a->w * b->w - a->x * b->x - a->y * b->y - a->z * b->z;
    f32_t x = a->w * b->x + a->x * b->w + a->y * b->z - a->z * b->y;
    f32_t y = a->w * b->y - a->x * b->z + a->y * b->w + a->z * b->x;
    f32_t z = a->w * b->z + a->x * b->y - a->y * b->x + a->z * b->w;
    out->w = w;
    out->x = x;
    out->y = y;
    out->z = z;
}

void titan_quat_normalize(titan_quat_t *q)
{
    if (!q) return;
    f32_t len_sq = (q->w * q->w) + (q->x * q->x) + (q->y * q->y) + (q->z * q->z);
    if (len_sq > 1e-9f) {
        f32_t inv = titan_fast_inv_sqrt(len_sq);
        q->w *= inv;
        q->x *= inv;
        q->y *= inv;
        q->z *= inv;
    }
}

void titan_quat_rotate_vec3(const titan_quat_t *q, const titan_vec3_t *v, titan_vec3_t *out)
{
    if (!q || !v || !out) return;
    titan_quat_t v_quat = { .w = 0.0f, .x = v->x, .y = v->y, .z = v->z };
    titan_quat_t q_conj = { .w = q->w, .x = -q->x, .y = -q->y, .z = -q->z };
    titan_quat_t tmp;

    titan_quat_multiply(q, &v_quat, &tmp);
    titan_quat_multiply(&tmp, &q_conj, &v_quat);

    out->x = v_quat.x;
    out->y = v_quat.y;
    out->z = v_quat.z;
}

q15_t titan_q15_add(q15_t a, q15_t b)
{
    s32_t sum = (s32_t)a + (s32_t)b;
    return (q15_t)TITAN_CLAMP(sum, -32768, 32767);
}

q15_t titan_q15_sub(q15_t a, q15_t b)
{
    s32_t diff = (s32_t)a - (s32_t)b;
    return (q15_t)TITAN_CLAMP(diff, -32768, 32767);
}

q15_t titan_q15_mul(q15_t a, q15_t b)
{
    s32_t prod = ((s32_t)a * (s32_t)b) >> 15;
    return (q15_t)TITAN_CLAMP(prod, -32768, 32767);
}

q31_t titan_q31_mul(q31_t a, q31_t b)
{
    s64_t prod = ((s64_t)a * (s64_t)b) >> 31;
    if (prod > 2147483647LL) return 2147483647;
    if (prod < -2147483648LL) return -2147483648LL;
    return (q31_t)prod;
}
