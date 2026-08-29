/**
 * @file titan_types.h
 * @brief Core Fixed-Width Types, Platform Primitives, and Architectural Aliases
 * @version 2.4.0
 * @date 2026-08-29
 *
 * Designed for strict MISRA-C compliance and high-reliability embedded platforms.
 * Provides deterministic type definitions across 32-bit and 64-bit microcontroller cores.
 */

#ifndef TITAN_TYPES_H
#define TITAN_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/* Unsigned integer types */
typedef uint8_t             u8_t;
typedef uint16_t            u16_t;
typedef uint32_t            u32_t;
typedef uint64_t            u64_t;

/* Signed integer types */
typedef int8_t              s8_t;
typedef int16_t             s16_t;
typedef int32_t             s32_t;
typedef int64_t             s64_t;

/* Floating point types */
typedef float               f32_t;
typedef double              f64_t;

/* Fixed-point fractional types (Q-format) */
typedef int16_t             q15_t;  /**< 1 sign bit, 15 fractional bits (-1.0 to +0.999969) */
typedef int32_t             q31_t;  /**< 1 sign bit, 31 fractional bits */

/* Boolean type */
typedef bool                bool_t;

#ifndef TRUE
#define TRUE                ((bool_t)true)
#endif

#ifndef FALSE
#define FALSE               ((bool_t)false)
#endif

#ifndef NULL_PTR
#define NULL_PTR            ((void *)0)
#endif

/* Memory addressing and sizes */
typedef uintptr_t           mem_addr_t;
typedef size_t              mem_size_t;
typedef uint32_t            reg_val_t;

/* Hardware register qualifiers */
#define __IO                volatile
#define __I                 volatile const
#define __O                 volatile

/* Function attribute macros */
#if defined(__GNUC__) || defined(__clang__)
    #define TITAN_INLINE            inline __attribute__((always_inline))
    #define TITAN_NOINLINE          __attribute__((noinline))
    #define TITAN_PACKED            __attribute__((packed))
    #define TITAN_ALIGNED(n)        __attribute__((aligned(n)))
    #define TITAN_WEAK              __attribute__((weak))
    #define TITAN_SECTION(s)        __attribute__((section(s)))
    #define TITAN_UNUSED            __attribute__((unused))
    #define TITAN_RAMFUNC           __attribute__((section(".ramfunc"), noinline))
#elif defined(_MSC_VER)
    #define TITAN_INLINE            __forceinline
    #define TITAN_NOINLINE          __declspec(noinline)
    #define TITAN_PACKED
    #define TITAN_ALIGNED(n)        __declspec(align(n))
    #define TITAN_WEAK
    #define TITAN_SECTION(s)
    #define TITAN_UNUSED
    #define TITAN_RAMFUNC
#else
    #define TITAN_INLINE            inline
    #define TITAN_NOINLINE
    #define TITAN_PACKED
    #define TITAN_ALIGNED(n)
    #define TITAN_WEAK
    #define TITAN_SECTION(s)
    #define TITAN_UNUSED
    #define TITAN_RAMFUNC
#endif

/* System timestamp definition in microseconds */
typedef uint64_t titan_time_us_t;
typedef uint32_t titan_time_ms_t;

#ifdef __cplusplus
}
#endif

#endif /* TITAN_TYPES_H */
