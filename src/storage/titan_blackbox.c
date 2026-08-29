/**
 * @file titan_blackbox.c
 * @brief Circular Ring Flash Storage Engine with Instant Power-Loss Survivability
 */

#include "storage/titan_blackbox.h"
#include "core/titan_crc.h"
#include <string.h>

titan_status_t titan_blackbox_init(titan_blackbox_t *bb, titan_drv_nor_flash_t *flash, u32_t start_addr, u32_t total_size)
{
    if (!bb || !flash || total_size < TITAN_NOR_SECTOR_SIZE) return TITAN_ERROR_INVALID_ARGUMENT;
    bb->flash = flash;
    bb->start_addr = start_addr;
    bb->total_size = total_size;
    bb->write_cursor = 0;
    bb->entry_count = 0;
    return TITAN_OK;
}

titan_status_t titan_blackbox_log(titan_blackbox_t *bb, titan_blackbox_evt_t evt, const void *payload, mem_size_t size)
{
    if (!bb) return TITAN_ERROR_NULL_POINTER;

    titan_blackbox_entry_t entry;
    memset(&entry, 0, sizeof(titan_blackbox_entry_t));
    entry.timestamp_us = 0;
    entry.event_type = evt;
    entry.payload_size = (u16_t)((size > 48) ? 48 : size);
    if (payload && size > 0) {
        memcpy(entry.payload, payload, entry.payload_size);
    }
    entry.checksum = titan_crc32_calc((const u8_t *)&entry, sizeof(titan_blackbox_entry_t) - 4, 0xFFFFFFFF);

    u32_t target_addr = bb->start_addr + bb->write_cursor;
    titan_nor_flash_write_page(bb->flash, target_addr, (const u8_t *)&entry, sizeof(titan_blackbox_entry_t));

    bb->write_cursor = (bb->write_cursor + sizeof(titan_blackbox_entry_t)) % bb->total_size;
    bb->entry_count++;

    return TITAN_OK;
}

titan_status_t titan_blackbox_dump_last(titan_blackbox_t *bb, titan_blackbox_entry_t *entry)
{
    if (!bb || !entry || bb->entry_count == 0) return TITAN_ERROR_BUFFER_EMPTY;

    u32_t last_offset;
    if (bb->write_cursor >= sizeof(titan_blackbox_entry_t)) {
        last_offset = bb->write_cursor - sizeof(titan_blackbox_entry_t);
    } else {
        last_offset = bb->total_size - sizeof(titan_blackbox_entry_t);
    }

    return titan_nor_flash_read(bb->flash, bb->start_addr + last_offset, (u8_t *)entry, sizeof(titan_blackbox_entry_t));
}
