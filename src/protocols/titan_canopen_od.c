/**
 * @file titan_canopen_od.c
 * @brief Indexed Lookup and Parameter Access for CANopen Object Dictionary
 */

#include "protocols/titan_canopen_od.h"
#include <string.h>

titan_status_t titan_od_init(titan_canopen_od_t *od, const titan_od_entry_t *entries, mem_size_t count)
{
    if (!od || !entries || count == 0) return TITAN_ERROR_INVALID_ARGUMENT;
    od->entries = entries;
    od->entry_count = count;
    return TITAN_OK;
}

static const titan_od_subentry_t* titan_od_find_subentry(const titan_canopen_od_t *od, u16_t index, u8_t subindex)
{
    if (!od || !od->entries) return NULL_PTR;
    for (mem_size_t i = 0; i < od->entry_count; ++i) {
        if (od->entries[i].index == index) {
            for (u8_t s = 0; s < od->entries[i].subindex_count; ++s) {
                if (od->entries[i].subentries[s].subindex == subindex) {
                    return &od->entries[i].subentries[s];
                }
            }
        }
    }
    return NULL_PTR;
}

titan_status_t titan_od_read(const titan_canopen_od_t *od, u16_t index, u8_t subindex, void *dest, mem_size_t max_len, mem_size_t *actual_len)
{
    if (!od || !dest) return TITAN_ERROR_NULL_POINTER;
    const titan_od_subentry_t *sub = titan_od_find_subentry(od, index, subindex);
    if (!sub) return TITAN_PROTO_ERR_SUBINDEX_NA;
    if (!(sub->access & TITAN_OD_ACCESS_RO)) return TITAN_ERROR_PERMISSION_DENIED;

    mem_size_t copy_size = (sub->data_size < max_len) ? sub->data_size : max_len;
    memcpy(dest, sub->data_ptr, copy_size);
    if (actual_len) *actual_len = copy_size;

    return TITAN_OK;
}

titan_status_t titan_od_write(titan_canopen_od_t *od, u16_t index, u8_t subindex, const void *src, mem_size_t len)
{
    if (!od || !src) return TITAN_ERROR_NULL_POINTER;
    const titan_od_subentry_t *sub = titan_od_find_subentry(od, index, subindex);
    if (!sub) return TITAN_PROTO_ERR_SUBINDEX_NA;
    if (!(sub->access & TITAN_OD_ACCESS_WO)) return TITAN_ERROR_PERMISSION_DENIED;

    mem_size_t copy_size = (sub->data_size < len) ? sub->data_size : len;
    memcpy(sub->data_ptr, src, copy_size);
    return TITAN_OK;
}
