/**
 * @file titan_mutex.h
 * @brief Priority-Inheritance Mutex Synchronization Primitive
 */

#ifndef TITAN_MUTEX_H
#define TITAN_MUTEX_H

#include "kernel/titan_task.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct titan_mutex {
    titan_tcb_t        *owner;                  /**< Current holding task */
    u8_t                original_priority;      /**< Owner's base priority prior to inheritance */
    u32_t               lock_count;             /**< Recursive lock counter */
    titan_tcb_t        *wait_list;              /**< Queue of blocked tasks awaiting unlock */
} titan_mutex_t;

titan_status_t titan_mutex_init(titan_mutex_t *mutex);
titan_status_t titan_mutex_lock(titan_mutex_t *mutex, titan_time_ms_t timeout_ms);
titan_status_t titan_mutex_unlock(titan_mutex_t *mutex);
titan_status_t titan_mutex_trylock(titan_mutex_t *mutex);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_MUTEX_H */
