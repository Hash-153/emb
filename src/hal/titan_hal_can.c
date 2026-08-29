/**
 * @file titan_hal_can.c
 * @brief CAN Arbitration Mailbox and Filter Bank Driver
 */

#include "hal/titan_hal_can.h"
#include <string.h>

#define CAN_MSG_QUEUE_SIZE 32

typedef struct {
    titan_can_msg_t queue[CAN_MSG_QUEUE_SIZE];
    u32_t head;
    u32_t tail;
    u32_t count;
    titan_can_filter_t filters[14];
} titan_can_internal_t;

static titan_can_internal_t s_can_dev[TITAN_CAN_COUNT];

titan_status_t titan_hal_can_init(titan_can_id_t can_id, u32_t baudrate_kbps)
{
    if (can_id >= TITAN_CAN_COUNT) return TITAN_ERROR_INVALID_ARGUMENT;
    TITAN_UNUSED_PARAM(baudrate_kbps);

    memset(&s_can_dev[can_id], 0, sizeof(titan_can_internal_t));
    return TITAN_OK;
}

titan_status_t titan_hal_can_transmit(titan_can_id_t can_id, const titan_can_msg_t *msg)
{
    if (can_id >= TITAN_CAN_COUNT || !msg) return TITAN_ERROR_INVALID_ARGUMENT;
    titan_can_internal_t *dev = &s_can_dev[can_id];

    if (dev->count >= CAN_MSG_QUEUE_SIZE) return TITAN_ERROR_BUFFER_FULL;

    dev->queue[dev->head] = *msg;
    dev->head = (dev->head + 1) % CAN_MSG_QUEUE_SIZE;
    dev->count++;

    return TITAN_OK;
}

titan_status_t titan_hal_can_receive(titan_can_id_t can_id, titan_can_msg_t *msg)
{
    if (can_id >= TITAN_CAN_COUNT || !msg) return TITAN_ERROR_INVALID_ARGUMENT;
    titan_can_internal_t *dev = &s_can_dev[can_id];

    if (dev->count == 0) return TITAN_ERROR_BUFFER_EMPTY;

    *msg = dev->queue[dev->tail];
    dev->tail = (dev->tail + 1) % CAN_MSG_QUEUE_SIZE;
    dev->count--;

    return TITAN_OK;
}

titan_status_t titan_hal_can_set_filter(titan_can_id_t can_id, u8_t filter_idx, const titan_can_filter_t *filter)
{
    if (can_id >= TITAN_CAN_COUNT || filter_idx >= 14 || !filter) return TITAN_ERROR_INVALID_ARGUMENT;
    s_can_dev[can_id].filters[filter_idx] = *filter;
    return TITAN_OK;
}
