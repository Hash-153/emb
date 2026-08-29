/**
 * @file titan_semaphore.c
 * @brief Counting Semaphore Implementation
 */

#include "kernel/titan_semaphore.h"
#include "kernel/titan_scheduler.h"

titan_status_t titan_sem_init(titan_semaphore_t *sem, u32_t initial_count, u32_t max_count)
{
    if (!sem || max_count == 0 || initial_count > max_count) return TITAN_ERROR_INVALID_ARGUMENT;
    sem->count = initial_count;
    sem->max_count = max_count;
    sem->wait_list = NULL_PTR;
    return TITAN_OK;
}

titan_status_t titan_sem_wait(titan_semaphore_t *sem, titan_time_ms_t timeout_ms)
{
    if (!sem) return TITAN_ERROR_NULL_POINTER;

    titan_sched_lock();
    if (sem->count > 0) {
        sem->count--;
        titan_sched_unlock();
        return TITAN_OK;
    }

    if (timeout_ms == 0) {
        titan_sched_unlock();
        return TITAN_ERROR_BUSY;
    }

    titan_tcb_t *cur = titan_sched_get_current_task();
    if (cur) {
        titan_sched_set_task_state(cur, TITAN_TASK_STATE_BLOCKED);
        cur->next = sem->wait_list;
        sem->wait_list = cur;
    }

    titan_sched_unlock();
    titan_sched_yield();
    return TITAN_OK;
}

titan_status_t titan_sem_post(titan_semaphore_t *sem)
{
    if (!sem) return TITAN_ERROR_NULL_POINTER;

    titan_sched_lock();
    if (sem->wait_list) {
        titan_tcb_t *wake = sem->wait_list;
        sem->wait_list = wake->next;
        wake->next = NULL_PTR;
        titan_sched_set_task_state(wake, TITAN_TASK_STATE_READY);
    } else {
        if (sem->count < sem->max_count) {
            sem->count++;
        }
    }

    titan_sched_unlock();
    titan_sched_yield();
    return TITAN_OK;
}

u32_t titan_sem_get_count(const titan_semaphore_t *sem)
{
    if (!sem) return 0;
    return sem->count;
}
