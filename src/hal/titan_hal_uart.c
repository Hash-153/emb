/**
 * @file titan_hal_uart.c
 * @brief Circular Buffer and DMA Transfer Emulation for Serial Communications
 */

#include "hal/titan_hal_uart.h"
#include <stdio.h>

titan_status_t titan_hal_uart_init(titan_uart_handle_t *handle, const titan_uart_config_t *cfg)
{
    if (!handle || !cfg || !cfg->rx_storage || !cfg->tx_storage) {
        return TITAN_ERROR_INVALID_ARGUMENT;
    }
    handle->id = cfg->uart_id;
    handle->is_tx_busy = FALSE;

    titan_cbuf_init(&handle->rx_cbuf, cfg->rx_storage, cfg->rx_capacity, TRUE);
    titan_cbuf_init(&handle->tx_cbuf, cfg->tx_storage, cfg->tx_capacity, FALSE);

    return TITAN_OK;
}

titan_status_t titan_hal_uart_send_byte(titan_uart_handle_t *handle, u8_t byte)
{
    if (!handle) return TITAN_ERROR_NULL_POINTER;
    return titan_cbuf_put(&handle->tx_cbuf, byte);
}

mem_size_t titan_hal_uart_write(titan_uart_handle_t *handle, const u8_t *data, mem_size_t len)
{
    if (!handle || !data) return 0;
    return titan_cbuf_write(&handle->tx_cbuf, data, len);
}

mem_size_t titan_hal_uart_read(titan_uart_handle_t *handle, u8_t *dest, mem_size_t len)
{
    if (!handle || !dest) return 0;
    return titan_cbuf_read(&handle->rx_cbuf, dest, len);
}

void titan_hal_uart_rx_isr(titan_uart_handle_t *handle, u8_t received_byte)
{
    if (handle) {
        titan_cbuf_put(&handle->rx_cbuf, received_byte);
    }
}
