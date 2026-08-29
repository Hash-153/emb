/**
 * @file titan_bitops.h
 * @brief Bitfield Manipulations, Bit-Reverse, Parity, and Endian Swapping
 */

#ifndef TITAN_BITOPS_H
#define TITAN_BITOPS_H

#include "titan_types.h"

#ifdef __cplusplus
extern "C" {
#endif

u32_t titan_clz(u32_t val);
u32_t titan_ctz(u32_t val);
u32_t titan_popcount(u32_t val);
u32_t titan_bit_reverse32(u32_t val);
u16_t titan_bit_reverse16(u16_t val);
u8_t  titan_bit_reverse8(u8_t val);

u16_t titan_bswap16(u16_t val);
u32_t titan_bswap32(u32_t val);
u64_t titan_bswap64(u64_t val);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_BITOPS_H */
