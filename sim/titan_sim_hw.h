/**
 * @file titan_sim_hw.h
 * @brief Host Emulation API for Virtual UART, CAN, SPI, I2C, and Flash Memory
 */

#ifndef TITAN_SIM_HW_H
#define TITAN_SIM_HW_H

#include "core/titan_types.h"
#include "core/titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    u64_t simulated_clock_cycles;
    bool_t interrupts_enabled;
    u32_t uart_tx_bytes;
    u32_t can_tx_frames;
} titan_sim_hw_state_t;

titan_status_t titan_sim_hw_init(void);
void           titan_sim_hw_step(u32_t us);
titan_sim_hw_state_t* titan_sim_hw_get_state(void);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_SIM_HW_H */
