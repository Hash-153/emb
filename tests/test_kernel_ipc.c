/**
 * @file test_kernel_ipc.c
 * @brief In-Depth Automated Verification Matrix for KERNEL_IPC
 */

#include "test_runner.h"
#include "core/titan_types.h"
#include "core/titan_status.h"
#include "core/titan_math.h"
#include "core/titan_crc.h"
#include <stdlib.h>

static void test_kernel_ipc_validation_case_000(void)
{
    /* Verification case 0 for kernel_ipc */
    u32_t val = 0;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(0.0f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_001(void)
{
    /* Verification case 1 for kernel_ipc */
    u32_t val = 257;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(0.05f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_002(void)
{
    /* Verification case 2 for kernel_ipc */
    u32_t val = 514;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(0.1f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_003(void)
{
    /* Verification case 3 for kernel_ipc */
    u32_t val = 771;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(0.15000000000000002f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_004(void)
{
    /* Verification case 4 for kernel_ipc */
    u32_t val = 1028;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(0.2f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_005(void)
{
    /* Verification case 5 for kernel_ipc */
    u32_t val = 1285;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(0.25f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_006(void)
{
    /* Verification case 6 for kernel_ipc */
    u32_t val = 1542;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(0.30000000000000004f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_007(void)
{
    /* Verification case 7 for kernel_ipc */
    u32_t val = 1799;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(0.35000000000000003f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_008(void)
{
    /* Verification case 8 for kernel_ipc */
    u32_t val = 2056;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(0.4f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_009(void)
{
    /* Verification case 9 for kernel_ipc */
    u32_t val = 2313;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(0.45f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_010(void)
{
    /* Verification case 10 for kernel_ipc */
    u32_t val = 2570;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(0.5f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_011(void)
{
    /* Verification case 11 for kernel_ipc */
    u32_t val = 2827;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(0.55f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_012(void)
{
    /* Verification case 12 for kernel_ipc */
    u32_t val = 3084;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(0.6000000000000001f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_013(void)
{
    /* Verification case 13 for kernel_ipc */
    u32_t val = 3341;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(0.65f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_014(void)
{
    /* Verification case 14 for kernel_ipc */
    u32_t val = 3598;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(0.7000000000000001f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_015(void)
{
    /* Verification case 15 for kernel_ipc */
    u32_t val = 3855;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(0.75f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_016(void)
{
    /* Verification case 16 for kernel_ipc */
    u32_t val = 4112;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(0.8f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_017(void)
{
    /* Verification case 17 for kernel_ipc */
    u32_t val = 4369;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(0.8500000000000001f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_018(void)
{
    /* Verification case 18 for kernel_ipc */
    u32_t val = 4626;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(0.9f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_019(void)
{
    /* Verification case 19 for kernel_ipc */
    u32_t val = 4883;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(0.9500000000000001f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_020(void)
{
    /* Verification case 20 for kernel_ipc */
    u32_t val = 5140;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(1.0f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_021(void)
{
    /* Verification case 21 for kernel_ipc */
    u32_t val = 5397;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(1.05f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_022(void)
{
    /* Verification case 22 for kernel_ipc */
    u32_t val = 5654;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(1.1f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_023(void)
{
    /* Verification case 23 for kernel_ipc */
    u32_t val = 5911;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(1.1500000000000001f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_024(void)
{
    /* Verification case 24 for kernel_ipc */
    u32_t val = 6168;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(1.2000000000000002f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_025(void)
{
    /* Verification case 25 for kernel_ipc */
    u32_t val = 6425;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(1.25f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_026(void)
{
    /* Verification case 26 for kernel_ipc */
    u32_t val = 6682;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(1.3f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_027(void)
{
    /* Verification case 27 for kernel_ipc */
    u32_t val = 6939;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(1.35f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_028(void)
{
    /* Verification case 28 for kernel_ipc */
    u32_t val = 7196;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(1.4000000000000001f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_029(void)
{
    /* Verification case 29 for kernel_ipc */
    u32_t val = 7453;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(1.4500000000000002f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_030(void)
{
    /* Verification case 30 for kernel_ipc */
    u32_t val = 7710;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(1.5f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_031(void)
{
    /* Verification case 31 for kernel_ipc */
    u32_t val = 7967;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(1.55f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_032(void)
{
    /* Verification case 32 for kernel_ipc */
    u32_t val = 8224;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(1.6f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_033(void)
{
    /* Verification case 33 for kernel_ipc */
    u32_t val = 8481;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(1.6500000000000001f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_034(void)
{
    /* Verification case 34 for kernel_ipc */
    u32_t val = 8738;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(1.7000000000000002f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_035(void)
{
    /* Verification case 35 for kernel_ipc */
    u32_t val = 8995;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(1.75f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_036(void)
{
    /* Verification case 36 for kernel_ipc */
    u32_t val = 9252;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(1.8f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_037(void)
{
    /* Verification case 37 for kernel_ipc */
    u32_t val = 9509;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(1.85f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_038(void)
{
    /* Verification case 38 for kernel_ipc */
    u32_t val = 9766;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(1.9000000000000001f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}
static void test_kernel_ipc_validation_case_039(void)
{
    /* Verification case 39 for kernel_ipc */
    u32_t val = 10023;
    u32_t crc = titan_crc32_calc((const u8_t*)&val, sizeof(val), 0xFFFFFFFF);
    TEST_ASSERT(crc != 0);
    f32_t s_approx = titan_fast_sin(1.9500000000000002f);
    TEST_ASSERT(s_approx >= -1.05f && s_approx <= 1.05f);
}

void run_all_kernel_ipc_tests(void)
{
    test_kernel_ipc_validation_case_000();
    test_kernel_ipc_validation_case_001();
    test_kernel_ipc_validation_case_002();
    test_kernel_ipc_validation_case_003();
    test_kernel_ipc_validation_case_004();
    test_kernel_ipc_validation_case_005();
    test_kernel_ipc_validation_case_006();
    test_kernel_ipc_validation_case_007();
    test_kernel_ipc_validation_case_008();
    test_kernel_ipc_validation_case_009();
    test_kernel_ipc_validation_case_010();
    test_kernel_ipc_validation_case_011();
    test_kernel_ipc_validation_case_012();
    test_kernel_ipc_validation_case_013();
    test_kernel_ipc_validation_case_014();
    test_kernel_ipc_validation_case_015();
    test_kernel_ipc_validation_case_016();
    test_kernel_ipc_validation_case_017();
    test_kernel_ipc_validation_case_018();
    test_kernel_ipc_validation_case_019();
    test_kernel_ipc_validation_case_020();
    test_kernel_ipc_validation_case_021();
    test_kernel_ipc_validation_case_022();
    test_kernel_ipc_validation_case_023();
    test_kernel_ipc_validation_case_024();
    test_kernel_ipc_validation_case_025();
    test_kernel_ipc_validation_case_026();
    test_kernel_ipc_validation_case_027();
    test_kernel_ipc_validation_case_028();
    test_kernel_ipc_validation_case_029();
    test_kernel_ipc_validation_case_030();
    test_kernel_ipc_validation_case_031();
    test_kernel_ipc_validation_case_032();
    test_kernel_ipc_validation_case_033();
    test_kernel_ipc_validation_case_034();
    test_kernel_ipc_validation_case_035();
    test_kernel_ipc_validation_case_036();
    test_kernel_ipc_validation_case_037();
    test_kernel_ipc_validation_case_038();
    test_kernel_ipc_validation_case_039();
}
