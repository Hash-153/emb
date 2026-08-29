/**
 * @file titan_heap_tlsf.h
 * @brief Deterministic Real-Time Two-Level Segregated Fit (TLSF) Dynamic Heap
 */

#ifndef TITAN_HEAP_TLSF_H
#define TITAN_HEAP_TLSF_H

#include "core/titan_types.h"
#include "core/titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TITAN_TLSF_FL_COUNT 16
#define TITAN_TLSF_SL_COUNT 16

typedef struct titan_tlsf_block {
    mem_size_t               prev_size;
    mem_size_t               size;               /**< Size and flags in lower bits */
    struct titan_tlsf_block *next_free;
    struct titan_tlsf_block *prev_free;
} titan_tlsf_block_t;

typedef struct {
    u32_t                   fl_bitmap;
    u32_t                   sl_bitmap[TITAN_TLSF_FL_COUNT];
    titan_tlsf_block_t     *blocks[TITAN_TLSF_FL_COUNT][TITAN_TLSF_SL_COUNT];
    void                   *pool_start;
    mem_size_t              pool_size;
    mem_size_t              used_bytes;
    mem_size_t              peak_bytes;
} titan_tlsf_heap_t;

titan_status_t titan_tlsf_init(titan_tlsf_heap_t *heap, void *memory_pool, mem_size_t size);
void*          titan_tlsf_malloc(titan_tlsf_heap_t *heap, mem_size_t size);
void           titan_tlsf_free(titan_tlsf_heap_t *heap, void *ptr);
void*          titan_tlsf_realloc(titan_tlsf_heap_t *heap, void *ptr, mem_size_t new_size);
mem_size_t     titan_tlsf_get_free_bytes(const titan_tlsf_heap_t *heap);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_HEAP_TLSF_H */
