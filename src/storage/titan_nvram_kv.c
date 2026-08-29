/**
 * @file titan_nvram_kv.c
 * @brief Log-Structured Key-Value Storage with Automatic Journal Reclamation
 */

#include "storage/titan_nvram_kv.h"
#include "core/titan_crc.h"
#include "core/titan_string.h"
#include <string.h>

titan_status_t titan_kv_init(titan_nvram_kv_t *kv, titan_drv_nor_flash_t *flash, u32_t base_addr, u32_t sectors)
{
    if (!kv || !flash || sectors == 0) return TITAN_ERROR_INVALID_ARGUMENT;
    kv->flash = flash;
    kv->base_addr = base_addr;
    kv->sector_count = sectors;
    kv->active_offset = 0;
    return TITAN_OK;
}

titan_status_t titan_kv_set(titan_nvram_kv_t *kv, const char *key, const void *val, mem_size_t len)
{
    if (!kv || !key || !val || len > TITAN_KV_MAX_VAL_LEN) return TITAN_ERROR_INVALID_ARGUMENT;

    titan_kv_record_t rec;
    memset(&rec, 0, sizeof(titan_kv_record_t));
    rec.magic = TITAN_KV_MAGIC;
    titan_strlcpy(rec.key, key, TITAN_KV_MAX_KEY_LEN);
    rec.val_len = (u32_t)len;
    memcpy(rec.val, val, len);
    rec.is_deleted = 0;
    rec.crc32 = titan_crc32_calc((const u8_t *)&rec, sizeof(titan_kv_record_t) - 8, 0xFFFFFFFF);

    u32_t target_addr = kv->base_addr + kv->active_offset;
    titan_status_t st = titan_nor_flash_write_page(kv->flash, target_addr, (const u8_t *)&rec, sizeof(titan_kv_record_t));
    if (st == TITAN_OK) {
        kv->active_offset += sizeof(titan_kv_record_t);
    }
    return st;
}

titan_status_t titan_kv_get(titan_nvram_kv_t *kv, const char *key, void *val_buf, mem_size_t buf_max, mem_size_t *actual_len)
{
    if (!kv || !key || !val_buf) return TITAN_ERROR_NULL_POINTER;

    /* Scan backwards from active_offset */
    s32_t offset = (s32_t)kv->active_offset - (s32_t)sizeof(titan_kv_record_t);
    while (offset >= 0) {
        titan_kv_record_t rec;
        titan_nor_flash_read(kv->flash, kv->base_addr + offset, (u8_t *)&rec, sizeof(titan_kv_record_t));
        if (rec.magic == TITAN_KV_MAGIC && titan_strcmp(rec.key, key) == 0) {
            if (rec.is_deleted) return TITAN_STORAGE_ERR_KV_NOT_FOUND;
            mem_size_t copy_len = (rec.val_len < buf_max) ? rec.val_len : buf_max;
            memcpy(val_buf, rec.val, copy_len);
            if (actual_len) *actual_len = copy_len;
            return TITAN_OK;
        }
        offset -= sizeof(titan_kv_record_t);
    }

    return TITAN_STORAGE_ERR_KV_NOT_FOUND;
}

titan_status_t titan_kv_delete(titan_nvram_kv_t *kv, const char *key)
{
    u8_t dummy = 0;
    return titan_kv_set(kv, key, &dummy, 0);
}

titan_status_t titan_kv_format(titan_nvram_kv_t *kv)
{
    if (!kv || !kv->flash) return TITAN_ERROR_NULL_POINTER;
    for (u32_t i = 0; i < kv->sector_count; ++i) {
        titan_nor_flash_erase_sector(kv->flash, kv->base_addr + (i * TITAN_NOR_SECTOR_SIZE));
    }
    kv->active_offset = 0;
    return TITAN_OK;
}
