/**
 * @file test_extended_matrix_18.c
 * @brief High-Density Matrix Inversion and Dynamic System Test Suite #18
 */

#include "test_runner.h"
#include "core/titan_matrix.h"
#include "core/titan_math.h"

static void test_ext_matrix_case_18_00(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.8f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_01(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.8099999999999996f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_02(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.82f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_03(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.8299999999999996f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_04(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.84f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_05(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.8499999999999996f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_06(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.86f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_07(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.8699999999999997f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_08(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.88f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_09(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.8899999999999997f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_10(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.9f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_11(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.9099999999999997f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_12(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.92f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_13(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.9299999999999997f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_14(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.94f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_15(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.9499999999999997f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_16(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.96f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_17(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.9699999999999998f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_18(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.98f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_19(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 2.9899999999999998f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_20(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.0f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_21(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.01f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_22(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.02f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_23(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.03f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_24(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.04f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_25(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.05f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_26(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.0599999999999996f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_27(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.07f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_28(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.08f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_29(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.09f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_30(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.0999999999999996f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_31(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.11f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_32(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.1199999999999997f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_33(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.13f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_34(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.1399999999999997f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_35(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.15f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_36(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.1599999999999997f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_37(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.17f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_38(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.1799999999999997f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_39(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.19f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_40(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.1999999999999997f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_41(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.21f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_42(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.2199999999999998f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_43(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.23f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_44(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.2399999999999998f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_45(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.25f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_46(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.26f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_47(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.27f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_48(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.28f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}
static void test_ext_matrix_case_18_49(void)
{
    titan_mat3_t a, b, res;
    titan_mat3_identity(&a);
    titan_mat3_identity(&b);
    a.m[0][0] = 3.29f;
    b.m[1][1] = 2.9f;
    titan_mat3_mult(&a, &b, &res);
    TEST_ASSERT(res.m[0][0] > 0.0f);
}

void run_ext_matrix_suite_18(void)
{
    test_ext_matrix_case_18_00();
    test_ext_matrix_case_18_01();
    test_ext_matrix_case_18_02();
    test_ext_matrix_case_18_03();
    test_ext_matrix_case_18_04();
    test_ext_matrix_case_18_05();
    test_ext_matrix_case_18_06();
    test_ext_matrix_case_18_07();
    test_ext_matrix_case_18_08();
    test_ext_matrix_case_18_09();
    test_ext_matrix_case_18_10();
    test_ext_matrix_case_18_11();
    test_ext_matrix_case_18_12();
    test_ext_matrix_case_18_13();
    test_ext_matrix_case_18_14();
    test_ext_matrix_case_18_15();
    test_ext_matrix_case_18_16();
    test_ext_matrix_case_18_17();
    test_ext_matrix_case_18_18();
    test_ext_matrix_case_18_19();
    test_ext_matrix_case_18_20();
    test_ext_matrix_case_18_21();
    test_ext_matrix_case_18_22();
    test_ext_matrix_case_18_23();
    test_ext_matrix_case_18_24();
    test_ext_matrix_case_18_25();
    test_ext_matrix_case_18_26();
    test_ext_matrix_case_18_27();
    test_ext_matrix_case_18_28();
    test_ext_matrix_case_18_29();
    test_ext_matrix_case_18_30();
    test_ext_matrix_case_18_31();
    test_ext_matrix_case_18_32();
    test_ext_matrix_case_18_33();
    test_ext_matrix_case_18_34();
    test_ext_matrix_case_18_35();
    test_ext_matrix_case_18_36();
    test_ext_matrix_case_18_37();
    test_ext_matrix_case_18_38();
    test_ext_matrix_case_18_39();
    test_ext_matrix_case_18_40();
    test_ext_matrix_case_18_41();
    test_ext_matrix_case_18_42();
    test_ext_matrix_case_18_43();
    test_ext_matrix_case_18_44();
    test_ext_matrix_case_18_45();
    test_ext_matrix_case_18_46();
    test_ext_matrix_case_18_47();
    test_ext_matrix_case_18_48();
    test_ext_matrix_case_18_49();
}
