/**
 * @file titan_lockstep.c
 * @brief Lockstep Checkpoint Signatures & Miscompare Trap Execution
 */

#include "kernel/titan_lockstep.h"
#include "core/titan_crc.h"
#include <string.h>

titan_status_t titan_lockstep_init(titan_lockstep_ctx_t *ctx, u32_t core_id)
{
    if (!ctx) return TITAN_ERROR_NULL_POINTER;
    memset(ctx, 0, sizeof(titan_lockstep_ctx_t));
    ctx->core_id = core_id;
    return TITAN_OK;
}

titan_status_t titan_lockstep_feed_signature(titan_lockstep_ctx_t *ctx, u32_t checkpoint_sig)
{
    if (!ctx) return TITAN_ERROR_NULL_POINTER;
    ctx->signature_accum = (ctx->signature_accum * 1664525UL + checkpoint_sig + 1013904223UL);
    ctx->step_counter++;
    return TITAN_OK;
}

bool_t titan_lockstep_verify_sync(const titan_lockstep_ctx_t *master, const titan_lockstep_ctx_t *checker)
{
    if (!master || !checker) return FALSE;
    return (master->signature_accum == checker->signature_accum &&
            master->step_counter == checker->step_counter);
}
