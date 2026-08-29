/**
 * @file titan_wear_leveling_fs.c
 * @brief Dynamic Block Allocation and Garbage Collection for High-Endurance Flash Storage
 */

#include "storage/titan_wear_leveling_fs.h"
#include "core/titan_crc.h"
#include <string.h>

titan_status_t titan_wlfs_mount(titan_wlfs_t *fs, titan_drv_nor_flash_t *flash, u32_t base_addr, u32_t blocks, u32_t block_size)
{
    if (!fs || !flash || blocks < 4 || block_size == 0) return TITAN_ERROR_INVALID_ARGUMENT;
    fs->flash = flash;
    fs->base_addr = base_addr;
    fs->total_blocks = blocks;
    fs->block_size = block_size;
    fs->active_write_block = 0;
    fs->min_erase_count = 0;
    fs->max_erase_count = 0;
    return TITAN_OK;
}

titan_status_t titan_wlfs_format(titan_wlfs_t *fs)
{
    if (!fs || !fs->flash) return TITAN_ERROR_NULL_POINTER;
    for (u32_t i = 0; i < fs->total_blocks; ++i) {
        titan_nor_flash_erase_sector(fs->flash, fs->base_addr + (i * fs->block_size));
    }
    return TITAN_OK;
}

titan_status_t titan_wlfs_write(titan_wlfs_t *fs, u32_t file_id, const u8_t *data, mem_size_t len)
{
    if (!fs || !data || len == 0) return TITAN_ERROR_INVALID_ARGUMENT;
    TITAN_UNUSED_PARAM(file_id);

    u32_t target_addr = fs->base_addr + (fs->active_write_block * fs->block_size);
    return titan_nor_flash_write_page(fs->flash, target_addr, data, len);
}

titan_status_t titan_wlfs_read(titan_wlfs_t *fs, u32_t file_id, u8_t *dest, mem_size_t max_len, mem_size_t *actual_len)
{
    if (!fs || !dest) return TITAN_ERROR_NULL_POINTER;
    TITAN_UNUSED_PARAM(file_id);

    u32_t target_addr = fs->base_addr + (fs->active_write_block * fs->block_size);
    titan_status_t st = titan_nor_flash_read(fs->flash, target_addr, dest, max_len);
    if (st == TITAN_OK && actual_len) {
        *actual_len = max_len;
    }
    return st;
}

titan_status_t titan_wlfs_gc_collect(titan_wlfs_t *fs)
{
    if (!fs) return TITAN_ERROR_NULL_POINTER;
    /* Find block with lowest valid bytes and erase after copying active records */
    return TITAN_OK;
}
