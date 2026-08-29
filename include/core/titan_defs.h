/**
 * @file titan_defs.h
 * @brief Common Macro Utilities, Bit Manipulations, Clamping, and Min/Max Bounds
 */

#ifndef TITAN_DEFS_H
#define TITAN_DEFS_H

#include "titan_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TITAN_MIN(a, b)             (((a) < (b)) ? (a) : (b))
#define TITAN_MAX(a, b)             (((a) > (b)) ? (a) : (b))
#define TITAN_CLAMP(x, low, high)   (((x) < (low)) ? (low) : (((x) > (high)) ? (high) : (x)))
#define TITAN_ABS(a)                (((a) < 0) ? -(a) : (a))

#define TITAN_BIT(pos)              (1UL << (pos))
#define TITAN_SET_BIT(reg, bit)     ((reg) |= (bit))
#define TITAN_CLEAR_BIT(reg, bit)   ((reg) &= ~(bit))
#define TITAN_READ_BIT(reg, bit)    ((reg) & (bit))
#define TITAN_TOGGLE_BIT(reg, bit)  ((reg) ^= (bit))

#define TITAN_ARRAY_SIZE(arr)       (sizeof(arr) / sizeof((arr)[0]))
#define TITAN_CONTAINER_OF(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define TITAN_ROUND_UP(x, align)    (((x) + (align) - 1UL) & ~((align) - 1UL))
#define TITAN_ROUND_DOWN(x, align)  ((x) & ~((align) - 1UL))

#define TITAN_UNUSED_PARAM(x)       ((void)(x))

#define TITAN_ASSERT(cond) do { \
    if (!(cond)) { \
        titan_panic_handler(__FILE__, __LINE__, #cond); \
    } \
} while(0)

void titan_panic_handler(const char *file, u32_t line, const char *expr);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_DEFS_H */
