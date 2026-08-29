/**
 * @file titan_bist_cpu.c
 * @brief CPU Functional Pattern Checks
 */

#include "safety/titan_bist_cpu.h"

titan_status_t titan_bist_cpu_test_registers(void)
{
    volatile u32_t pat1 = 0x55555555UL;
    volatile u32_t pat2 = 0xAAAAAAAAUL;

    if ((pat1 ^ pat2) != 0xFFFFFFFFUL) {
        return TITAN_SAFETY_ERR_CPU_REG_FAIL;
    }
    return TITAN_OK;
}

titan_status_t titan_bist_cpu_test_alu_flags(void)
{
    volatile s32_t a = 2147483647;
    volatile s32_t b = 1;
    volatile s32_t res = a + b;

    if (res >= 0) {
        /* Overflow flag failure */
        return TITAN_SAFETY_ERR_CPU_REG_FAIL;
    }
    return TITAN_OK;
}
