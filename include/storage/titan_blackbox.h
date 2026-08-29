/**
 * @file titan_blackbox.h
 * @brief High-Speed Circular Blackbox Flight Data & Crash Recorder
 */

#ifndef TITAN_BLACKBOX_H
#define TITAN_BLACKBOX_H

#include "core/titan_types.h"
#include "core/titan_status.h"
#include "drivers/titan_drv_nor_flash.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    TITAN_BB_EVT_BOOT = 0,
    TITAN_BB_EVT_STATE_CHANGE,
    TITAN_BB_EVT_FAULT_TRIP,
    TITAN_BB_EVT_CRITICAL_TELEMETRY,
    TITAN_BB_EVT_SHUTDOWN
} titan_blackbox_evt_t;

typedef struct {
    u64_t                timestamp_us;
    titan_blackbox_evt_t event_type;
    u16_t                payload_size;
    u8_t                 payload[48];
    u32_t                checksum;
} TITAN_PACKED titan_blackbox_entry_t;

typedef struct {
    titan_drv_nor_flash_t *flash;
    u32_t                  start_addr;
    u32_t                  total_size;
    u32_t                  write_cursor;
    u32_t                  entry_count;
} titan_blackbox_t;

titan_status_t titan_blackbox_init(titan_blackbox_t *bb, titan_drv_nor_flash_t *flash, u32_t start_addr, u32_t total_size);
titan_status_t titan_blackbox_log(titan_blackbox_t *bb, titan_blackbox_evt_t evt, const void *payload, mem_size_t size);
titan_status_t titan_blackbox_dump_last(titan_blackbox_t *bb, titan_blackbox_entry_t *entry);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_BLACKBOX_H */
