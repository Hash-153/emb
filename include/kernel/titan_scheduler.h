/**
 * @file titan_scheduler.h
 * @brief Priority-Preemptive Real-Time Scheduler with Round-Robin Slicing
 */

#ifndef TITAN_SCHEDULER_H
#define TITAN_SCHEDULER_H

#include "kernel/titan_task.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    titan_tcb_t        *ready_list[TITAN_TASK_MAX_PRIORITIES];
    titan_tcb_t        *blocked_list;
    titan_tcb_t        *current_task;
    titan_tcb_t        *idle_task;
    u32_t               ready_bitmap;       /**< Bitmask of ready priorities for O(1) scheduling */
    volatile u32_t      tick_counter;
    volatile bool_t     is_running;
    volatile u32_t      lock_nesting;
} titan_sched_t;

titan_status_t titan_sched_init(void);
titan_status_t titan_sched_start(void);
void           titan_sched_tick_handler(void);
void           titan_sched_yield(void);

titan_status_t titan_sched_add_task(titan_tcb_t *tcb);
titan_status_t titan_sched_remove_task(titan_tcb_t *tcb);
titan_status_t titan_sched_set_task_state(titan_tcb_t *tcb, titan_task_state_t new_state);
titan_status_t titan_sched_sleep_current(titan_time_ms_t ms);

void           titan_sched_lock(void);
void           titan_sched_unlock(void);
bool_t         titan_sched_is_locked(void);

titan_tcb_t*   titan_sched_get_current_task(void);
u32_t          titan_sched_get_ticks(void);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_SCHEDULER_H */
