/**
 * @file titan_uds_server.c
 * @brief Diagnostic Session Management, Seed-Key Security & Negative Response Codes (NRC)
 */

#include "protocols/titan_uds_server.h"
#include <string.h>

#define TITAN_UDS_NRC_SUBFUNCTION_NOT_SUPPORTED 0x12
#define TITAN_UDS_NRC_INCORRECT_MESSAGE_LENGTH   0x13
#define TITAN_UDS_NRC_SECURITY_ACCESS_DENIED    0x33
#define TITAN_UDS_NRC_SERVICE_NOT_SUPPORTED     0x11

titan_status_t titan_uds_server_init(titan_uds_server_t *srv)
{
    if (!srv) return TITAN_ERROR_NULL_POINTER;
    srv->active_session = TITAN_UDS_SESSION_DEFAULT;
    srv->security_unlocked = FALSE;
    srv->security_seed = 0xA5A55A5AUL;
    srv->session_timeout_ticks = 5000;
    return TITAN_OK;
}

titan_status_t titan_uds_process_request(titan_uds_server_t *srv, const u8_t *req, mem_size_t req_len, u8_t *resp, mem_size_t *resp_len)
{
    if (!srv || !req || !resp || !resp_len || req_len == 0) {
        return TITAN_ERROR_INVALID_ARGUMENT;
    }

    u8_t sid = req[0];

    switch (sid) {
        case TITAN_UDS_SID_DIAGNOSTIC_SESSION_CONTROL: {
            if (req_len < 2) {
                resp[0] = 0x7F; resp[1] = sid; resp[2] = TITAN_UDS_NRC_INCORRECT_MESSAGE_LENGTH;
                *resp_len = 3;
                break;
            }
            srv->active_session = (titan_uds_session_t)req[1];
            resp[0] = sid + 0x40; /* Positive response */
            resp[1] = req[1];
            resp[2] = 0x00; resp[3] = 0x32; /* P2 server timing */
            resp[4] = 0x01; resp[5] = 0xF4; /* P2* server timing */
            *resp_len = 6;
            break;
        }
        case TITAN_UDS_SID_TESTER_PRESENT: {
            resp[0] = sid + 0x40;
            resp[1] = (req_len > 1) ? req[1] : 0x00;
            *resp_len = 2;
            break;
        }
        default:
            resp[0] = 0x7F;
            resp[1] = sid;
            resp[2] = TITAN_UDS_NRC_SERVICE_NOT_SUPPORTED;
            *resp_len = 3;
            break;
    }

    return TITAN_OK;
}
