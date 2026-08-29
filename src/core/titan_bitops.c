/**
 * @file titan_bitops.c
 * @brief Hardware Bit Manipulation and Endian Conversion Routines
 */

#include "titan_bitops.h"

u32_t titan_clz(u32_t val)
{
    if (val == 0) return 32;
    u32_t n = 0;
    if ((val & 0xFFFF0000) == 0) { n += 16; val <<= 16; }
    if ((val & 0xFF000000) == 0) { n += 8;  val <<= 8; }
    if ((val & 0xF0000000) == 0) { n += 4;  val <<= 4; }
    if ((val & 0xC0000000) == 0) { n += 2;  val <<= 2; }
    if ((val & 0x80000000) == 0) { n += 1; }
    return n;
}

u32_t titan_ctz(u32_t val)
{
    if (val == 0) return 32;
    u32_t n = 0;
    if ((val & 0x0000FFFF) == 0) { n += 16; val >>= 16; }
    if ((val & 0x000000FF) == 0) { n += 8;  val >>= 8; }
    if ((val & 0x0000000F) == 0) { n += 4;  val >>= 4; }
    if ((val & 0x00000003) == 0) { n += 2;  val >>= 2; }
    if ((val & 0x00000001) == 0) { n += 1; }
    return n;
}

u32_t titan_popcount(u32_t val)
{
    val = val - ((val >> 1) & 0x55555555);
    val = (val & 0x33333333) + ((val >> 2) & 0x33333333);
    val = (val + (val >> 4)) & 0x0F0F0F0F;
    return (val * 0x01010101) >> 24;
}

u32_t titan_bit_reverse32(u32_t val)
{
    val = (((val & 0xaaaaaaaa) >> 1) | ((val & 0x55555555) << 1));
    val = (((val & 0xcccccccc) >> 2) | ((val & 0x33333333) << 2));
    val = (((val & 0xf0f0f0f0) >> 4) | ((val & 0x0f0f0f0f) << 4));
    val = (((val & 0xff00ff00) >> 8) | ((val & 0x00ff00ff) << 8));
    return ((val >> 16) | (val << 16));
}

u16_t titan_bit_reverse16(u16_t val)
{
    return (u16_t)(titan_bit_reverse32(val) >> 16);
}

u8_t titan_bit_reverse8(u8_t val)
{
    return (u8_t)(titan_bit_reverse32(val) >> 24);
}

u16_t titan_bswap16(u16_t val)
{
    return (u16_t)((val << 8) | (val >> 8));
}

u32_t titan_bswap32(u32_t val)
{
    return (((val & 0x000000FF) << 24) |
            ((val & 0x0000FF00) << 8)  |
            ((val & 0x00FF0000) >> 8)  |
            ((val & 0xFF000000) >> 24));
}

u64_t titan_bswap64(u64_t val)
{
    return (((u64_t)titan_bswap32((u32_t)(val & 0xFFFFFFFF))) << 32) |
           ((u64_t)titan_bswap32((u32_t)(val >> 32)));
}
