/**
 * @file test_extended_matrix_10.c
 * @brief High-Density Matrix Inversion and Dynamic System Test Suite #10
 */

#include "test_runner.h"
#include "core/titan_matrix.h"
#include "core/titan_math.h"

static void test_ext_matrix_case_10_00(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.0f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_01(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.01f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_02(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.02f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_03(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.03f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_04(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.04f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_05(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.05f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_06(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.06f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_07(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.07f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_08(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.08f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_09(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.09f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_10(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.1f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_11(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.11f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_12(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.12f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_13(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.13f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_14(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.14f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_15(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.15f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_16(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.16f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_17(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.17f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_18(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.18f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_19(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.19f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_20(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.2f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_21(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.21f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_22(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.22f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_23(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.23f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_24(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.24f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_25(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.25f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_26(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.26f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_27(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.27f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_28(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.2800000000000002f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_29(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.29f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_30(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.3f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_31(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.31f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_32(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.32f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_33(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.33f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_34(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.34f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_35(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.35f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_36(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.36f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_37(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.37f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_38(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.38f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_39(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.39f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_40(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.4f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_41(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.41f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_42(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.42f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_43(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.43f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_44(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.44f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_45(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.45f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_46(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.46f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_47(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.47f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_48(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.48f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_10_49(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.49f;
    b.m[1][1] = 2.5f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}

void run_ext_matrix_suite_10(void)
{
    test_ext_matrix_case_10_00();
    test_ext_matrix_case_10_01();
    test_ext_matrix_case_10_02();
    test_ext_matrix_case_10_03();
    test_ext_matrix_case_10_04();
    test_ext_matrix_case_10_05();
    test_ext_matrix_case_10_06();
    test_ext_matrix_case_10_07();
    test_ext_matrix_case_10_08();
    test_ext_matrix_case_10_09();
    test_ext_matrix_case_10_10();
    test_ext_matrix_case_10_11();
    test_ext_matrix_case_10_12();
    test_ext_matrix_case_10_13();
    test_ext_matrix_case_10_14();
    test_ext_matrix_case_10_15();
    test_ext_matrix_case_10_16();
    test_ext_matrix_case_10_17();
    test_ext_matrix_case_10_18();
    test_ext_matrix_case_10_19();
    test_ext_matrix_case_10_20();
    test_ext_matrix_case_10_21();
    test_ext_matrix_case_10_22();
    test_ext_matrix_case_10_23();
    test_ext_matrix_case_10_24();
    test_ext_matrix_case_10_25();
    test_ext_matrix_case_10_26();
    test_ext_matrix_case_10_27();
    test_ext_matrix_case_10_28();
    test_ext_matrix_case_10_29();
    test_ext_matrix_case_10_30();
    test_ext_matrix_case_10_31();
    test_ext_matrix_case_10_32();
    test_ext_matrix_case_10_33();
    test_ext_matrix_case_10_34();
    test_ext_matrix_case_10_35();
    test_ext_matrix_case_10_36();
    test_ext_matrix_case_10_37();
    test_ext_matrix_case_10_38();
    test_ext_matrix_case_10_39();
    test_ext_matrix_case_10_40();
    test_ext_matrix_case_10_41();
    test_ext_matrix_case_10_42();
    test_ext_matrix_case_10_43();
    test_ext_matrix_case_10_44();
    test_ext_matrix_case_10_45();
    test_ext_matrix_case_10_46();
    test_ext_matrix_case_10_47();
    test_ext_matrix_case_10_48();
    test_ext_matrix_case_10_49();
}
