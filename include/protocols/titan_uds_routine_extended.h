/**
 * @file titan_uds_routine_extended.h
 * @brief ISO 14229 UDS Routine Control Extended Services (Flash Reprogramming Session)
 */
#ifndef TITAN_UDS_ROUTINE_EXTENDED_H
#define TITAN_UDS_ROUTINE_EXTENDED_H

#include "core/titan_types.h"
#include "core/titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    TITAN_UDS_SEC_LOCKED = 0,
    TITAN_UDS_SEC_LEVEL_1_SEED_SENT,
    TITAN_UDS_SEC_UNLOCKED
} titan_uds_security_state_t;

titan_status_t titan_uds_sec_request_seed(u8_t *seed_out, mem_size_t *seed_len);
titan_status_t titan_uds_sec_verify_key(const u8_t *key_in, mem_size_t key_len);
bool_t         titan_uds_is_unlocked(void);

#ifdef __cplusplus
}
#endif
#endif
