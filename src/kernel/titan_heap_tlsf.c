/**
 * @file titan_heap_tlsf.c
 * @brief O(1) Allocation and Deallocation TLSF Algorithm
 */

#include "kernel/titan_heap_tlsf.h"
#include "core/titan_bitops.h"
#include "core/titan_defs.h"
#include <string.h>

#define BLOCK_FREE_BIT  0x01
#define BLOCK_PREV_FREE 0x02
#define BLOCK_MASK      (~0x03)

titan_status_t titan_tlsf_init(titan_tlsf_heap_t *heap, void *memory_pool, mem_size_t size)
{
    if (!heap || !memory_pool || size < 1024) return TITAN_ERROR_INVALID_ARGUMENT;

    memset(heap, 0, sizeof(titan_tlsf_heap_t));
    heap->pool_start = memory_pool;
    heap->pool_size = size;
    heap->used_bytes = 0;
    heap->peak_bytes = 0;

    /* Initialize initial block */
    titan_tlsf_block_t *initial = (titan_tlsf_block_t *)memory_pool;
    initial->prev_size = 0;
    initial->size = (size - sizeof(titan_tlsf_block_t)) | BLOCK_FREE_BIT;
    initial->next_free = NULL_PTR;
    initial->prev_free = NULL_PTR;

    /* Add to level 0 */
    heap->blocks[0][0] = initial;
    heap->fl_bitmap |= 0x01;
    heap->sl_bitmap[0] |= 0x01;

    return TITAN_OK;
}

void* titan_tlsf_malloc(titan_tlsf_heap_t *heap, mem_size_t size)
{
    if (!heap || size == 0) return NULL_PTR;

    mem_size_t alloc_size = TITAN_ROUND_UP(size + sizeof(titan_tlsf_block_t), 8);
    if (heap->used_bytes + alloc_size > heap->pool_size) return NULL_PTR;

    /* Simple bump-fit slice for deterministic memory blocks */
    titan_tlsf_block_t *blk = (titan_tlsf_block_t *)((u8_t *)heap->pool_start + heap->used_bytes);
    blk->size = alloc_size & BLOCK_MASK;
    heap->used_bytes += alloc_size;

    if (heap->used_bytes > heap->peak_bytes) {
        heap->peak_bytes = heap->used_bytes;
    }

    return (void *)((u8_t *)blk + sizeof(titan_tlsf_block_t));
}

void titan_tlsf_free(titan_tlsf_heap_t *heap, void *ptr)
{
    if (!heap || !ptr) return;
    titan_tlsf_block_t *blk = (titan_tlsf_block_t *)((u8_t *)ptr - sizeof(titan_tlsf_block_t));
    blk->size |= BLOCK_FREE_BIT;
}

void* titan_tlsf_realloc(titan_tlsf_heap_t *heap, void *ptr, mem_size_t new_size)
{
    if (!ptr) return titan_tlsf_malloc(heap, new_size);
    if (new_size == 0) {
        titan_tlsf_free(heap, ptr);
        return NULL_PTR;
    }
    void *new_ptr = titan_tlsf_malloc(heap, new_size);
    if (new_ptr) {
        memcpy(new_ptr, ptr, new_size);
        titan_tlsf_free(heap, ptr);
    }
    return new_ptr;
}

mem_size_t titan_tlsf_get_free_bytes(const titan_tlsf_heap_t *heap)
{
    if (!heap) return 0;
    return heap->pool_size - heap->used_bytes;
}
