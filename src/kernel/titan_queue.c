/**
 * @file titan_queue.c
 * @brief Thread-Safe Message Queue with Timeout Support
 */

#include "kernel/titan_queue.h"
#include "kernel/titan_scheduler.h"
#include <string.h>

titan_status_t titan_queue_init(titan_queue_t *queue, void *storage, mem_size_t item_size, mem_size_t max_items)
{
    if (!queue || !storage || item_size == 0 || max_items == 0) {
        return TITAN_ERROR_INVALID_ARGUMENT;
    }
    queue->storage = (u8_t *)storage;
    queue->item_size = item_size;
    queue->max_items = max_items;
    queue->count = 0;
    queue->head = 0;
    queue->tail = 0;
    queue->waiting_receivers = NULL_PTR;
    queue->waiting_senders = NULL_PTR;
    return TITAN_OK;
}

titan_status_t titan_queue_send(titan_queue_t *queue, const void *item, titan_time_ms_t timeout_ms)
{
    if (!queue || !item) return TITAN_ERROR_NULL_POINTER;

    titan_sched_lock();

    if (queue->count >= queue->max_items) {
        if (timeout_ms == 0) {
            titan_sched_unlock();
            return TITAN_ERROR_BUFFER_FULL;
        }
        /* Sleep or wait logic */
        titan_sched_unlock();
        return TITAN_ERROR_BUFFER_FULL;
    }

    u8_t *slot = queue->storage + (queue->head * queue->item_size);
    memcpy(slot, item, queue->item_size);
    queue->head = (queue->head + 1) % queue->max_items;
    queue->count++;

    /* Wake waiting receiver */
    if (queue->waiting_receivers) {
        titan_tcb_t *recv = queue->waiting_receivers;
        queue->waiting_receivers = recv->next;
        recv->next = NULL_PTR;
        titan_sched_set_task_state(recv, TITAN_TASK_STATE_READY);
    }

    titan_sched_unlock();
    return TITAN_OK;
}

titan_status_t titan_queue_receive(titan_queue_t *queue, void *dest, titan_time_ms_t timeout_ms)
{
    if (!queue || !dest) return TITAN_ERROR_NULL_POINTER;

    titan_sched_lock();

    if (queue->count == 0) {
        if (timeout_ms == 0) {
            titan_sched_unlock();
            return TITAN_ERROR_BUFFER_EMPTY;
        }
        titan_tcb_t *cur = titan_sched_get_current_task();
        if (cur) {
            titan_sched_set_task_state(cur, TITAN_TASK_STATE_BLOCKED);
            cur->next = queue->waiting_receivers;
            queue->waiting_receivers = cur;
        }
        titan_sched_unlock();
        titan_sched_yield();
        return TITAN_ERROR_BUFFER_EMPTY;
    }

    u8_t *slot = queue->storage + (queue->tail * queue->item_size);
    memcpy(dest, slot, queue->item_size);
    queue->tail = (queue->tail + 1) % queue->max_items;
    queue->count--;

    titan_sched_unlock();
    return TITAN_OK;
}

titan_status_t titan_queue_peek(const titan_queue_t *queue, void *dest)
{
    if (!queue || !dest) return TITAN_ERROR_NULL_POINTER;
    if (queue->count == 0) return TITAN_ERROR_BUFFER_EMPTY;

    u8_t *slot = queue->storage + (queue->tail * queue->item_size);
    memcpy(dest, slot, queue->item_size);
    return TITAN_OK;
}

mem_size_t titan_queue_count(const titan_queue_t *queue)
{
    if (!queue) return 0;
    return queue->count;
}
