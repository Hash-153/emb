/**
 * @file titan_string.h
 * @brief Safe Embedded String Formatting, Hex Parsers, and Substring Utilities
 */

#ifndef TITAN_STRING_H
#define TITAN_STRING_H

#include "titan_types.h"
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

mem_size_t titan_strlen(const char *str);
mem_size_t titan_strlcpy(char *dst, const char *src, mem_size_t size);
mem_size_t titan_strlcat(char *dst, const char *src, mem_size_t size);
s32_t      titan_strcmp(const char *s1, const char *s2);
s32_t      titan_strncmp(const char *s1, const char *s2, mem_size_t n);

s32_t      titan_snprintf(char *buf, mem_size_t size, const char *fmt, ...);
s32_t      titan_vsnprintf(char *buf, mem_size_t size, const char *fmt, va_list args);

s32_t      titan_atoi(const char *str);
f32_t      titan_atof(const char *str);
u32_t      titan_hex_to_u32(const char *hex_str);
void       titan_u32_to_hex(u32_t val, char *dst, bool_t uppercase);
void       titan_bytes_to_hex(const u8_t *bytes, mem_size_t len, char *dst, mem_size_t dst_max);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_STRING_H */
