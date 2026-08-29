/**
 * @file titan_bist_ram.h
 * @brief IEC 61508 / ISO 26262 March C- Algorithm for RAM Hardware Diagnostics
 * @version 2.4.0
 * @date 2026-08-29
 */

#ifndef TITAN_BIST_RAM_H
#define TITAN_BIST_RAM_H

#include "core/titan_types.h"
#include "core/titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

titan_status_t titan_bist_ram_march_c_destructive(u32_t *start_addr, mem_size_t word_count);
titan_status_t titan_bist_ram_march_c_transparent(u32_t *start_addr, mem_size_t word_count, u32_t *buffer, mem_size_t buf_words);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_BIST_RAM_H */
