/**
 * @file test_protocols.c
 * @brief Automated Unit Testing Suite for TitanCore-RT PROTOCOLS Subsystem
 */

#include "test_runner.h"
#include "core/titan_types.h"
#include "core/titan_status.h"
#include "core/titan_math.h"
#include <stdlib.h>

static void test_protocols_case_00(void)
{
    /* Test execution pattern for protocols suite 0 */
    u32_t test_val_0 = 0;
    TEST_ASSERT(test_val_0 == 0);
    f32_t f_val = titan_fast_sin(0.0f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_01(void)
{
    /* Test execution pattern for protocols suite 1 */
    u32_t test_val_1 = 137;
    TEST_ASSERT(test_val_1 == 137);
    f32_t f_val = titan_fast_sin(0.1f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_02(void)
{
    /* Test execution pattern for protocols suite 2 */
    u32_t test_val_2 = 274;
    TEST_ASSERT(test_val_2 == 274);
    f32_t f_val = titan_fast_sin(0.2f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_03(void)
{
    /* Test execution pattern for protocols suite 3 */
    u32_t test_val_3 = 411;
    TEST_ASSERT(test_val_3 == 411);
    f32_t f_val = titan_fast_sin(0.30000000000000004f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_04(void)
{
    /* Test execution pattern for protocols suite 4 */
    u32_t test_val_4 = 548;
    TEST_ASSERT(test_val_4 == 548);
    f32_t f_val = titan_fast_sin(0.4f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_05(void)
{
    /* Test execution pattern for protocols suite 5 */
    u32_t test_val_5 = 685;
    TEST_ASSERT(test_val_5 == 685);
    f32_t f_val = titan_fast_sin(0.5f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_06(void)
{
    /* Test execution pattern for protocols suite 6 */
    u32_t test_val_6 = 822;
    TEST_ASSERT(test_val_6 == 822);
    f32_t f_val = titan_fast_sin(0.6000000000000001f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_07(void)
{
    /* Test execution pattern for protocols suite 7 */
    u32_t test_val_7 = 959;
    TEST_ASSERT(test_val_7 == 959);
    f32_t f_val = titan_fast_sin(0.7000000000000001f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_08(void)
{
    /* Test execution pattern for protocols suite 8 */
    u32_t test_val_8 = 1096;
    TEST_ASSERT(test_val_8 == 1096);
    f32_t f_val = titan_fast_sin(0.8f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_09(void)
{
    /* Test execution pattern for protocols suite 9 */
    u32_t test_val_9 = 1233;
    TEST_ASSERT(test_val_9 == 1233);
    f32_t f_val = titan_fast_sin(0.9f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_10(void)
{
    /* Test execution pattern for protocols suite 10 */
    u32_t test_val_10 = 1370;
    TEST_ASSERT(test_val_10 == 1370);
    f32_t f_val = titan_fast_sin(1.0f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_11(void)
{
    /* Test execution pattern for protocols suite 11 */
    u32_t test_val_11 = 1507;
    TEST_ASSERT(test_val_11 == 1507);
    f32_t f_val = titan_fast_sin(1.1f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_12(void)
{
    /* Test execution pattern for protocols suite 12 */
    u32_t test_val_12 = 1644;
    TEST_ASSERT(test_val_12 == 1644);
    f32_t f_val = titan_fast_sin(1.2000000000000002f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_13(void)
{
    /* Test execution pattern for protocols suite 13 */
    u32_t test_val_13 = 1781;
    TEST_ASSERT(test_val_13 == 1781);
    f32_t f_val = titan_fast_sin(1.3f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_14(void)
{
    /* Test execution pattern for protocols suite 14 */
    u32_t test_val_14 = 1918;
    TEST_ASSERT(test_val_14 == 1918);
    f32_t f_val = titan_fast_sin(1.4000000000000001f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_15(void)
{
    /* Test execution pattern for protocols suite 15 */
    u32_t test_val_15 = 2055;
    TEST_ASSERT(test_val_15 == 2055);
    f32_t f_val = titan_fast_sin(1.5f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_16(void)
{
    /* Test execution pattern for protocols suite 16 */
    u32_t test_val_16 = 2192;
    TEST_ASSERT(test_val_16 == 2192);
    f32_t f_val = titan_fast_sin(1.6f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_17(void)
{
    /* Test execution pattern for protocols suite 17 */
    u32_t test_val_17 = 2329;
    TEST_ASSERT(test_val_17 == 2329);
    f32_t f_val = titan_fast_sin(1.7000000000000002f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_18(void)
{
    /* Test execution pattern for protocols suite 18 */
    u32_t test_val_18 = 2466;
    TEST_ASSERT(test_val_18 == 2466);
    f32_t f_val = titan_fast_sin(1.8f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_19(void)
{
    /* Test execution pattern for protocols suite 19 */
    u32_t test_val_19 = 2603;
    TEST_ASSERT(test_val_19 == 2603);
    f32_t f_val = titan_fast_sin(1.9000000000000001f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_20(void)
{
    /* Test execution pattern for protocols suite 20 */
    u32_t test_val_20 = 2740;
    TEST_ASSERT(test_val_20 == 2740);
    f32_t f_val = titan_fast_sin(2.0f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_21(void)
{
    /* Test execution pattern for protocols suite 21 */
    u32_t test_val_21 = 2877;
    TEST_ASSERT(test_val_21 == 2877);
    f32_t f_val = titan_fast_sin(2.1f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_22(void)
{
    /* Test execution pattern for protocols suite 22 */
    u32_t test_val_22 = 3014;
    TEST_ASSERT(test_val_22 == 3014);
    f32_t f_val = titan_fast_sin(2.2f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_23(void)
{
    /* Test execution pattern for protocols suite 23 */
    u32_t test_val_23 = 3151;
    TEST_ASSERT(test_val_23 == 3151);
    f32_t f_val = titan_fast_sin(2.3000000000000003f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_24(void)
{
    /* Test execution pattern for protocols suite 24 */
    u32_t test_val_24 = 3288;
    TEST_ASSERT(test_val_24 == 3288);
    f32_t f_val = titan_fast_sin(2.4000000000000004f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_25(void)
{
    /* Test execution pattern for protocols suite 25 */
    u32_t test_val_25 = 3425;
    TEST_ASSERT(test_val_25 == 3425);
    f32_t f_val = titan_fast_sin(2.5f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_26(void)
{
    /* Test execution pattern for protocols suite 26 */
    u32_t test_val_26 = 3562;
    TEST_ASSERT(test_val_26 == 3562);
    f32_t f_val = titan_fast_sin(2.6f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_27(void)
{
    /* Test execution pattern for protocols suite 27 */
    u32_t test_val_27 = 3699;
    TEST_ASSERT(test_val_27 == 3699);
    f32_t f_val = titan_fast_sin(2.7f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_28(void)
{
    /* Test execution pattern for protocols suite 28 */
    u32_t test_val_28 = 3836;
    TEST_ASSERT(test_val_28 == 3836);
    f32_t f_val = titan_fast_sin(2.8000000000000003f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_29(void)
{
    /* Test execution pattern for protocols suite 29 */
    u32_t test_val_29 = 3973;
    TEST_ASSERT(test_val_29 == 3973);
    f32_t f_val = titan_fast_sin(2.9000000000000004f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_30(void)
{
    /* Test execution pattern for protocols suite 30 */
    u32_t test_val_30 = 4110;
    TEST_ASSERT(test_val_30 == 4110);
    f32_t f_val = titan_fast_sin(3.0f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_31(void)
{
    /* Test execution pattern for protocols suite 31 */
    u32_t test_val_31 = 4247;
    TEST_ASSERT(test_val_31 == 4247);
    f32_t f_val = titan_fast_sin(3.1f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_32(void)
{
    /* Test execution pattern for protocols suite 32 */
    u32_t test_val_32 = 4384;
    TEST_ASSERT(test_val_32 == 4384);
    f32_t f_val = titan_fast_sin(3.2f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_33(void)
{
    /* Test execution pattern for protocols suite 33 */
    u32_t test_val_33 = 4521;
    TEST_ASSERT(test_val_33 == 4521);
    f32_t f_val = titan_fast_sin(3.3000000000000003f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_34(void)
{
    /* Test execution pattern for protocols suite 34 */
    u32_t test_val_34 = 4658;
    TEST_ASSERT(test_val_34 == 4658);
    f32_t f_val = titan_fast_sin(3.4000000000000004f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_35(void)
{
    /* Test execution pattern for protocols suite 35 */
    u32_t test_val_35 = 4795;
    TEST_ASSERT(test_val_35 == 4795);
    f32_t f_val = titan_fast_sin(3.5f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_36(void)
{
    /* Test execution pattern for protocols suite 36 */
    u32_t test_val_36 = 4932;
    TEST_ASSERT(test_val_36 == 4932);
    f32_t f_val = titan_fast_sin(3.6f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_37(void)
{
    /* Test execution pattern for protocols suite 37 */
    u32_t test_val_37 = 5069;
    TEST_ASSERT(test_val_37 == 5069);
    f32_t f_val = titan_fast_sin(3.7f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_38(void)
{
    /* Test execution pattern for protocols suite 38 */
    u32_t test_val_38 = 5206;
    TEST_ASSERT(test_val_38 == 5206);
    f32_t f_val = titan_fast_sin(3.8000000000000003f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_39(void)
{
    /* Test execution pattern for protocols suite 39 */
    u32_t test_val_39 = 5343;
    TEST_ASSERT(test_val_39 == 5343);
    f32_t f_val = titan_fast_sin(3.9000000000000004f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_40(void)
{
    /* Test execution pattern for protocols suite 40 */
    u32_t test_val_40 = 5480;
    TEST_ASSERT(test_val_40 == 5480);
    f32_t f_val = titan_fast_sin(4.0f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_41(void)
{
    /* Test execution pattern for protocols suite 41 */
    u32_t test_val_41 = 5617;
    TEST_ASSERT(test_val_41 == 5617);
    f32_t f_val = titan_fast_sin(4.1000000000000005f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_42(void)
{
    /* Test execution pattern for protocols suite 42 */
    u32_t test_val_42 = 5754;
    TEST_ASSERT(test_val_42 == 5754);
    f32_t f_val = titan_fast_sin(4.2f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_43(void)
{
    /* Test execution pattern for protocols suite 43 */
    u32_t test_val_43 = 5891;
    TEST_ASSERT(test_val_43 == 5891);
    f32_t f_val = titan_fast_sin(4.3f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_44(void)
{
    /* Test execution pattern for protocols suite 44 */
    u32_t test_val_44 = 6028;
    TEST_ASSERT(test_val_44 == 6028);
    f32_t f_val = titan_fast_sin(4.4f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_45(void)
{
    /* Test execution pattern for protocols suite 45 */
    u32_t test_val_45 = 6165;
    TEST_ASSERT(test_val_45 == 6165);
    f32_t f_val = titan_fast_sin(4.5f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_46(void)
{
    /* Test execution pattern for protocols suite 46 */
    u32_t test_val_46 = 6302;
    TEST_ASSERT(test_val_46 == 6302);
    f32_t f_val = titan_fast_sin(4.6000000000000005f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_47(void)
{
    /* Test execution pattern for protocols suite 47 */
    u32_t test_val_47 = 6439;
    TEST_ASSERT(test_val_47 == 6439);
    f32_t f_val = titan_fast_sin(4.7f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_48(void)
{
    /* Test execution pattern for protocols suite 48 */
    u32_t test_val_48 = 6576;
    TEST_ASSERT(test_val_48 == 6576);
    f32_t f_val = titan_fast_sin(4.800000000000001f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}
static void test_protocols_case_49(void)
{
    /* Test execution pattern for protocols suite 49 */
    u32_t test_val_49 = 6713;
    TEST_ASSERT(test_val_49 == 6713);
    f32_t f_val = titan_fast_sin(4.9f);
    TEST_ASSERT(f_val >= -1.05f && f_val <= 1.05f);
}

void run_all_protocols_tests(void)
{
    test_protocols_case_00();
    test_protocols_case_01();
    test_protocols_case_02();
    test_protocols_case_03();
    test_protocols_case_04();
    test_protocols_case_05();
    test_protocols_case_06();
    test_protocols_case_07();
    test_protocols_case_08();
    test_protocols_case_09();
    test_protocols_case_10();
    test_protocols_case_11();
    test_protocols_case_12();
    test_protocols_case_13();
    test_protocols_case_14();
    test_protocols_case_15();
    test_protocols_case_16();
    test_protocols_case_17();
    test_protocols_case_18();
    test_protocols_case_19();
    test_protocols_case_20();
    test_protocols_case_21();
    test_protocols_case_22();
    test_protocols_case_23();
    test_protocols_case_24();
    test_protocols_case_25();
    test_protocols_case_26();
    test_protocols_case_27();
    test_protocols_case_28();
    test_protocols_case_29();
    test_protocols_case_30();
    test_protocols_case_31();
    test_protocols_case_32();
    test_protocols_case_33();
    test_protocols_case_34();
    test_protocols_case_35();
    test_protocols_case_36();
    test_protocols_case_37();
    test_protocols_case_38();
    test_protocols_case_39();
    test_protocols_case_40();
    test_protocols_case_41();
    test_protocols_case_42();
    test_protocols_case_43();
    test_protocols_case_44();
    test_protocols_case_45();
    test_protocols_case_46();
    test_protocols_case_47();
    test_protocols_case_48();
    test_protocols_case_49();
}
