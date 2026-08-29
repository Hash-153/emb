/**
 * @file titan_mutex.c
 * @brief Mutex with Dynamic Priority Inheritance to Preempt Priority Inversion
 */

#include "kernel/titan_mutex.h"
#include "kernel/titan_scheduler.h"

titan_status_t titan_mutex_init(titan_mutex_t *mutex)
{
    if (!mutex) return TITAN_ERROR_NULL_POINTER;
    mutex->owner = NULL_PTR;
    mutex->original_priority = 0;
    mutex->lock_count = 0;
    mutex->wait_list = NULL_PTR;
    return TITAN_OK;
}

titan_status_t titan_mutex_lock(titan_mutex_t *mutex, titan_time_ms_t timeout_ms)
{
    if (!mutex) return TITAN_ERROR_NULL_POINTER;
    titan_tcb_t *cur = titan_sched_get_current_task();

    titan_sched_lock();

    /* Unowned mutex */
    if (mutex->owner == NULL_PTR) {
        mutex->owner = cur;
        mutex->original_priority = cur ? cur->current_priority : 0;
        mutex->lock_count = 1;
        titan_sched_unlock();
        return TITAN_OK;
    }

    /* Recursive lock */
    if (mutex->owner == cur) {
        mutex->lock_count++;
        titan_sched_unlock();
        return TITAN_OK;
    }

    /* Contended mutex: Apply Priority Inheritance */
    if (cur && mutex->owner && cur->current_priority > mutex->owner->current_priority) {
        mutex->owner->current_priority = cur->current_priority;
    }

    /* Block current task */
    if (timeout_ms == 0) {
        titan_sched_unlock();
        return TITAN_ERROR_BUSY;
    }

    if (cur) {
        titan_sched_set_task_state(cur, TITAN_TASK_STATE_BLOCKED);
        cur->next = mutex->wait_list;
        mutex->wait_list = cur;
    }

    titan_sched_unlock();
    titan_sched_yield();
    return TITAN_OK;
}

titan_status_t titan_mutex_unlock(titan_mutex_t *mutex)
{
    if (!mutex) return TITAN_ERROR_NULL_POINTER;
    titan_tcb_t *cur = titan_sched_get_current_task();

    titan_sched_lock();

    if (mutex->owner != cur) {
        titan_sched_unlock();
        return TITAN_ERROR_PERMISSION_DENIED;
    }

    mutex->lock_count--;
    if (mutex->lock_count > 0) {
        titan_sched_unlock();
        return TITAN_OK;
    }

    /* Restore owner's base priority */
    if (cur) {
        cur->current_priority = mutex->original_priority;
    }

    /* Wake highest priority waiting task */
    if (mutex->wait_list) {
        titan_tcb_t *wake_task = mutex->wait_list;
        mutex->wait_list = wake_task->next;
        wake_task->next = NULL_PTR;

        mutex->owner = wake_task;
        mutex->original_priority = wake_task->current_priority;
        mutex->lock_count = 1;

        titan_sched_set_task_state(wake_task, TITAN_TASK_STATE_READY);
    } else {
        mutex->owner = NULL_PTR;
    }

    titan_sched_unlock();
    titan_sched_yield();
    return TITAN_OK;
}

titan_status_t titan_mutex_trylock(titan_mutex_t *mutex)
{
    return titan_mutex_lock(mutex, 0);
}
