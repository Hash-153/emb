/**
 * @file titan_hal_can.h
 * @brief Controller Area Network (CAN 2.0B & CAN-FD) Mailbox & Filter Engine
 */

#ifndef TITAN_HAL_CAN_H
#define TITAN_HAL_CAN_H

#include "core/titan_types.h"
#include "core/titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    TITAN_CAN_1 = 0,
    TITAN_CAN_2,
    TITAN_CAN_COUNT
} titan_can_id_t;

typedef enum {
    TITAN_CAN_ID_STD = 0,   /**< 11-bit standard identifier */
    TITAN_CAN_ID_EXT = 1    /**< 29-bit extended identifier */
} titan_can_ide_t;

typedef enum {
    TITAN_CAN_FRAME_DATA   = 0,
    TITAN_CAN_FRAME_REMOTE = 1
} titan_can_rtr_t;

typedef struct {
    u32_t           id;         /**< Arbitration Identifier */
    titan_can_ide_t ide;        /**< Standard / Extended */
    titan_can_rtr_t rtr;        /**< Data / Remote Request */
    u8_t            dlc;        /**< Payload length (0..8 for 2.0B, up to 64 for FD) */
    u8_t            data[8];    /**< Payload bytes */
    titan_time_us_t timestamp;  /**< Capture hardware timestamp */
} titan_can_msg_t;

typedef struct {
    u32_t filter_id;
    u32_t filter_mask;
    u8_t  fifo_assignment;
    bool_t is_active;
} titan_can_filter_t;

titan_status_t titan_hal_can_init(titan_can_id_t can_id, u32_t baudrate_kbps);
titan_status_t titan_hal_can_transmit(titan_can_id_t can_id, const titan_can_msg_t *msg);
titan_status_t titan_hal_can_receive(titan_can_id_t can_id, titan_can_msg_t *msg);
titan_status_t titan_hal_can_set_filter(titan_can_id_t can_id, u8_t filter_idx, const titan_can_filter_t *filter);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_HAL_CAN_H */
