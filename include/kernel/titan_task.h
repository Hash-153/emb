/**
 * @file titan_task.h
 * @brief Task Control Block (TCB), Task Lifecycle States, and Stack Canary Integrity
 * @version 2.4.0
 * @date 2026-08-29
 */

#ifndef TITAN_TASK_H
#define TITAN_TASK_H

#include "core/titan_types.h"
#include "core/titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TITAN_MAX_TASK_NAME_LEN     16
#define TITAN_STACK_CANARY_MAGIC    0xDEADBEEFUL
#define TITAN_TASK_MAX_PRIORITIES   32

typedef enum {
    TITAN_TASK_STATE_READY = 0,
    TITAN_TASK_STATE_RUNNING,
    TITAN_TASK_STATE_BLOCKED,
    TITAN_TASK_STATE_SUSPENDED,
    TITAN_TASK_STATE_TERMINATED
} titan_task_state_t;

typedef void (*titan_task_func_t)(void *arg);

typedef struct titan_tcb {
    void               *stack_ptr;                  /**< Current Top of Stack (architecture-dependent) */
    void               *stack_base;                 /**< Base address of allocated stack */
    mem_size_t          stack_size;                 /**< Stack capacity in bytes */
    u32_t               canary_top;                 /**< Canary magic word at stack top */
    u32_t               canary_bottom;              /**< Canary magic word at stack bottom */
    
    char                name[TITAN_MAX_TASK_NAME_LEN];
    u8_t                base_priority;              /**< Assigned base priority (0 = lowest, 31 = highest) */
    u8_t                current_priority;           /**< Priority dynamically adjusted for mutex inheritance */
    titan_task_state_t  state;                      /**< Lifecycle state */
    
    titan_task_func_t   entry_func;                 /**< Main task function */
    void               *arg;                        /**< Argument pointer passed to task */
    
    titan_time_ms_t     wake_tick;                  /**< Scheduler tick when blocked sleep expires */
    u32_t               runtime_ticks;              /**< Execution time accounting */
    
    struct titan_tcb   *next;                       /**< Linked list pointer for priority queues */
    struct titan_tcb   *prev;
} titan_tcb_t;

titan_status_t titan_task_create(titan_tcb_t *tcb,
                                const char *name,
                                titan_task_func_t entry,
                                void *arg,
                                u8_t priority,
                                void *stack_storage,
                                mem_size_t stack_size);

titan_status_t titan_task_suspend(titan_tcb_t *tcb);
titan_status_t titan_task_resume(titan_tcb_t *tcb);
titan_status_t titan_task_delay_ms(titan_time_ms_t delay_ms);
bool_t         titan_task_verify_stack(const titan_tcb_t *tcb);
mem_size_t     titan_task_get_stack_high_watermark(const titan_tcb_t *tcb);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_TASK_H */
