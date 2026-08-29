/**
 * @file titan_status.c
 * @brief Status Code Text Decoder and Diagnostic String Lookups
 */

#include "titan_status.h"

const char *titan_status_str(titan_status_t status)
{
    switch (status) {
        case TITAN_OK:                        return "TITAN_OK: Operation completed successfully";
        case TITAN_ERROR_GENERIC:             return "TITAN_ERROR_GENERIC: Generic failure";
        case TITAN_ERROR_NULL_POINTER:        return "TITAN_ERROR_NULL_POINTER: Null pointer dereference prevented";
        case TITAN_ERROR_INVALID_ARGUMENT:    return "TITAN_ERROR_INVALID_ARGUMENT: Argument out of bounds or invalid";
        case TITAN_ERROR_OUT_OF_BOUNDS:       return "TITAN_ERROR_OUT_OF_BOUNDS: Index or boundary overrun";
        case TITAN_ERROR_BUFFER_FULL:         return "TITAN_ERROR_BUFFER_FULL: Ring buffer or queue is full";
        case TITAN_ERROR_BUFFER_EMPTY:        return "TITAN_ERROR_BUFFER_EMPTY: No data available in buffer";
        case TITAN_ERROR_BUSY:                return "TITAN_ERROR_BUSY: Resource is locked or in active transaction";
        case TITAN_ERROR_TIMEOUT:             return "TITAN_ERROR_TIMEOUT: Hardware or scheduler timeout";
        case TITAN_ERROR_NOT_INITIALIZED:     return "TITAN_ERROR_NOT_INITIALIZED: Module has not been initialized";
        case TITAN_ERROR_ALREADY_INITIALIZED: return "TITAN_ERROR_ALREADY_INITIALIZED: Module already initialized";
        case TITAN_ERROR_NOT_SUPPORTED:       return "TITAN_ERROR_NOT_SUPPORTED: Requested mode is unsupported";
        case TITAN_ERROR_RESOURCE_EXHAUSTED:  return "TITAN_ERROR_RESOURCE_EXHAUSTED: System memory/pool exhausted";
        case TITAN_ERROR_CHECKSUM_MISMATCH:   return "TITAN_ERROR_CHECKSUM_MISMATCH: Checksum/CRC verification failed";
        case TITAN_ERROR_CORRUPTED:           return "TITAN_ERROR_CORRUPTED: Data structure integrity compromised";
        case TITAN_ERROR_PERMISSION_DENIED:   return "TITAN_ERROR_PERMISSION_DENIED: Security clearance denied";

        case TITAN_KERNEL_ERR_TASK_CREATE:    return "TITAN_KERNEL_ERR_TASK_CREATE: Task stack/TCB allocation failed";
        case TITAN_KERNEL_ERR_SCHED_LOCKED:   return "TITAN_KERNEL_ERR_SCHED_LOCKED: Attempted blocking in locked context";
        case TITAN_KERNEL_ERR_STACK_OVERFLOW: return "TITAN_KERNEL_ERR_STACK_OVERFLOW: Stack canary corruption detected";
        case TITAN_KERNEL_ERR_MUTEX_DEADLOCK: return "TITAN_KERNEL_ERR_MUTEX_DEADLOCK: Priority inversion or deadlock avoided";
        case TITAN_KERNEL_ERR_QUEUE_SEND:     return "TITAN_KERNEL_ERR_QUEUE_SEND: Queue enqueue failure";
        case TITAN_KERNEL_ERR_QUEUE_RECV:     return "TITAN_KERNEL_ERR_QUEUE_RECV: Queue dequeue failure";
        case TITAN_KERNEL_ERR_ISR_CONTEXT:    return "TITAN_KERNEL_ERR_ISR_CONTEXT: Illegal call from interrupt handler";
        case TITAN_KERNEL_ERR_HEAP_ALLOC:     return "TITAN_KERNEL_ERR_HEAP_ALLOC: Heap memory allocation failure";

        case TITAN_HAL_ERR_GPIO_CONFIG:       return "TITAN_HAL_ERR_GPIO_CONFIG: Pin configuration rejected";
        case TITAN_HAL_ERR_CLOCK_UNLOCK:      return "TITAN_HAL_ERR_CLOCK_UNLOCK: PLL or main oscillator unlock";
        case TITAN_HAL_ERR_UART_PARITY:       return "TITAN_HAL_ERR_UART_PARITY: Parity error on UART bus";
        case TITAN_HAL_ERR_UART_FRAMING:      return "TITAN_HAL_ERR_UART_FRAMING: Framing error on UART bus";
        case TITAN_HAL_ERR_UART_OVERRUN:      return "TITAN_HAL_ERR_UART_OVERRUN: Receiver hardware FIFO overrun";
        case TITAN_HAL_ERR_SPI_TX_FAULT:      return "TITAN_HAL_ERR_SPI_TX_FAULT: SPI bus transmit fault";
        case TITAN_HAL_ERR_I2C_NACK:          return "TITAN_HAL_ERR_I2C_NACK: I2C slave returned NACK";
        case TITAN_HAL_ERR_I2C_BUS_ARBITR:    return "TITAN_HAL_ERR_I2C_BUS_ARBITR: I2C multi-master arbitration lost";
        case TITAN_HAL_ERR_CAN_BUS_OFF:       return "TITAN_HAL_ERR_CAN_BUS_OFF: CAN controller entered bus-off state";
        case TITAN_HAL_ERR_CAN_PASSIVE:       return "TITAN_HAL_ERR_CAN_PASSIVE: CAN error count reached error passive";
        case TITAN_HAL_ERR_ADC_CONVERSION:    return "TITAN_HAL_ERR_ADC_CONVERSION: ADC sampling timeout";
        case TITAN_HAL_ERR_FLASH_LOCKED:      return "TITAN_HAL_ERR_FLASH_LOCKED: Flash sector write-protected";
        case TITAN_HAL_ERR_DMA_TRANSFER:      return "TITAN_HAL_ERR_DMA_TRANSFER: DMA stream transfer error";

        case TITAN_DRV_ERR_DEVICE_ID_MISMATCH:return "TITAN_DRV_ERR_DEVICE_ID_MISMATCH: Chip ID register verification failed";
        case TITAN_DRV_ERR_CALIBRATION:       return "TITAN_DRV_ERR_CALIBRATION: Sensor offset calibration out of bounds";
        case TITAN_DRV_ERR_FIFO_OVERFLOW:     return "TITAN_DRV_ERR_FIFO_OVERFLOW: Sensor FIFO watermark overflow";
        case TITAN_DRV_ERR_SATURATION:        return "TITAN_DRV_ERR_SATURATION: Sensor measurement ADC saturated";
        case TITAN_DRV_ERR_COMM_LOST:         return "TITAN_DRV_ERR_COMM_LOST: Device unresponsive";

        case TITAN_PROTO_ERR_FRAME_INVALID:   return "TITAN_PROTO_ERR_FRAME_INVALID: Malformed packet header";
        case TITAN_PROTO_ERR_CRC_FAIL:        return "TITAN_PROTO_ERR_CRC_FAIL: Frame payload CRC mismatch";
        case TITAN_PROTO_ERR_LEN_MISMATCH:    return "TITAN_PROTO_ERR_LEN_MISMATCH: Payload length does not match header";
        case TITAN_PROTO_ERR_SEQ_NUMBER:      return "TITAN_PROTO_ERR_SEQ_NUMBER: Packet sequence drop or discontinuity";
        case TITAN_PROTO_ERR_SUBINDEX_NA:     return "TITAN_PROTO_ERR_SUBINDEX_NA: CANopen/UDS index unavailable";
        case TITAN_PROTO_ERR_SECURITY_LOCKED: return "TITAN_PROTO_ERR_SECURITY_LOCKED: Seed-Key authentication required";

        case TITAN_STORAGE_ERR_WEAR_LIMIT:    return "TITAN_STORAGE_ERR_WEAR_LIMIT: Flash erase cycle count exceeded threshold";
        case TITAN_STORAGE_ERR_BAD_BLOCK:     return "TITAN_STORAGE_ERR_BAD_BLOCK: Memory block marked bad";
        case TITAN_STORAGE_ERR_JOURNAL_FULL:  return "TITAN_STORAGE_ERR_JOURNAL_FULL: NVRAM transaction journal saturated";
        case TITAN_STORAGE_ERR_KV_NOT_FOUND:  return "TITAN_STORAGE_ERR_KV_NOT_FOUND: Key not found in configuration store";

        case TITAN_SAFETY_ERR_RAM_TEST_FAIL:  return "TITAN_SAFETY_ERR_RAM_TEST_FAIL: March C- memory diagnostic failed";
        case TITAN_SAFETY_ERR_FLASH_ECC:      return "TITAN_SAFETY_ERR_FLASH_ECC: Flash uncorrectable multi-bit ECC error";
        case TITAN_SAFETY_ERR_CPU_REG_FAIL:   return "TITAN_SAFETY_ERR_CPU_REG_FAIL: Core register test verification failed";
        case TITAN_SAFETY_ERR_CLOCK_DRIFT:    return "TITAN_SAFETY_ERR_CLOCK_DRIFT: Oscillator frequency drifted outside tolerance";
        case TITAN_SAFETY_ERR_2OO3_DISAGREE:  return "TITAN_SAFETY_ERR_2OO3_DISAGREE: Triple modular redundancy voter disagreement";
        case TITAN_SAFETY_ERR_WATCHDOG_RESET: return "TITAN_SAFETY_ERR_WATCHDOG_RESET: Previous reboot caused by watchdog expiry";

        default:                              return "TITAN_STATUS_UNKNOWN: Unrecognized status code";
    }
}
