/**
 * @file titan_uds_server.h
 * @brief ISO 14229-1 Unified Diagnostic Services (UDS) Server Engine
 */

#ifndef TITAN_UDS_SERVER_H
#define TITAN_UDS_SERVER_H

#include "core/titan_types.h"
#include "core/titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    TITAN_UDS_SID_DIAGNOSTIC_SESSION_CONTROL = 0x10,
    TITAN_UDS_SID_ECU_RESET                  = 0x11,
    TITAN_UDS_SID_CLEAR_DIAGNOSTIC_INFO      = 0x14,
    TITAN_UDS_SID_READ_DTC_INFORMATION       = 0x19,
    TITAN_UDS_SID_READ_DATA_BY_IDENTIFIER    = 0x22,
    TITAN_UDS_SID_SECURITY_ACCESS            = 0x27,
    TITAN_UDS_SID_WRITE_DATA_BY_IDENTIFIER   = 0x2E,
    TITAN_UDS_SID_ROUTINE_CONTROL            = 0x31,
    TITAN_UDS_SID_TESTER_PRESENT             = 0x3E
} titan_uds_sid_t;

typedef enum {
    TITAN_UDS_SESSION_DEFAULT     = 0x01,
    TITAN_UDS_SESSION_PROGRAMMING = 0x02,
    TITAN_UDS_SESSION_EXTENDED    = 0x03,
    TITAN_UDS_SESSION_SAFETY      = 0x04
} titan_uds_session_t;

typedef struct {
    titan_uds_session_t active_session;
    bool_t              security_unlocked;
    u32_t               security_seed;
    u32_t               session_timeout_ticks;
} titan_uds_server_t;

titan_status_t titan_uds_server_init(titan_uds_server_t *srv);
titan_status_t titan_uds_process_request(titan_uds_server_t *srv, const u8_t *req, mem_size_t req_len, u8_t *resp, mem_size_t *resp_len);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_UDS_SERVER_H */
