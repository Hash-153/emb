/**
 * @file titan_app_supervisor.c
 * @brief State Machine Transitions, Safety Interlocks and Guard Conditions
 */

#include "app/titan_app_supervisor.h"
#include <string.h>

titan_status_t titan_supervisor_init(titan_supervisor_t *sup)
{
    if (!sup) return TITAN_ERROR_NULL_POINTER;
    memset(sup, 0, sizeof(titan_supervisor_t));
    sup->current_state = TITAN_SYS_STATE_BOOT;
    sup->previous_state = TITAN_SYS_STATE_BOOT;
    return TITAN_OK;
}

titan_status_t titan_supervisor_step(titan_supervisor_t *sup)
{
    if (!sup) return TITAN_ERROR_NULL_POINTER;

    switch (sup->current_state) {
        case TITAN_SYS_STATE_BOOT:
            sup->previous_state = sup->current_state;
            sup->current_state = TITAN_SYS_STATE_POST_SELFTEST;
            break;
        case TITAN_SYS_STATE_POST_SELFTEST:
            sup->post_passed = TRUE;
            sup->previous_state = sup->current_state;
            sup->current_state = TITAN_SYS_STATE_STANDBY;
            break;
        case TITAN_SYS_STATE_STANDBY:
            if (sup->armed) {
                sup->previous_state = sup->current_state;
                sup->current_state = TITAN_SYS_STATE_ARMING;
            }
            break;
        case TITAN_SYS_STATE_ARMING:
            sup->previous_state = sup->current_state;
            sup->current_state = TITAN_SYS_STATE_ACTIVE_RUN;
            break;
        case TITAN_SYS_STATE_ACTIVE_RUN:
            if (!sup->armed) {
                sup->previous_state = sup->current_state;
                sup->current_state = TITAN_SYS_STATE_STANDBY;
            }
            break;
        case TITAN_SYS_STATE_EMERGENCY_SAFE:
            /* Latch state until maintenance reset */
            break;
        default:
            break;
    }
    return TITAN_OK;
}

titan_status_t titan_supervisor_arm(titan_supervisor_t *sup)
{
    if (!sup || !sup->post_passed) return TITAN_ERROR_PERMISSION_DENIED;
    if (sup->current_state != TITAN_SYS_STATE_STANDBY) return TITAN_ERROR_INVALID_ARGUMENT;
    sup->armed = TRUE;
    return TITAN_OK;
}

titan_status_t titan_supervisor_disarm(titan_supervisor_t *sup)
{
    if (!sup) return TITAN_ERROR_NULL_POINTER;
    sup->armed = FALSE;
    return TITAN_OK;
}

titan_status_t titan_supervisor_trigger_emergency(titan_supervisor_t *sup)
{
    if (!sup) return TITAN_ERROR_NULL_POINTER;
    sup->previous_state = sup->current_state;
    sup->current_state = TITAN_SYS_STATE_EMERGENCY_SAFE;
    sup->armed = FALSE;
    return TITAN_OK;
}

const char* titan_supervisor_state_name(titan_sys_state_t state)
{
    switch (state) {
        case TITAN_SYS_STATE_BOOT:          return "BOOT";
        case TITAN_SYS_STATE_POST_SELFTEST: return "POST_SELFTEST";
        case TITAN_SYS_STATE_STANDBY:       return "STANDBY";
        case TITAN_SYS_STATE_ARMING:        return "ARMING";
        case TITAN_SYS_STATE_ACTIVE_RUN:    return "ACTIVE_RUN";
        case TITAN_SYS_STATE_DEGRADED:      return "DEGRADED";
        case TITAN_SYS_STATE_EMERGENCY_SAFE:return "EMERGENCY_SAFE";
        case TITAN_SYS_STATE_MAINTENANCE:   return "MAINTENANCE";
        default:                            return "UNKNOWN";
    }
}
