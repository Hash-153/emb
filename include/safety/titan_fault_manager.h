/**
 * @file titan_fault_manager.h
 * @brief System Fault Classification, Diagnostic Trouble Code (DTC) & Safe-State Latch
 */

#ifndef TITAN_FAULT_MANAGER_H
#define TITAN_FAULT_MANAGER_H

#include "core/titan_types.h"
#include "core/titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    TITAN_SEVERITY_INFO = 0,
    TITAN_SEVERITY_WARNING,
    TITAN_SEVERITY_ERROR,
    TITAN_SEVERITY_CRITICAL_FAILSAFE
} titan_fault_severity_t;

typedef struct {
    u32_t                  fault_code;
    titan_fault_severity_t severity;
    u64_t                  timestamp_us;
    u32_t                  occurrence_count;
    bool_t                 is_active;
} titan_fault_record_t;

#define TITAN_MAX_FAULTS 32

typedef struct {
    titan_fault_record_t records[TITAN_MAX_FAULTS];
    u32_t                fault_count;
    bool_t               failsafe_latched;
} titan_fault_mgr_t;

titan_status_t titan_fault_init(titan_fault_mgr_t *mgr);
titan_status_t titan_fault_raise(titan_fault_mgr_t *mgr, u32_t code, titan_fault_severity_t sev);
titan_status_t titan_fault_clear(titan_fault_mgr_t *mgr, u32_t code);
bool_t         titan_fault_is_failsafe_active(const titan_fault_mgr_t *mgr);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_FAULT_MANAGER_H */
