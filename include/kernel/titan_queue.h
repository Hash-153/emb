/**
 * @file titan_queue.h
 * @brief Bounded Inter-Task Message Queue with Copy and Zero-Copy Pointers
 */

#ifndef TITAN_QUEUE_H
#define TITAN_QUEUE_H

#include "kernel/titan_task.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    u8_t               *storage;
    mem_size_t          item_size;
    mem_size_t          max_items;
    volatile mem_size_t count;
    volatile mem_size_t head;
    volatile mem_size_t tail;
    titan_tcb_t        *waiting_receivers;
    titan_tcb_t        *waiting_senders;
} titan_queue_t;

titan_status_t titan_queue_init(titan_queue_t *queue, void *storage, mem_size_t item_size, mem_size_t max_items);
titan_status_t titan_queue_send(titan_queue_t *queue, const void *item, titan_time_ms_t timeout_ms);
titan_status_t titan_queue_receive(titan_queue_t *queue, void *dest, titan_time_ms_t timeout_ms);
titan_status_t titan_queue_peek(const titan_queue_t *queue, void *dest);
mem_size_t     titan_queue_count(const titan_queue_t *queue);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_QUEUE_H */
