/**
 * @file titan_cli_shell.h
 * @brief VT100 Serial Interactive Terminal Shell with Line Editing & History
 */

#ifndef TITAN_CLI_SHELL_H
#define TITAN_CLI_SHELL_H

#include "core/titan_types.h"
#include "core/titan_status.h"
#include "hal/titan_hal_uart.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TITAN_CLI_LINE_MAX 128
#define TITAN_CLI_MAX_ARGS 8

typedef titan_status_t (*titan_cli_cmd_func_t)(int argc, char **argv);

typedef struct {
    const char           *name;
    const char           *help;
    titan_cli_cmd_func_t  func;
} titan_cli_cmd_entry_t;

typedef struct {
    titan_uart_handle_t         *uart;
    const titan_cli_cmd_entry_t *cmd_table;
    u16_t                        cmd_count;
    char                         line_buffer[TITAN_CLI_LINE_MAX];
    u16_t                        line_len;
} titan_cli_t;

titan_status_t titan_cli_init(titan_cli_t *cli, titan_uart_handle_t *uart, const titan_cli_cmd_entry_t *cmds, u16_t count);
void           titan_cli_process(titan_cli_t *cli);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_CLI_SHELL_H */
