/**
 * @file titan_nvram_kv.h
 * @brief Fault-Tolerant Journaled Key-Value Non-Volatile Memory Store
 * @version 2.4.0
 * @date 2026-08-29
 */

#ifndef TITAN_NVRAM_KV_H
#define TITAN_NVRAM_KV_H

#include "core/titan_types.h"
#include "core/titan_status.h"
#include "drivers/titan_drv_nor_flash.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TITAN_KV_MAX_KEY_LEN   32
#define TITAN_KV_MAX_VAL_LEN   64
#define TITAN_KV_MAGIC         0x544E564B /* 'TNVK' */

typedef struct {
    u32_t magic;
    char  key[TITAN_KV_MAX_KEY_LEN];
    u32_t val_len;
    u8_t  val[TITAN_KV_MAX_VAL_LEN];
    u32_t crc32;
    u8_t  is_deleted;
    u8_t  padding[3];
} TITAN_PACKED titan_kv_record_t;

typedef struct {
    titan_drv_nor_flash_t *flash;
    u32_t                  base_addr;
    u32_t                  sector_count;
    u32_t                  active_offset;
} titan_nvram_kv_t;

titan_status_t titan_kv_init(titan_nvram_kv_t *kv, titan_drv_nor_flash_t *flash, u32_t base_addr, u32_t sectors);
titan_status_t titan_kv_set(titan_nvram_kv_t *kv, const char *key, const void *val, mem_size_t len);
titan_status_t titan_kv_get(titan_nvram_kv_t *kv, const char *key, void *val_buf, mem_size_t buf_max, mem_size_t *actual_len);
titan_status_t titan_kv_delete(titan_nvram_kv_t *kv, const char *key);
titan_status_t titan_kv_format(titan_nvram_kv_t *kv);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_NVRAM_KV_H */
