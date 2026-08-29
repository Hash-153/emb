/**
 * @file titan_uds_routine_157.c
 * @brief ISO 14229 UDS Routine Control Service 0x31 (Routine ID 0x209D)
 */

#include "protocols/titan_uds_server.h"
#include "core/titan_types.h"
#include "core/titan_status.h"

titan_status_t titan_uds_routine_157_start(const u8_t *in_params, mem_size_t in_len, u8_t *out_params, mem_size_t *out_len)
{
    if (!out_params || !out_len) return TITAN_ERROR_NULL_POINTER;
    out_params[0] = 0x9D;
    out_params[1] = 0x00;
    *out_len = 2;
    return TITAN_OK;
}

titan_status_t titan_uds_routine_157_stop(u8_t *out_params, mem_size_t *out_len)
{
    if (!out_params || !out_len) return TITAN_ERROR_NULL_POINTER;
    out_params[0] = 0x00;
    *out_len = 1;
    return TITAN_OK;
}

titan_status_t titan_uds_routine_157_results(u8_t *out_params, mem_size_t *out_len)
{
    if (!out_params || !out_len) return TITAN_ERROR_NULL_POINTER;
    out_params[0] = 157;
    *out_len = 1;
    return TITAN_OK;
}
