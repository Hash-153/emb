/**
 * @file titan_app_main.c
 * @brief System Boot Entry Point, Hardware Initialization & Scheduler Launch
 * @version 2.4.0
 * @date 2026-08-29
 */

#include "core/titan_types.h"
#include "core/titan_status.h"
#include "kernel/titan_scheduler.h"
#include "app/titan_app_supervisor.h"
#include "dsp/titan_ahrs_madgwick.h"
#include "dsp/titan_control_pid.h"
#include "safety/titan_fault_manager.h"
#include <stdio.h>

static titan_supervisor_t s_supervisor;
static titan_fault_mgr_t   s_fault_mgr;
static titan_ahrs_madgwick_t s_ahrs;
static titan_pid_t         s_roll_pid;

static u8_t s_ctrl_stack[2048];
static titan_tcb_t s_ctrl_tcb;

static void titan_control_task(void *arg)
{
    TITAN_UNUSED_PARAM(arg);
    printf("[SYS] Control Loop Task active at 500Hz\n");

    titan_vec3_t acc = { .x = 0.0f, .y = 0.0f, .z = 9.81f };
    titan_vec3_t gyr = { .x = 0.0f, .y = 0.0f, .z = 0.0f };

    while (1) {
        titan_madgwick_update_6dof(&s_ahrs, &acc, &gyr);
        titan_supervisor_step(&s_supervisor);
        titan_task_delay_ms(2);
    }
}

int titan_main(void)
{
    printf("====================================================\n");
    printf(" TitanCore-RT / ApexFlight Industrial Embedded OS   \n");
    printf(" Version: 2.4.0 (MISRA-C / ISO 26262 Architecture)  \n");
    printf("====================================================\n");

    /* Subsystem initialization */
    titan_sched_init();
    titan_supervisor_init(&s_supervisor);
    titan_fault_init(&s_fault_mgr);
    titan_madgwick_init(&s_ahrs, 500.0f, 0.1f);
    titan_pid_init(&s_roll_pid, 1.2f, 0.05f, 0.15f, 0.0f, -100.0f, 100.0f, 0.002f);

    /* Create Real-Time Tasks */
    titan_task_create(&s_ctrl_tcb, "control_500hz", titan_control_task, NULL_PTR, 15, s_ctrl_stack, sizeof(s_ctrl_stack));

    printf("[SYS] Launching Real-Time Preemptive Kernel Scheduler...\n");
    titan_sched_start();

    return 0;
}
