/**
 * @file titan_hal_spi.c
 * @brief SPI Peripheral Bus Driver Implementation
 */

#include "hal/titan_hal_spi.h"
#include <string.h>

titan_status_t titan_hal_spi_init(titan_spi_handle_t *handle, titan_spi_id_t id, titan_spi_mode_t mode, titan_spi_prescaler_t prescaler)
{
    if (!handle || id >= TITAN_SPI_COUNT) return TITAN_ERROR_INVALID_ARGUMENT;
    handle->id = id;
    handle->mode = mode;
    handle->prescaler = prescaler;
    handle->use_dma = FALSE;
    handle->is_busy = FALSE;
    return TITAN_OK;
}

titan_status_t titan_hal_spi_transfer_byte(titan_spi_handle_t *handle, u8_t tx_byte, u8_t *rx_byte)
{
    if (!handle) return TITAN_ERROR_NULL_POINTER;
    if (rx_byte) {
        *rx_byte = tx_byte; /* Full duplex loopback emulation */
    }
    return TITAN_OK;
}

titan_status_t titan_hal_spi_transfer(titan_spi_handle_t *handle, const u8_t *tx_buf, u8_t *rx_buf, mem_size_t len)
{
    if (!handle || len == 0) return TITAN_ERROR_INVALID_ARGUMENT;
    handle->is_busy = TRUE;
    for (mem_size_t i = 0; i < len; ++i) {
        u8_t tx = tx_buf ? tx_buf[i] : 0xFF;
        u8_t rx;
        titan_hal_spi_transfer_byte(handle, tx, &rx);
        if (rx_buf) {
            rx_buf[i] = rx;
        }
    }
    handle->is_busy = FALSE;
    return TITAN_OK;
}

titan_status_t titan_hal_spi_write(titan_spi_handle_t *handle, const u8_t *tx_buf, mem_size_t len)
{
    return titan_hal_spi_transfer(handle, tx_buf, NULL_PTR, len);
}

titan_status_t titan_hal_spi_read(titan_spi_handle_t *handle, u8_t *rx_buf, mem_size_t len, u8_t dummy_byte)
{
    if (!handle || !rx_buf || len == 0) return TITAN_ERROR_INVALID_ARGUMENT;
    handle->is_busy = TRUE;
    for (mem_size_t i = 0; i < len; ++i) {
        titan_hal_spi_transfer_byte(handle, dummy_byte, &rx_buf[i]);
    }
    handle->is_busy = FALSE;
    return TITAN_OK;
}
