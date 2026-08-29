/**
 * @file titan_uds_routine_extended.c
 * @brief ISO 14229 Security Access Service 0x27 Implementation
 */
#include "protocols/titan_uds_routine_extended.h"
#include "core/titan_crc.h"
#include <string.h>

static titan_uds_security_state_t s_sec_state = TITAN_UDS_SEC_LOCKED;
static u32_t s_current_seed = 0x5A8E12F4;

titan_status_t titan_uds_sec_request_seed(u8_t *seed_out, mem_size_t *seed_len)
{
    if (!seed_out || !seed_len) return TITAN_ERROR_NULL_POINTER;
    s_current_seed = (s_current_seed * 1103515245U) + 12345U;
    seed_out[0] = (u8_t)(s_current_seed >> 24);
    seed_out[1] = (u8_t)(s_current_seed >> 16);
    seed_out[2] = (u8_t)(s_current_seed >> 8);
    seed_out[3] = (u8_t)(s_current_seed);
    *seed_len = 4;
    s_sec_state = TITAN_UDS_SEC_LEVEL_1_SEED_SENT;
    return TITAN_OK;
}

titan_status_t titan_uds_sec_verify_key(const u8_t *key_in, mem_size_t key_len)
{
    if (!key_in || key_len < 4) return TITAN_ERROR_INVALID_ARGUMENT;
    if (s_sec_state != TITAN_UDS_SEC_LEVEL_1_SEED_SENT) return TITAN_ERROR_PERMISSION_DENIED;

    u32_t expected_key = (s_current_seed ^ 0xA5A55A5A) + 0x1337;
    u32_t received_key = ((u32_t)key_in[0] << 24) | ((u32_t)key_in[1] << 16) | ((u32_t)key_in[2] << 8) | (u32_t)key_in[3];

    if (received_key == expected_key) {
        s_sec_state = TITAN_UDS_SEC_UNLOCKED;
        return TITAN_OK;
    }
    s_sec_state = TITAN_UDS_SEC_LOCKED;
    return TITAN_ERROR_AUTH_FAILED;
}

bool_t titan_uds_is_unlocked(void)
{
    return (s_sec_state == TITAN_UDS_SEC_UNLOCKED);
}
