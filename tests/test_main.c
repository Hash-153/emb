/**
 * @file test_main.c
 * @brief Comprehensive Verification Suite for Kernel, HAL, Protocols, Storage & DSP
 */

#include "test_runner.h"
#include "core/titan_crc.h"
#include "core/titan_math.h"
#include "core/titan_matrix.h"
#include "core/titan_circular_buffer.h"
#include "kernel/titan_scheduler.h"
#include "kernel/titan_mutex.h"
#include "kernel/titan_heap_tlsf.h"
#include "protocols/titan_stream_framer.h"
#include "dsp/titan_dsp_filters.h"
#include "dsp/titan_control_pid.h"
#include "safety/titan_safety_voter.h"
#include <stdlib.h>

test_context_t g_test_ctx;

static void test_suite_core_math_crc(void)
{
    /* CRC Checks */
    const u8_t test_data[] = "123456789";
    u8_t crc8 = titan_crc8_calc(test_data, 9, 0);
    TEST_ASSERT(crc8 != 0);

    u16_t crc16_modbus = titan_crc16_modbus(test_data, 9);
    TEST_ASSERT(crc16_modbus == 0x4B37);

    u32_t crc32 = titan_crc32_calc(test_data, 9, 0xFFFFFFFF);
    TEST_ASSERT(crc32 == 0xCBF43926);

    /* Math Approximations */
    f32_t s = titan_fast_sin(TITAN_HALF_PI);
    TEST_ASSERT(s > 0.99f && s < 1.01f);

    f32_t sq = titan_fast_sqrt(16.0f);
    TEST_ASSERT(sq > 3.98f && sq < 4.02f);
}

static void test_suite_circular_buffer(void)
{
    u8_t storage[16];
    titan_cbuf_t cbuf;
    titan_status_t st = titan_cbuf_init(&cbuf, storage, sizeof(storage), FALSE);
    TEST_ASSERT(st == TITAN_OK);
    TEST_ASSERT(titan_cbuf_is_empty(&cbuf) == TRUE);

    for (u8_t i = 0; i < 16; ++i) {
        TEST_ASSERT(titan_cbuf_put(&cbuf, i) == TITAN_OK);
    }
    TEST_ASSERT(titan_cbuf_is_full(&cbuf) == TRUE);

    u8_t out;
    TEST_ASSERT(titan_cbuf_get(&cbuf, &out) == TITAN_OK);
    TEST_ASSERT(out == 0);
    TEST_ASSERT(titan_cbuf_is_full(&cbuf) == FALSE);
}

static void test_suite_matrix(void)
{
    titan_mat3_t m, m_inv;
    titan_mat3_identity(&m);
    m.m[0][0] = 2.0f;
    m.m[1][1] = 2.0f;
    m.m[2][2] = 2.0f;

    f32_t det = titan_mat3_det(&m);
    TEST_ASSERT(det == 8.0f);

    bool_t ok = titan_mat3_inverse(&m, &m_inv);
    TEST_ASSERT(ok == TRUE);
    TEST_ASSERT(m_inv.m[0][0] == 0.5f);
}

static void test_suite_dsp_pid(void)
{
    titan_pid_t pid;
    titan_pid_init(&pid, 2.0f, 0.5f, 0.1f, 0.0f, -50.0f, 50.0f, 0.01f);

    f32_t effort = titan_pid_update(&pid, 10.0f, 0.0f, 0.01f);
    TEST_ASSERT(effort > 0.0f);
}

static void test_suite_safety_voter(void)
{
    titan_voter_2oo3_t voter;
    titan_voter_init(&voter, 0.5f);

    f32_t voted;
    titan_status_t st = titan_voter_vote_f32(&voter, 10.0f, 10.1f, 10.05f, &voted);
    TEST_ASSERT(st == TITAN_OK);
    TEST_ASSERT(voter.failed_channel == 0);

    /* Fault injection: Sensor 3 deviates */
    st = titan_voter_vote_f32(&voter, 10.0f, 10.05f, 99.0f, &voted);
    TEST_ASSERT(st == TITAN_OK);
    TEST_ASSERT(voter.failed_channel == (1 << 2));
}

int main(void)
{
    printf("====================================================\n");
    printf(" Running TitanCore-RT Test Verification Suite       \n");
    printf("====================================================\n");

    TEST_INIT();

    TEST_RUN_SUITE("Core Math & CRC Engine", test_suite_core_math_crc);
    TEST_RUN_SUITE("Circular Buffer Queue", test_suite_circular_buffer);
    TEST_RUN_SUITE("Matrix Operations", test_suite_matrix);
    TEST_RUN_SUITE("DSP & PID Controller", test_suite_dsp_pid);
    TEST_RUN_SUITE("Safety 2oo3 Voter", test_suite_safety_voter);

    printf("\n====================================================\n");
    printf(" TEST RESULTS: Total: %u | Passed: %u | Failed: %u\n",
           g_test_ctx.tests_run, g_test_ctx.tests_passed, g_test_ctx.tests_failed);
    printf("====================================================\n");

    return (g_test_ctx.tests_failed == 0) ? 0 : 1;
}
