/**
 * @file titan_fault_manager.c
 * @brief Real-Time Fault Assertion and Fail-Safe Transition
 */

#include "safety/titan_fault_manager.h"
#include <string.h>

titan_status_t titan_fault_init(titan_fault_mgr_t *mgr)
{
    if (!mgr) return TITAN_ERROR_NULL_POINTER;
    memset(mgr, 0, sizeof(titan_fault_mgr_t));
    return TITAN_OK;
}

titan_status_t titan_fault_raise(titan_fault_mgr_t *mgr, u32_t code, titan_fault_severity_t sev)
{
    if (!mgr) return TITAN_ERROR_NULL_POINTER;

    /* Check if already present */
    for (u32_t i = 0; i < mgr->fault_count; ++i) {
        if (mgr->records[i].fault_code == code) {
            mgr->records[i].occurrence_count++;
            mgr->records[i].is_active = TRUE;
            if (sev == TITAN_SEVERITY_CRITICAL_FAILSAFE) {
                mgr->failsafe_latched = TRUE;
            }
            return TITAN_OK;
        }
    }

    if (mgr->fault_count >= TITAN_MAX_FAULTS) {
        return TITAN_ERROR_BUFFER_FULL;
    }

    titan_fault_record_t *r = &mgr->records[mgr->fault_count++];
    r->fault_code = code;
    r->severity = sev;
    r->timestamp_us = 0;
    r->occurrence_count = 1;
    r->is_active = TRUE;

    if (sev == TITAN_SEVERITY_CRITICAL_FAILSAFE) {
        mgr->failsafe_latched = TRUE;
    }

    return TITAN_OK;
}

titan_status_t titan_fault_clear(titan_fault_mgr_t *mgr, u32_t code)
{
    if (!mgr) return TITAN_ERROR_NULL_POINTER;
    for (u32_t i = 0; i < mgr->fault_count; ++i) {
        if (mgr->records[i].fault_code == code) {
            mgr->records[i].is_active = FALSE;
            return TITAN_OK;
        }
    }
    return TITAN_ERROR_INVALID_ARGUMENT;
}

bool_t titan_fault_is_failsafe_active(const titan_fault_mgr_t *mgr)
{
    if (!mgr) return FALSE;
    return mgr->failsafe_latched;
}
