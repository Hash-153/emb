/**
 * @file titan_lockstep.h
 * @brief Asymmetric Dual-Core Lockstep Processor Synchronization & Cross-Core Heartbeat
 */

#ifndef TITAN_LOCKSTEP_H
#define TITAN_LOCKSTEP_H

#include "core/titan_types.h"
#include "core/titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    TITAN_CORE_MASTER = 0,
    TITAN_CORE_CHECKER = 1
} titan_core_role_t;

typedef struct {
    u32_t core_id;
    u64_t signature_accum;
    u32_t step_counter;
    u32_t sync_failures;
} titan_lockstep_ctx_t;

titan_status_t titan_lockstep_init(titan_lockstep_ctx_t *ctx, u32_t core_id);
titan_status_t titan_lockstep_feed_signature(titan_lockstep_ctx_t *ctx, u32_t checkpoint_sig);
bool_t         titan_lockstep_verify_sync(const titan_lockstep_ctx_t *master, const titan_lockstep_ctx_t *checker);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_LOCKSTEP_H */
