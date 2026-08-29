/**
 * @file titan_bist_ram.c
 * @brief March C- Implementation: Up 0, Up (r0, w1), Up (r1, w0), Down (r0, w1), Down (r1, w0), Down r0
 */

#include "safety/titan_bist_ram.h"

titan_status_t titan_bist_ram_march_c_destructive(u32_t *start_addr, mem_size_t word_count)
{
    if (!start_addr || word_count == 0) return TITAN_ERROR_INVALID_ARGUMENT;

    volatile u32_t *ram = (volatile u32_t *)start_addr;

    /* Step 1: Upward write 0 */
    for (mem_size_t i = 0; i < word_count; ++i) {
        ram[i] = 0x00000000UL;
    }

    /* Step 2: Upward read 0, write 1 */
    for (mem_size_t i = 0; i < word_count; ++i) {
        if (ram[i] != 0x00000000UL) return TITAN_SAFETY_ERR_RAM_TEST_FAIL;
        ram[i] = 0xFFFFFFFFUL;
    }

    /* Step 3: Upward read 1, write 0 */
    for (mem_size_t i = 0; i < word_count; ++i) {
        if (ram[i] != 0xFFFFFFFFUL) return TITAN_SAFETY_ERR_RAM_TEST_FAIL;
        ram[i] = 0x00000000UL;
    }

    /* Step 4: Downward read 0, write 1 */
    for (s32_t i = (s32_t)word_count - 1; i >= 0; --i) {
        if (ram[i] != 0x00000000UL) return TITAN_SAFETY_ERR_RAM_TEST_FAIL;
        ram[i] = 0xFFFFFFFFUL;
    }

    /* Step 5: Downward read 1, write 0 */
    for (s32_t i = (s32_t)word_count - 1; i >= 0; --i) {
        if (ram[i] != 0xFFFFFFFFUL) return TITAN_SAFETY_ERR_RAM_TEST_FAIL;
        ram[i] = 0x00000000UL;
    }

    /* Step 6: Downward read 0 */
    for (s32_t i = (s32_t)word_count - 1; i >= 0; --i) {
        if (ram[i] != 0x00000000UL) return TITAN_SAFETY_ERR_RAM_TEST_FAIL;
    }

    return TITAN_OK;
}
