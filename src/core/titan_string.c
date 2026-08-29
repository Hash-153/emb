/**
 * @file titan_string.c
 * @brief Bounded String Routines and Formatting Engine
 */

#include "titan_string.h"
#include <stdio.h>
#include <ctype.h>

mem_size_t titan_strlen(const char *str)
{
    if (!str) return 0;
    const char *s = str;
    while (*s) s++;
    return (mem_size_t)(s - str);
}

mem_size_t titan_strlcpy(char *dst, const char *src, mem_size_t size)
{
    if (!dst || !src || size == 0) return 0;
    mem_size_t src_len = titan_strlen(src);
    if (src_len + 1 < size) {
        memcpy(dst, src, src_len + 1);
    } else {
        memcpy(dst, src, size - 1);
        dst[size - 1] = '\0';
    }
    return src_len;
}

mem_size_t titan_strlcat(char *dst, const char *src, mem_size_t size)
{
    if (!dst || !src || size == 0) return 0;
    mem_size_t dst_len = titan_strlen(dst);
    mem_size_t src_len = titan_strlen(src);

    if (dst_len >= size) return size + src_len;

    mem_size_t copy_len = size - dst_len - 1;
    if (src_len < copy_len) {
        copy_len = src_len;
    }

    memcpy(dst + dst_len, src, copy_len);
    dst[dst_len + copy_len] = '\0';
    return dst_len + src_len;
}

s32_t titan_strcmp(const char *s1, const char *s2)
{
    if (!s1 && !s2) return 0;
    if (!s1) return -1;
    if (!s2) return 1;
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return (s32_t)(*(const unsigned char *)s1 - *(const unsigned char *)s2);
}

s32_t titan_strncmp(const char *s1, const char *s2, mem_size_t n)
{
    if (n == 0) return 0;
    if (!s1 && !s2) return 0;
    if (!s1) return -1;
    if (!s2) return 1;
    while (--n && *s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return (s32_t)(*(const unsigned char *)s1 - *(const unsigned char *)s2);
}

s32_t titan_vsnprintf(char *buf, mem_size_t size, const char *fmt, va_list args)
{
    if (!buf || size == 0 || !fmt) return -1;
    return vsnprintf(buf, size, fmt, args);
}

s32_t titan_snprintf(char *buf, mem_size_t size, const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    s32_t ret = titan_vsnprintf(buf, size, fmt, args);
    va_end(args);
    return ret;
}

s32_t titan_atoi(const char *str)
{
    if (!str) return 0;
    s32_t res = 0;
    s32_t sign = 1;
    while (isspace((unsigned char)*str)) str++;
    if (*str == '-') { sign = -1; str++; }
    else if (*str == '+') { str++; }
    while (isdigit((unsigned char)*str)) {
        res = res * 10 + (*str - '0');
        str++;
    }
    return res * sign;
}

f32_t titan_atof(const char *str)
{
    if (!str) return 0.0f;
    f32_t res = 0.0f;
    f32_t sign = 1.0f;
    f32_t factor = 1.0f;
    bool_t in_decimal = FALSE;

    while (isspace((unsigned char)*str)) str++;
    if (*str == '-') { sign = -1.0f; str++; }
    else if (*str == '+') { str++; }

    while (*str) {
        if (*str == '.') {
            in_decimal = TRUE;
        } else if (isdigit((unsigned char)*str)) {
            if (in_decimal) {
                factor *= 0.1f;
                res += (*str - '0') * factor;
            } else {
                res = res * 10.0f + (*str - '0');
            }
        } else {
            break;
        }
        str++;
    }
    return res * sign;
}

u32_t titan_hex_to_u32(const char *hex_str)
{
    if (!hex_str) return 0;
    u32_t val = 0;
    if (hex_str[0] == '0' && (hex_str[1] == 'x' || hex_str[1] == 'X')) {
        hex_str += 2;
    }
    while (*hex_str) {
        char c = *hex_str++;
        u32_t d;
        if (c >= '0' && c <= '9') d = c - '0';
        else if (c >= 'a' && c <= 'f') d = c - 'a' + 10;
        else if (c >= 'A' && c <= 'F') d = c - 'A' + 10;
        else break;
        val = (val << 4) | d;
    }
    return val;
}

void titan_u32_to_hex(u32_t val, char *dst, bool_t uppercase)
{
    if (!dst) return;
    const char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
    for (int i = 7; i >= 0; --i) {
        dst[7 - i] = digits[(val >> (i * 4)) & 0x0F];
    }
    dst[8] = '\0';
}

void titan_bytes_to_hex(const u8_t *bytes, mem_size_t len, char *dst, mem_size_t dst_max)
{
    if (!bytes || !dst || dst_max == 0) return;
    const char hex_chars[] = "0123456789ABCDEF";
    mem_size_t out_idx = 0;
    for (mem_size_t i = 0; i < len && (out_idx + 3) <= dst_max; ++i) {
        dst[out_idx++] = hex_chars[(bytes[i] >> 4) & 0x0F];
        dst[out_idx++] = hex_chars[bytes[i] & 0x0F];
        if (i + 1 < len && (out_idx + 1) < dst_max) {
            dst[out_idx++] = ' ';
        }
    }
    dst[out_idx] = '\0';
}
