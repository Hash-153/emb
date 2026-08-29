/**
 * @file titan_scheduler.c
 * @brief Preemptive Microkernel Scheduler Engine with O(1) Bitmap Lookup
 */

#include "kernel/titan_scheduler.h"
#include "core/titan_bitops.h"
#include "core/titan_defs.h"
#include <string.h>

static titan_sched_t s_sched;
static u8_t s_idle_stack[256];
static titan_tcb_t s_idle_tcb;

static void titan_idle_task_func(void *arg)
{
    TITAN_UNUSED_PARAM(arg);
    while (1) {
        /* Low power wait-for-interrupt hook */
    }
}

titan_status_t titan_sched_init(void)
{
    memset(&s_sched, 0, sizeof(titan_sched_t));
    s_sched.is_running = FALSE;
    s_sched.lock_nesting = 0;
    s_sched.tick_counter = 0;
    s_sched.ready_bitmap = 0;

    /* Initialize Idle Task at lowest priority 0 */
    return titan_task_create(&s_idle_tcb, "idle", titan_idle_task_func, NULL_PTR, 0, s_idle_stack, sizeof(s_idle_stack));
}

titan_status_t titan_sched_start(void)
{
    s_sched.is_running = TRUE;
    titan_sched_yield();
    return TITAN_OK;
}

titan_status_t titan_sched_add_task(titan_tcb_t *tcb)
{
    if (!tcb) return TITAN_ERROR_NULL_POINTER;
    u8_t prio = tcb->current_priority;

    /* Insert into ready list */
    tcb->next = s_sched.ready_list[prio];
    tcb->prev = NULL_PTR;
    if (s_sched.ready_list[prio]) {
        s_sched.ready_list[prio]->prev = tcb;
    }
    s_sched.ready_list[prio] = tcb;
    s_sched.ready_bitmap |= TITAN_BIT(prio);

    return TITAN_OK;
}

titan_status_t titan_sched_remove_task(titan_tcb_t *tcb)
{
    if (!tcb) return TITAN_ERROR_NULL_POINTER;
    u8_t prio = tcb->current_priority;

    if (tcb->prev) {
        tcb->prev->next = tcb->next;
    } else {
        s_sched.ready_list[prio] = tcb->next;
    }
    if (tcb->next) {
        tcb->next->prev = tcb->prev;
    }

    tcb->next = NULL_PTR;
    tcb->prev = NULL_PTR;

    if (s_sched.ready_list[prio] == NULL_PTR) {
        s_sched.ready_bitmap &= ~TITAN_BIT(prio);
    }
    return TITAN_OK;
}

titan_status_t titan_sched_set_task_state(titan_tcb_t *tcb, titan_task_state_t new_state)
{
    if (!tcb) return TITAN_ERROR_NULL_POINTER;
    if (tcb->state == new_state) return TITAN_OK;

    if (tcb->state == TITAN_TASK_STATE_READY) {
        titan_sched_remove_task(tcb);
    }

    tcb->state = new_state;

    if (new_state == TITAN_TASK_STATE_READY) {
        titan_sched_add_task(tcb);
    }
    return TITAN_OK;
}

titan_status_t titan_sched_sleep_current(titan_time_ms_t ms)
{
    if (!s_sched.current_task || ms == 0) return TITAN_OK;
    titan_tcb_t *cur = s_sched.current_task;

    titan_sched_lock();
    cur->wake_tick = s_sched.tick_counter + ms;
    titan_sched_set_task_state(cur, TITAN_TASK_STATE_BLOCKED);

    /* Enqueue to blocked list */
    cur->next = s_sched.blocked_list;
    s_sched.blocked_list = cur;

    titan_sched_unlock();
    titan_sched_yield();
    return TITAN_OK;
}

void titan_sched_tick_handler(void)
{
    s_sched.tick_counter++;

    /* Process blocked list */
    titan_tcb_t *curr = s_sched.blocked_list;
    titan_tcb_t *prev = NULL_PTR;

    while (curr) {
        titan_tcb_t *next = curr->next;
        if (s_sched.tick_counter >= curr->wake_tick) {
            /* Unblock */
            if (prev) {
                prev->next = next;
            } else {
                s_sched.blocked_list = next;
            }
            curr->next = NULL_PTR;
            titan_sched_set_task_state(curr, TITAN_TASK_STATE_READY);
        } else {
            prev = curr;
        }
        curr = next;
    }

    /* Check preemption if not locked */
    if (!titan_sched_is_locked()) {
        titan_sched_yield();
    }
}

void titan_sched_yield(void)
{
    if (s_sched.ready_bitmap == 0) return;

    /* Highest priority = 31 - clz(ready_bitmap) */
    u32_t highest_prio = 31 - titan_clz(s_sched.ready_bitmap);
    titan_tcb_t *next_task = s_sched.ready_list[highest_prio];

    if (next_task && next_task != s_sched.current_task) {
        titan_tcb_t *prev_task = s_sched.current_task;
        s_sched.current_task = next_task;
        next_task->state = TITAN_TASK_STATE_RUNNING;
        TITAN_UNUSED_PARAM(prev_task);
        /* Context switch hook */
    }
}

void titan_sched_lock(void)
{
    s_sched.lock_nesting++;
}

void titan_sched_unlock(void)
{
    if (s_sched.lock_nesting > 0) {
        s_sched.lock_nesting--;
    }
}

bool_t titan_sched_is_locked(void)
{
    return (s_sched.lock_nesting > 0);
}

titan_tcb_t* titan_sched_get_current_task(void)
{
    return s_sched.current_task;
}

u32_t titan_sched_get_ticks(void)
{
    return s_sched.tick_counter;
}
