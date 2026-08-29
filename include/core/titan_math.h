/**
 * @file titan_math.h
 * @brief Fast Fixed-Point, Vector3, Quaternion, and Trigonometric Approximations
 */

#ifndef TITAN_MATH_H
#define TITAN_MATH_H

#include "titan_types.h"
#include "titan_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TITAN_PI            (3.14159265358979323846f)
#define TITAN_TWO_PI        (6.28318530717958647692f)
#define TITAN_HALF_PI       (1.57079632679489661923f)
#define TITAN_DEG_TO_RAD    (0.01745329251994329576f)
#define TITAN_RAD_TO_DEG    (57.2957795130823208767f)

/* Q15 Fixed Point Helpers */
#define TITAN_F32_TO_Q15(f) ((q15_t)((f) * 32768.0f))
#define TITAN_Q15_TO_F32(q) ((f32_t)(q) / 32768.0f)
#define TITAN_F32_TO_Q31(f) ((q31_t)((f) * 2147483648.0f))
#define TITAN_Q31_TO_F32(q) ((f32_t)(q) / 2147483648.0f)

typedef struct {
    f32_t x;
    f32_t y;
    f32_t z;
} titan_vec3_t;

typedef struct {
    f32_t w;
    f32_t x;
    f32_t y;
    f32_t z;
} titan_quat_t;

typedef struct {
    f32_t roll;     /**< Rotation around X axis (radians) */
    f32_t pitch;    /**< Rotation around Y axis (radians) */
    f32_t yaw;      /**< Rotation around Z axis (radians) */
} titan_euler_t;

/* Fast Math Functions */
f32_t titan_fast_sin(f32_t rad);
f32_t titan_fast_cos(f32_t rad);
f32_t titan_fast_atan2(f32_t y, f32_t x);
f32_t titan_fast_sqrt(f32_t val);
f32_t titan_fast_inv_sqrt(f32_t val);

/* Vector3 Algebra */
void  titan_vec3_init(titan_vec3_t *v, f32_t x, f32_t y, f32_t z);
void  titan_vec3_add(const titan_vec3_t *a, const titan_vec3_t *b, titan_vec3_t *out);
void  titan_vec3_sub(const titan_vec3_t *a, const titan_vec3_t *b, titan_vec3_t *out);
void  titan_vec3_scale(const titan_vec3_t *v, f32_t scalar, titan_vec3_t *out);
f32_t titan_vec3_dot(const titan_vec3_t *a, const titan_vec3_t *b);
void  titan_vec3_cross(const titan_vec3_t *a, const titan_vec3_t *b, titan_vec3_t *out);
f32_t titan_vec3_norm(const titan_vec3_t *v);
void  titan_vec3_normalize(titan_vec3_t *v);

/* Quaternion Operations */
void  titan_quat_identity(titan_quat_t *q);
void  titan_quat_from_euler(titan_quat_t *q, const titan_euler_t *euler);
void  titan_quat_to_euler(const titan_quat_t *q, titan_euler_t *euler);
void  titan_quat_multiply(const titan_quat_t *a, const titan_quat_t *b, titan_quat_t *out);
void  titan_quat_normalize(titan_quat_t *q);
void  titan_quat_rotate_vec3(const titan_quat_t *q, const titan_vec3_t *v, titan_vec3_t *out);

/* Q15 / Q31 DSP Arithmetic */
q15_t titan_q15_add(q15_t a, q15_t b);
q15_t titan_q15_sub(q15_t a, q15_t b);
q15_t titan_q15_mul(q15_t a, q15_t b);
q31_t titan_q31_mul(q31_t a, q31_t b);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_MATH_H */
