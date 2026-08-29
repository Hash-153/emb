/**
 * @file titan_task.c
 * @brief Task Initialization, Stack Formatting, and Canary Verification
 */

#include "kernel/titan_task.h"
#include "core/titan_string.h"
#include "kernel/titan_scheduler.h"
#include <string.h>

#define STACK_FILL_PATTERN 0xA5A5A5A5UL

titan_status_t titan_task_create(titan_tcb_t *tcb,
                                const char *name,
                                titan_task_func_t entry,
                                void *arg,
                                u8_t priority,
                                void *stack_storage,
                                mem_size_t stack_size)
{
    if (!tcb || !entry || !stack_storage || stack_size < 128) {
        return TITAN_ERROR_INVALID_ARGUMENT;
    }
    if (priority >= TITAN_TASK_MAX_PRIORITIES) {
        return TITAN_ERROR_INVALID_ARGUMENT;
    }

    memset(tcb, 0, sizeof(titan_tcb_t));
    titan_strlcpy(tcb->name, name ? name : "task", TITAN_MAX_TASK_NAME_LEN);

    tcb->entry_func = entry;
    tcb->arg = arg;
    tcb->base_priority = priority;
    tcb->current_priority = priority;
    tcb->state = TITAN_TASK_STATE_READY;
    tcb->stack_base = stack_storage;
    tcb->stack_size = stack_size;

    /* Fill stack with pattern to measure high-watermark */
    u32_t *words = (u32_t *)stack_storage;
    mem_size_t word_count = stack_size / sizeof(u32_t);
    for (mem_size_t i = 0; i < word_count; ++i) {
        words[i] = STACK_FILL_PATTERN;
    }

    /* Set up stack canaries */
    tcb->canary_bottom = TITAN_STACK_CANARY_MAGIC;
    tcb->canary_top = TITAN_STACK_CANARY_MAGIC;
    words[0] = TITAN_STACK_CANARY_MAGIC;
    words[word_count - 1] = TITAN_STACK_CANARY_MAGIC;

    /* Architecture stack frame initialization */
    /* Point stack_ptr near the top of stack storage aligned to 8 bytes */
    uintptr_t top_addr = (uintptr_t)stack_storage + stack_size - (2 * sizeof(u32_t));
    top_addr &= ~((uintptr_t)0x7);
    tcb->stack_ptr = (void *)top_addr;

    /* Register task with scheduler */
    return titan_sched_add_task(tcb);
}

titan_status_t titan_task_suspend(titan_tcb_t *tcb)
{
    if (!tcb) return TITAN_ERROR_NULL_POINTER;
    return titan_sched_set_task_state(tcb, TITAN_TASK_STATE_SUSPENDED);
}

titan_status_t titan_task_resume(titan_tcb_t *tcb)
{
    if (!tcb) return TITAN_ERROR_NULL_POINTER;
    if (tcb->state != TITAN_TASK_STATE_SUSPENDED) return TITAN_ERROR_INVALID_ARGUMENT;
    return titan_sched_set_task_state(tcb, TITAN_TASK_STATE_READY);
}

titan_status_t titan_task_delay_ms(titan_time_ms_t delay_ms)
{
    return titan_sched_sleep_current(delay_ms);
}

bool_t titan_task_verify_stack(const titan_tcb_t *tcb)
{
    if (!tcb || !tcb->stack_base) return FALSE;
    u32_t *words = (u32_t *)tcb->stack_base;
    mem_size_t word_count = tcb->stack_size / sizeof(u32_t);

    if (words[0] != TITAN_STACK_CANARY_MAGIC || words[word_count - 1] != TITAN_STACK_CANARY_MAGIC) {
        return FALSE;
    }
    return TRUE;
}

mem_size_t titan_task_get_stack_high_watermark(const titan_tcb_t *tcb)
{
    if (!tcb || !tcb->stack_base) return 0;
    const u32_t *words = (const u32_t *)tcb->stack_base;
    mem_size_t word_count = tcb->stack_size / sizeof(u32_t);
    mem_size_t unused = 0;

    for (mem_size_t i = 1; i < word_count - 1; ++i) {
        if (words[i] == STACK_FILL_PATTERN) {
            unused += sizeof(u32_t);
        } else {
            break;
        }
    }
    return tcb->stack_size - unused;
}
