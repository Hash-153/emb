/**
 * @file titan_hal_spi.h
 * @brief High-Speed SPI Transaction Queue, Master/Slave State Machine & DMA Controller
 * @version 2.4.0
 * @date 2026-08-29
 */

#ifndef TITAN_HAL_SPI_H
#define TITAN_HAL_SPI_H

#include "core/titan_types.h"
#include "core/titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    TITAN_SPI_1 = 0,
    TITAN_SPI_2,
    TITAN_SPI_3,
    TITAN_SPI_COUNT
} titan_spi_id_t;

typedef enum {
    TITAN_SPI_MODE_0 = 0, /**< CPOL=0, CPHA=0 */
    TITAN_SPI_MODE_1,     /**< CPOL=0, CPHA=1 */
    TITAN_SPI_MODE_2,     /**< CPOL=1, CPHA=0 */
    TITAN_SPI_MODE_3      /**< CPOL=1, CPHA=1 */
} titan_spi_mode_t;

typedef enum {
    TITAN_SPI_BAUD_DIV2   = 0,
    TITAN_SPI_BAUD_DIV4   = 1,
    TITAN_SPI_BAUD_DIV8   = 2,
    TITAN_SPI_BAUD_DIV16  = 3,
    TITAN_SPI_BAUD_DIV32  = 4,
    TITAN_SPI_BAUD_DIV64  = 5,
    TITAN_SPI_BAUD_DIV128 = 6,
    TITAN_SPI_BAUD_DIV256 = 7
} titan_spi_prescaler_t;

typedef struct {
    titan_spi_id_t        id;
    titan_spi_mode_t      mode;
    titan_spi_prescaler_t prescaler;
    bool_t                use_dma;
    bool_t                is_busy;
} titan_spi_handle_t;

titan_status_t titan_hal_spi_init(titan_spi_handle_t *handle, titan_spi_id_t id, titan_spi_mode_t mode, titan_spi_prescaler_t prescaler);
titan_status_t titan_hal_spi_transfer_byte(titan_spi_handle_t *handle, u8_t tx_byte, u8_t *rx_byte);
titan_status_t titan_hal_spi_transfer(titan_spi_handle_t *handle, const u8_t *tx_buf, u8_t *rx_buf, mem_size_t len);
titan_status_t titan_hal_spi_write(titan_spi_handle_t *handle, const u8_t *tx_buf, mem_size_t len);
titan_status_t titan_hal_spi_read(titan_spi_handle_t *handle, u8_t *rx_buf, mem_size_t len, u8_t dummy_byte);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_HAL_SPI_H */
