/**
 * @file titan_canopen_od.h
 * @brief CANopen CiA 301 Standardized Object Dictionary Engine
 * @version 2.4.0
 * @date 2026-08-29
 */

#ifndef TITAN_CANOPEN_OD_H
#define TITAN_CANOPEN_OD_H

#include "core/titan_types.h"
#include "core/titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    TITAN_OD_ACCESS_RO = 0x01,  /**< Read-Only */
    TITAN_OD_ACCESS_WO = 0x02,  /**< Write-Only */
    TITAN_OD_ACCESS_RW = 0x03   /**< Read/Write */
} titan_od_access_t;

typedef enum {
    TITAN_OD_TYPE_U8,
    TITAN_OD_TYPE_U16,
    TITAN_OD_TYPE_U32,
    TITAN_OD_TYPE_S8,
    TITAN_OD_TYPE_S16,
    TITAN_OD_TYPE_S32,
    TITAN_OD_TYPE_F32,
    TITAN_OD_TYPE_STRING,
    TITAN_OD_TYPE_OCTETS
} titan_od_type_t;

typedef struct {
    u8_t              subindex;
    titan_od_type_t   data_type;
    titan_od_access_t access;
    void             *data_ptr;
    mem_size_t        data_size;
} titan_od_subentry_t;

typedef struct {
    u16_t                      index;
    u8_t                       subindex_count;
    const titan_od_subentry_t *subentries;
} titan_od_entry_t;

typedef struct {
    const titan_od_entry_t *entries;
    mem_size_t              entry_count;
} titan_canopen_od_t;

titan_status_t titan_od_init(titan_canopen_od_t *od, const titan_od_entry_t *entries, mem_size_t count);
titan_status_t titan_od_read(const titan_canopen_od_t *od, u16_t index, u8_t subindex, void *dest, mem_size_t max_len, mem_size_t *actual_len);
titan_status_t titan_od_write(titan_canopen_od_t *od, u16_t index, u8_t subindex, const void *src, mem_size_t len);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_CANOPEN_OD_H */
