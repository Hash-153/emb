/**
 * @file titan_app_supervisor.h
 * @brief Master Supervisory Lifecycle State Machine
 * @version 2.4.0
 * @date 2026-08-29
 */

#ifndef TITAN_APP_SUPERVISOR_H
#define TITAN_APP_SUPERVISOR_H

#include "core/titan_types.h"
#include "core/titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    TITAN_SYS_STATE_BOOT = 0,
    TITAN_SYS_STATE_POST_SELFTEST,
    TITAN_SYS_STATE_STANDBY,
    TITAN_SYS_STATE_ARMING,
    TITAN_SYS_STATE_ACTIVE_RUN,
    TITAN_SYS_STATE_DEGRADED,
    TITAN_SYS_STATE_EMERGENCY_SAFE,
    TITAN_SYS_STATE_MAINTENANCE
} titan_sys_state_t;

typedef struct {
    titan_sys_state_t current_state;
    titan_sys_state_t previous_state;
    u32_t             state_entry_tick;
    bool_t            armed;
    bool_t            post_passed;
} titan_supervisor_t;

titan_status_t titan_supervisor_init(titan_supervisor_t *sup);
titan_status_t titan_supervisor_step(titan_supervisor_t *sup);
titan_status_t titan_supervisor_arm(titan_supervisor_t *sup);
titan_status_t titan_supervisor_disarm(titan_supervisor_t *sup);
titan_status_t titan_supervisor_trigger_emergency(titan_supervisor_t *sup);
const char*    titan_supervisor_state_name(titan_sys_state_t state);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_APP_SUPERVISOR_H */
