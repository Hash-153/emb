/**
 * @file titan_sim_hw.c
 * @brief Microcontroller Hardware Register, Bus, and Peripheral Emulation for Host Testing
 */

#include "sim/titan_sim_hw.h"
#include <string.h>
#include <stdio.h>

static titan_sim_hw_state_t s_sim_state;

titan_status_t titan_sim_hw_init(void)
{
    memset(&s_sim_state, 0, sizeof(titan_sim_hw_state_t));
    s_sim_state.interrupts_enabled = TRUE;
    return TITAN_OK;
}

void titan_sim_hw_step(u32_t us)
{
    s_sim_state.simulated_clock_cycles += (u64_t)us * 168; /* 168MHz Clock */
}

titan_sim_hw_state_t* titan_sim_hw_get_state(void)
{
    return &s_sim_state;
}
