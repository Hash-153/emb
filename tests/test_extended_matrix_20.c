/**
 * @file test_extended_matrix_20.c
 * @brief High-Density Matrix Inversion and Dynamic System Test Suite #20
 */

#include "test_runner.h"
#include "core/titan_matrix.h"
#include "core/titan_math.h"

static void test_ext_matrix_case_20_00(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.0f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_01(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.01f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_02(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.02f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_03(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.03f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_04(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.04f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_05(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.05f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_06(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.06f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_07(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.07f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_08(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.08f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_09(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.09f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_10(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.1f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_11(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.11f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_12(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.12f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_13(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.13f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_14(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.14f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_15(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.15f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_16(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.16f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_17(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.17f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_18(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.18f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_19(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.19f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_20(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.2f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_21(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.21f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_22(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.22f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_23(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.23f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_24(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.24f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_25(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.25f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_26(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.26f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_27(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.27f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_28(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.2800000000000002f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_29(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.29f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_30(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.3f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_31(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.31f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_32(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.32f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_33(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.33f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_34(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.34f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_35(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.35f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_36(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.36f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_37(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.37f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_38(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.38f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_39(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.39f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_40(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.4f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_41(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.41f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_42(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.42f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_43(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.43f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_44(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.44f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_45(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.45f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_46(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.46f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_47(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.47f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_48(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.48f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_20_49(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.49f;
    b.m[1][1] = 3.0f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}

void run_ext_matrix_suite_20(void)
{
    test_ext_matrix_case_20_00();
    test_ext_matrix_case_20_01();
    test_ext_matrix_case_20_02();
    test_ext_matrix_case_20_03();
    test_ext_matrix_case_20_04();
    test_ext_matrix_case_20_05();
    test_ext_matrix_case_20_06();
    test_ext_matrix_case_20_07();
    test_ext_matrix_case_20_08();
    test_ext_matrix_case_20_09();
    test_ext_matrix_case_20_10();
    test_ext_matrix_case_20_11();
    test_ext_matrix_case_20_12();
    test_ext_matrix_case_20_13();
    test_ext_matrix_case_20_14();
    test_ext_matrix_case_20_15();
    test_ext_matrix_case_20_16();
    test_ext_matrix_case_20_17();
    test_ext_matrix_case_20_18();
    test_ext_matrix_case_20_19();
    test_ext_matrix_case_20_20();
    test_ext_matrix_case_20_21();
    test_ext_matrix_case_20_22();
    test_ext_matrix_case_20_23();
    test_ext_matrix_case_20_24();
    test_ext_matrix_case_20_25();
    test_ext_matrix_case_20_26();
    test_ext_matrix_case_20_27();
    test_ext_matrix_case_20_28();
    test_ext_matrix_case_20_29();
    test_ext_matrix_case_20_30();
    test_ext_matrix_case_20_31();
    test_ext_matrix_case_20_32();
    test_ext_matrix_case_20_33();
    test_ext_matrix_case_20_34();
    test_ext_matrix_case_20_35();
    test_ext_matrix_case_20_36();
    test_ext_matrix_case_20_37();
    test_ext_matrix_case_20_38();
    test_ext_matrix_case_20_39();
    test_ext_matrix_case_20_40();
    test_ext_matrix_case_20_41();
    test_ext_matrix_case_20_42();
    test_ext_matrix_case_20_43();
    test_ext_matrix_case_20_44();
    test_ext_matrix_case_20_45();
    test_ext_matrix_case_20_46();
    test_ext_matrix_case_20_47();
    test_ext_matrix_case_20_48();
    test_ext_matrix_case_20_49();
}
