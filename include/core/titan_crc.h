/**
 * @file titan_crc.h
 * @brief High-Speed CRC8, CRC16 (CCITT/Modbus), CRC32 (IEEE 802.3), and Fletcher Checksums
 */

#ifndef TITAN_CRC_H
#define TITAN_CRC_H

#include "titan_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* CRC8 Engine (Polynomial: 0x07 / Dallas: 0x31) */
u8_t  titan_crc8_calc(const u8_t *data, mem_size_t len, u8_t init_val);
u8_t  titan_crc8_dallas(const u8_t *data, mem_size_t len);

/* CRC16 Engine (CCITT Poly: 0x1021, Modbus Poly: 0x8005) */
u16_t titan_crc16_ccitt(const u8_t *data, mem_size_t len, u16_t init_val);
u16_t titan_crc16_modbus(const u8_t *data, mem_size_t len);
u16_t titan_crc16_xmodem(const u8_t *data, mem_size_t len);

/* CRC32 Engine (IEEE 802.3 Poly: 0xEDB88320) */
u32_t titan_crc32_calc(const u8_t *data, mem_size_t len, u32_t init_val);
u32_t titan_crc32_step(u32_t current_crc, u8_t byte);

/* Fletcher 16 and Fletcher 32 */
u16_t titan_fletcher16(const u8_t *data, mem_size_t len);
u32_t titan_fletcher32(const u16_t *data, mem_size_t words);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_CRC_H */
