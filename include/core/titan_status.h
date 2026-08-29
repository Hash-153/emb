/**
 * @file titan_status.h
 * @brief System-Wide Status Codes, Error Classification, and Diagnostic Identifiers
 * @version 2.4.0
 * @date 2026-08-29
 */

#ifndef TITAN_STATUS_H
#define TITAN_STATUS_H

#include "titan_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @enum titan_status_t
 * @brief Universal error code return type for all subsystem APIs
 */
typedef enum {
    /* Generic Codes (0x0000 - 0x00FF) */
    TITAN_OK                        = 0x0000,   /**< Operation successful */
    TITAN_ERROR_GENERIC             = 0x0001,   /**< Unspecified generic failure */
    TITAN_ERROR_NULL_POINTER        = 0x0002,   /**< Null pointer passed to API */
    TITAN_ERROR_INVALID_ARGUMENT    = 0x0003,   /**< Parameter outside valid domain */
    TITAN_ERROR_OUT_OF_BOUNDS       = 0x0004,   /**< Index or range overflow */
    TITAN_ERROR_BUFFER_FULL         = 0x0005,   /**< Capacity reached */
    TITAN_ERROR_BUFFER_EMPTY        = 0x0006,   /**< No data available */
    TITAN_ERROR_BUSY                = 0x0007,   /**< Resource locked or active */
    TITAN_ERROR_TIMEOUT             = 0x0008,   /**< Operation timed out */
    TITAN_ERROR_NOT_INITIALIZED     = 0x0009,   /**< Subsystem uninitialized */
    TITAN_ERROR_ALREADY_INITIALIZED = 0x000A,   /**< Subsystem already active */
    TITAN_ERROR_NOT_SUPPORTED       = 0x000B,   /**< Feature not supported */
    TITAN_ERROR_RESOURCE_EXHAUSTED  = 0x000C,   /**< Heap, queue or pool full */
    TITAN_ERROR_CHECKSUM_MISMATCH   = 0x000D,   /**< Integrity verification failed */
    TITAN_ERROR_CORRUPTED           = 0x000E,   /**< Corrupted data structure detected */
    TITAN_ERROR_PERMISSION_DENIED   = 0x000F,   /**< Access level insufficient */

    /* Kernel / RTOS Codes (0x0100 - 0x01FF) */
    TITAN_KERNEL_ERR_TASK_CREATE    = 0x0100,
    TITAN_KERNEL_ERR_SCHED_LOCKED   = 0x0101,
    TITAN_KERNEL_ERR_STACK_OVERFLOW = 0x0102,
    TITAN_KERNEL_ERR_MUTEX_DEADLOCK = 0x0103,
    TITAN_KERNEL_ERR_QUEUE_SEND     = 0x0104,
    TITAN_KERNEL_ERR_QUEUE_RECV     = 0x0105,
    TITAN_KERNEL_ERR_ISR_CONTEXT    = 0x0106,
    TITAN_KERNEL_ERR_HEAP_ALLOC     = 0x0107,

    /* Hardware Abstraction Codes (0x0200 - 0x02FF) */
    TITAN_HAL_ERR_GPIO_CONFIG       = 0x0200,
    TITAN_HAL_ERR_CLOCK_UNLOCK      = 0x0201,
    TITAN_HAL_ERR_UART_PARITY       = 0x0202,
    TITAN_HAL_ERR_UART_FRAMING      = 0x0203,
    TITAN_HAL_ERR_UART_OVERRUN      = 0x0204,
    TITAN_HAL_ERR_SPI_TX_FAULT      = 0x0205,
    TITAN_HAL_ERR_I2C_NACK          = 0x0206,
    TITAN_HAL_ERR_I2C_BUS_ARBITR    = 0x0207,
    TITAN_HAL_ERR_CAN_BUS_OFF       = 0x0208,
    TITAN_HAL_ERR_CAN_PASSIVE       = 0x0209,
    TITAN_HAL_ERR_ADC_CONVERSION    = 0x020A,
    TITAN_HAL_ERR_FLASH_LOCKED      = 0x020B,
    TITAN_HAL_ERR_DMA_TRANSFER      = 0x020C,

    /* Driver Codes (0x0300 - 0x03FF) */
    TITAN_DRV_ERR_DEVICE_ID_MISMATCH= 0x0300,
    TITAN_DRV_ERR_CALIBRATION       = 0x0301,
    TITAN_DRV_ERR_FIFO_OVERFLOW     = 0x0302,
    TITAN_DRV_ERR_SATURATION        = 0x0303,
    TITAN_DRV_ERR_COMM_LOST         = 0x0304,

    /* Protocol Codes (0x0400 - 0x04FF) */
    TITAN_PROTO_ERR_FRAME_INVALID   = 0x0400,
    TITAN_PROTO_ERR_CRC_FAIL        = 0x0401,
    TITAN_PROTO_ERR_LEN_MISMATCH    = 0x0402,
    TITAN_PROTO_ERR_SEQ_NUMBER      = 0x0403,
    TITAN_PROTO_ERR_SUBINDEX_NA     = 0x0404,
    TITAN_PROTO_ERR_SECURITY_LOCKED = 0x0405,

    /* Storage Codes (0x0500 - 0x05FF) */
    TITAN_STORAGE_ERR_WEAR_LIMIT    = 0x0500,
    TITAN_STORAGE_ERR_BAD_BLOCK     = 0x0501,
    TITAN_STORAGE_ERR_JOURNAL_FULL  = 0x0502,
    TITAN_STORAGE_ERR_KV_NOT_FOUND  = 0x0503,

    /* Safety & BIST Codes (0x0600 - 0x06FF) */
    TITAN_SAFETY_ERR_RAM_TEST_FAIL  = 0x0600,
    TITAN_SAFETY_ERR_FLASH_ECC      = 0x0601,
    TITAN_SAFETY_ERR_CPU_REG_FAIL   = 0x0602,
    TITAN_SAFETY_ERR_CLOCK_DRIFT    = 0x0603,
    TITAN_SAFETY_ERR_2OO3_DISAGREE  = 0x0604,
    TITAN_SAFETY_ERR_WATCHDOG_RESET = 0x0605
} titan_status_t;

/**
 * @brief Convert status code to human readable string
 * @param status Status enum value
 * @return Constant character pointer containing description
 */
const char *titan_status_str(titan_status_t status);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_STATUS_H */
