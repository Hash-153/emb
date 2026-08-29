/**
 * @file test_extended_matrix_03.c
 * @brief High-Density Matrix Inversion and Dynamic System Test Suite #03
 */

#include "test_runner.h"
#include "core/titan_matrix.h"
#include "core/titan_math.h"

static void test_ext_matrix_case_03_00(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.3f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_01(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.31f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_02(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.32f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_03(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.33f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_04(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.34f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_05(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.35f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_06(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.36f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_07(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.37f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_08(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.3800000000000001f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_09(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.3900000000000001f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_10(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.4000000000000001f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_11(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.4100000000000001f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_12(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.42f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_13(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.4300000000000002f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_14(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.44f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_15(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.45f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_16(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.46f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_17(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.47f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_18(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.48f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_19(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.49f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_20(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.5f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_21(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.51f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_22(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.52f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_23(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.53f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_24(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.54f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_25(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.55f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_26(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.56f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_27(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.57f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_28(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.58f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_29(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.59f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_30(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.6f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_31(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.61f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_32(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.62f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_33(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.6300000000000001f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_34(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.6400000000000001f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_35(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.6500000000000001f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_36(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.6600000000000001f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_37(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.67f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_38(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.6800000000000002f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_39(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.69f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_40(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.7000000000000002f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_41(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.71f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_42(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.72f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_43(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.73f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_44(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.74f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_45(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.75f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_46(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.76f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_47(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.77f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_48(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.78f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_03_49(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 1.79f;
    b.m[1][1] = 2.15f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}

void run_ext_matrix_suite_03(void)
{
    test_ext_matrix_case_03_00();
    test_ext_matrix_case_03_01();
    test_ext_matrix_case_03_02();
    test_ext_matrix_case_03_03();
    test_ext_matrix_case_03_04();
    test_ext_matrix_case_03_05();
    test_ext_matrix_case_03_06();
    test_ext_matrix_case_03_07();
    test_ext_matrix_case_03_08();
    test_ext_matrix_case_03_09();
    test_ext_matrix_case_03_10();
    test_ext_matrix_case_03_11();
    test_ext_matrix_case_03_12();
    test_ext_matrix_case_03_13();
    test_ext_matrix_case_03_14();
    test_ext_matrix_case_03_15();
    test_ext_matrix_case_03_16();
    test_ext_matrix_case_03_17();
    test_ext_matrix_case_03_18();
    test_ext_matrix_case_03_19();
    test_ext_matrix_case_03_20();
    test_ext_matrix_case_03_21();
    test_ext_matrix_case_03_22();
    test_ext_matrix_case_03_23();
    test_ext_matrix_case_03_24();
    test_ext_matrix_case_03_25();
    test_ext_matrix_case_03_26();
    test_ext_matrix_case_03_27();
    test_ext_matrix_case_03_28();
    test_ext_matrix_case_03_29();
    test_ext_matrix_case_03_30();
    test_ext_matrix_case_03_31();
    test_ext_matrix_case_03_32();
    test_ext_matrix_case_03_33();
    test_ext_matrix_case_03_34();
    test_ext_matrix_case_03_35();
    test_ext_matrix_case_03_36();
    test_ext_matrix_case_03_37();
    test_ext_matrix_case_03_38();
    test_ext_matrix_case_03_39();
    test_ext_matrix_case_03_40();
    test_ext_matrix_case_03_41();
    test_ext_matrix_case_03_42();
    test_ext_matrix_case_03_43();
    test_ext_matrix_case_03_44();
    test_ext_matrix_case_03_45();
    test_ext_matrix_case_03_46();
    test_ext_matrix_case_03_47();
    test_ext_matrix_case_03_48();
    test_ext_matrix_case_03_49();
}
