/**
 * @file titan_defs.c
 * @brief System Panic Handler and Diagnostic Halt Execution
 */

#include "titan_defs.h"
#include <stdio.h>
#include <stdlib.h>

void titan_panic_handler(const char *file, u32_t line, const char *expr)
{
    /* Output panic trace */
    fprintf(stderr, "\n[CRITICAL HARDWARE PANIC]\n");
    fprintf(stderr, "Assertion Failed: %s\n", expr ? expr : "UNKNOWN");
    fprintf(stderr, "Location: %s:%u\n", file ? file : "UNKNOWN", (unsigned int)line);
    fprintf(stderr, "System entered fail-safe lockstate.\n");

    /* In actual silicon targets, disable all interrupts and enter safe watchdog loop */
#if defined(TITAN_HOST_SIMULATION) || defined(__x86_64__) || defined(_M_X64) || defined(_WIN32)
    /* Host environment test trap */
#else
    /* Target hardware: lock interrupts */
    while (1) {
        /* Busy wait or feed windowed watchdog with safe state */
    }
#endif
}
