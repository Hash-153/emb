/**
 * @file titan_hal_uart.h
 * @brief High-Throughput Double-Buffered DMA UART Driver
 */

#ifndef TITAN_HAL_UART_H
#define TITAN_HAL_UART_H

#include "core/titan_types.h"
#include "core/titan_status.h"
#include "core/titan_circular_buffer.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    TITAN_UART_1 = 0,
    TITAN_UART_2,
    TITAN_UART_3,
    TITAN_UART_COUNT
} titan_uart_id_t;

typedef enum {
    TITAN_UART_BAUD_9600   = 9600,
    TITAN_UART_BAUD_19200  = 19200,
    TITAN_UART_BAUD_38400  = 38400,
    TITAN_UART_BAUD_57600  = 57600,
    TITAN_UART_BAUD_115200 = 115200,
    TITAN_UART_BAUD_921600 = 921600
} titan_uart_baud_t;

typedef struct {
    titan_uart_id_t     uart_id;
    titan_uart_baud_t   baudrate;
    u8_t               *rx_storage;
    mem_size_t          rx_capacity;
    u8_t               *tx_storage;
    mem_size_t          tx_capacity;
} titan_uart_config_t;

typedef struct {
    titan_uart_id_t     id;
    titan_cbuf_t        rx_cbuf;
    titan_cbuf_t        tx_cbuf;
    volatile bool_t     is_tx_busy;
} titan_uart_handle_t;

titan_status_t titan_hal_uart_init(titan_uart_handle_t *handle, const titan_uart_config_t *cfg);
titan_status_t titan_hal_uart_send_byte(titan_uart_handle_t *handle, u8_t byte);
mem_size_t     titan_hal_uart_write(titan_uart_handle_t *handle, const u8_t *data, mem_size_t len);
mem_size_t     titan_hal_uart_read(titan_uart_handle_t *handle, u8_t *dest, mem_size_t len);
void           titan_hal_uart_rx_isr(titan_uart_handle_t *handle, u8_t received_byte);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_HAL_UART_H */
