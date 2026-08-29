/**
 * @file titan_semaphore.h
 * @brief Thread-Safe Counting Semaphore Synchronization Primitive
 */

#ifndef TITAN_SEMAPHORE_H
#define TITAN_SEMAPHORE_H

#include "kernel/titan_task.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    volatile u32_t count;
    u32_t          max_count;
    titan_tcb_t   *wait_list;
} titan_semaphore_t;

titan_status_t titan_sem_init(titan_semaphore_t *sem, u32_t initial_count, u32_t max_count);
titan_status_t titan_sem_wait(titan_semaphore_t *sem, titan_time_ms_t timeout_ms);
titan_status_t titan_sem_post(titan_semaphore_t *sem);
u32_t          titan_sem_get_count(const titan_semaphore_t *sem);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_SEMAPHORE_H */
