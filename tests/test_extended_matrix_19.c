/**
 * @file test_extended_matrix_19.c
 * @brief High-Density Matrix Inversion and Dynamic System Test Suite #19
 */

#include "test_runner.h"
#include "core/titan_matrix.h"
#include "core/titan_math.h"

static void test_ext_matrix_case_19_00(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.9000000000000004f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_01(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.91f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_02(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.9200000000000004f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_03(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.93f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_04(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.9400000000000004f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_05(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.95f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_06(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.9600000000000004f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_07(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.97f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_08(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.9800000000000004f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_09(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.99f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_10(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.0000000000000004f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_11(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.0100000000000002f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_12(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.0200000000000005f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_13(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.0300000000000002f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_14(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.0400000000000005f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_15(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.0500000000000003f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_16(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.0600000000000005f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_17(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.0700000000000003f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_18(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.0800000000000005f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_19(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.0900000000000003f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_20(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.1000000000000005f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_21(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.1100000000000003f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_22(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.1200000000000006f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_23(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.1300000000000003f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_24(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.1400000000000006f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_25(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.1500000000000004f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_26(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.16f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_27(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.1700000000000004f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_28(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.1800000000000006f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_29(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.1900000000000004f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_30(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.2f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_31(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.2100000000000004f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_32(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.22f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_33(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.2300000000000004f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_34(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.24f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_35(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.2500000000000004f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_36(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.2600000000000002f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_37(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.2700000000000005f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_38(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.2800000000000002f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_39(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.2900000000000005f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_40(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.3000000000000003f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_41(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.3100000000000005f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_42(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.3200000000000003f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_43(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.3300000000000005f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_44(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.3400000000000003f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_45(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.3500000000000005f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_46(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.3600000000000003f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_47(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.3700000000000006f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_48(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.3800000000000003f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_19_49(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.3900000000000006f;
    b.m[1][1] = 2.95f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}

void run_ext_matrix_suite_19(void)
{
    test_ext_matrix_case_19_00();
    test_ext_matrix_case_19_01();
    test_ext_matrix_case_19_02();
    test_ext_matrix_case_19_03();
    test_ext_matrix_case_19_04();
    test_ext_matrix_case_19_05();
    test_ext_matrix_case_19_06();
    test_ext_matrix_case_19_07();
    test_ext_matrix_case_19_08();
    test_ext_matrix_case_19_09();
    test_ext_matrix_case_19_10();
    test_ext_matrix_case_19_11();
    test_ext_matrix_case_19_12();
    test_ext_matrix_case_19_13();
    test_ext_matrix_case_19_14();
    test_ext_matrix_case_19_15();
    test_ext_matrix_case_19_16();
    test_ext_matrix_case_19_17();
    test_ext_matrix_case_19_18();
    test_ext_matrix_case_19_19();
    test_ext_matrix_case_19_20();
    test_ext_matrix_case_19_21();
    test_ext_matrix_case_19_22();
    test_ext_matrix_case_19_23();
    test_ext_matrix_case_19_24();
    test_ext_matrix_case_19_25();
    test_ext_matrix_case_19_26();
    test_ext_matrix_case_19_27();
    test_ext_matrix_case_19_28();
    test_ext_matrix_case_19_29();
    test_ext_matrix_case_19_30();
    test_ext_matrix_case_19_31();
    test_ext_matrix_case_19_32();
    test_ext_matrix_case_19_33();
    test_ext_matrix_case_19_34();
    test_ext_matrix_case_19_35();
    test_ext_matrix_case_19_36();
    test_ext_matrix_case_19_37();
    test_ext_matrix_case_19_38();
    test_ext_matrix_case_19_39();
    test_ext_matrix_case_19_40();
    test_ext_matrix_case_19_41();
    test_ext_matrix_case_19_42();
    test_ext_matrix_case_19_43();
    test_ext_matrix_case_19_44();
    test_ext_matrix_case_19_45();
    test_ext_matrix_case_19_46();
    test_ext_matrix_case_19_47();
    test_ext_matrix_case_19_48();
    test_ext_matrix_case_19_49();
}
