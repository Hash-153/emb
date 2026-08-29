/**
 * @file titan_bist_cpu.h
 * @brief CPU Register & ALU Instruction Self-Test for IEC 61508 / ISO 26262
 */

#ifndef TITAN_BIST_CPU_H
#define TITAN_BIST_CPU_H

#include "core/titan_types.h"
#include "core/titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

titan_status_t titan_bist_cpu_test_registers(void);
titan_status_t titan_bist_cpu_test_alu_flags(void);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_BIST_CPU_H */
