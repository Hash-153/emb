/**
 * @file titan_cli_shell.c
 * @brief Interactive Line Parser and Command Dispatcher
 */

#include "app/titan_cli_shell.h"
#include "core/titan_string.h"
#include <stdio.h>
#include <string.h>

titan_status_t titan_cli_init(titan_cli_t *cli, titan_uart_handle_t *uart, const titan_cli_cmd_entry_t *cmds, u16_t count)
{
    if (!cli || !cmds) return TITAN_ERROR_NULL_POINTER;
    cli->uart = uart;
    cli->cmd_table = cmds;
    cli->cmd_count = count;
    cli->line_len = 0;
    return TITAN_OK;
}

static void titan_cli_execute_line(titan_cli_t *cli)
{
    if (cli->line_len == 0) return;

    char *argv[TITAN_CLI_MAX_ARGS];
    int argc = 0;

    char *token = strtok(cli->line_buffer, " ");
    while (token && argc < TITAN_CLI_MAX_ARGS) {
        argv[argc++] = token;
        token = strtok(NULL_PTR, " ");
    }

    if (argc == 0) return;

    for (u16_t i = 0; i < cli->cmd_count; ++i) {
        if (titan_strcmp(cli->cmd_table[i].name, argv[0]) == 0) {
            cli->cmd_table[i].func(argc, argv);
            return;
        }
    }
    printf("Unknown command: %s. Type 'help' for listing.\n", argv[0]);
}

void titan_cli_process(titan_cli_t *cli)
{
    if (!cli || !cli->uart) return;

    u8_t ch;
    while (titan_hal_uart_read(cli->uart, &ch, 1) > 0) {
        if (ch == '\r' || ch == '\n') {
            cli->line_buffer[cli->line_len] = '\0';
            printf("\r\n");
            titan_cli_execute_line(cli);
            cli->line_len = 0;
            printf("titan> ");
        } else if (ch == '\b' || ch == 0x7F) {
            if (cli->line_len > 0) {
                cli->line_len--;
                printf("\b \b");
            }
        } else if (cli->line_len < TITAN_CLI_LINE_MAX - 1) {
            cli->line_buffer[cli->line_len++] = (char)ch;
            printf("%c", ch);
        }
    }
}
