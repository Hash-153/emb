/**
 * @file titan_wear_leveling_fs.h
 * @brief Power-Fail Safe Log-Structured Flash Wear-Leveling File System (WLFS)
 */

#ifndef TITAN_WEAR_LEVELING_FS_H
#define TITAN_WEAR_LEVELING_FS_H

#include "core/titan_types.h"
#include "core/titan_status.h"
#include "drivers/titan_drv_nor_flash.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TITAN_WLFS_BLOCK_MAGIC 0x574C4653 /* 'WLFS' */

typedef struct {
    u32_t magic;
    u32_t erase_count;
    u32_t valid_bytes;
    u32_t block_state;
    u32_t checksum;
} titan_wlfs_block_hdr_t;

typedef struct {
    titan_drv_nor_flash_t *flash;
    u32_t                  base_addr;
    u32_t                  total_blocks;
    u32_t                  block_size;
    u32_t                  active_write_block;
    u32_t                  min_erase_count;
    u32_t                  max_erase_count;
} titan_wlfs_t;

titan_status_t titan_wlfs_mount(titan_wlfs_t *fs, titan_drv_nor_flash_t *flash, u32_t base_addr, u32_t blocks, u32_t block_size);
titan_status_t titan_wlfs_format(titan_wlfs_t *fs);
titan_status_t titan_wlfs_write(titan_wlfs_t *fs, u32_t file_id, const u8_t *data, mem_size_t len);
titan_status_t titan_wlfs_read(titan_wlfs_t *fs, u32_t file_id, u8_t *dest, mem_size_t max_len, mem_size_t *actual_len);
titan_status_t titan_wlfs_gc_collect(titan_wlfs_t *fs);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_WEAR_LEVELING_FS_H */
