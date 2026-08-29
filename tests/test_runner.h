/**
 * @file test_runner.h
 * @brief Zero-Dependency Embedded Unit Testing Framework
 */

#ifndef TEST_RUNNER_H
#define TEST_RUNNER_H

#include "core/titan_types.h"
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    u32_t tests_run;
    u32_t tests_passed;
    u32_t tests_failed;
} test_context_t;

extern test_context_t g_test_ctx;

#define TEST_INIT() do { g_test_ctx.tests_run = 0; g_test_ctx.tests_passed = 0; g_test_ctx.tests_failed = 0; } while(0)

#define TEST_ASSERT(expr) do { \
    g_test_ctx.tests_run++; \
    if (expr) { \
        g_test_ctx.tests_passed++; \
    } else { \
        g_test_ctx.tests_failed++; \
        printf("  [FAIL] %s:%d: Assertion '%s' failed.\n", __FILE__, __LINE__, #expr); \
    } \
} while(0)

#define TEST_RUN_SUITE(suite_name, func) do { \
    printf("\n>>> Running Suite: %s\n", suite_name); \
    func(); \
} while(0)

#ifdef __cplusplus
}
#endif

#endif /* TEST_RUNNER_H */
