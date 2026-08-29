/**
 * @file titan_canopen_sdo.c
 * @brief SDO Client/Server Message Demultiplexing & Abort Code Generator
 */

#include "protocols/titan_canopen_sdo.h"
#include <string.h>

titan_status_t titan_sdo_server_init(titan_sdo_server_t *sdo, titan_canopen_od_t *od, u8_t node_id)
{
    if (!sdo || !od || node_id == 0 || node_id > 127) return TITAN_ERROR_INVALID_ARGUMENT;
    sdo->od = od;
    sdo->node_id = node_id;
    sdo->rx_cob_id = 0x600 + node_id;
    sdo->tx_cob_id = 0x580 + node_id;
    sdo->state = TITAN_SDO_STATE_IDLE;
    sdo->toggle_bit = 0;
    return TITAN_OK;
}

titan_status_t titan_sdo_process_frame(titan_sdo_server_t *sdo, const titan_can_msg_t *rx_msg, titan_can_msg_t *tx_msg)
{
    if (!sdo || !rx_msg || !tx_msg) return TITAN_ERROR_NULL_POINTER;
    if (rx_msg->id != sdo->rx_cob_id) return TITAN_OK;

    u8_t ccs = rx_msg->data[0] >> 5;
    u16_t index = (u16_t)rx_msg->data[1] | ((u16_t)rx_msg->data[2] << 8);
    u8_t subindex = rx_msg->data[3];

    tx_msg->id = sdo->tx_cob_id;
    tx_msg->ide = TITAN_CAN_ID_STD;
    tx_msg->rtr = TITAN_CAN_FRAME_DATA;
    tx_msg->dlc = 8;
    memset(tx_msg->data, 0, 8);

    if (ccs == 2) { /* Initiate Upload (Read) */
        u32_t val = 0;
        mem_size_t act_len = 0;
        titan_status_t st = titan_od_read(sdo->od, index, subindex, &val, sizeof(val), &act_len);

        if (st == TITAN_OK) {
            tx_msg->data[0] = 0x43 | ((4 - (u8_t)act_len) << 2); /* Expedited transfer */
            tx_msg->data[1] = (u8_t)(index & 0xFF);
            tx_msg->data[2] = (u8_t)(index >> 8);
            tx_msg->data[3] = subindex;
            memcpy(&tx_msg->data[4], &val, 4);
        } else {
            tx_msg->data[0] = 0x80; /* Abort */
            tx_msg->data[1] = (u8_t)(index & 0xFF);
            tx_msg->data[2] = (u8_t)(index >> 8);
            tx_msg->data[3] = subindex;
            tx_msg->data[4] = 0x11; /* Object does not exist */
            tx_msg->data[5] = 0x00;
            tx_msg->data[6] = 0x09;
            tx_msg->data[7] = 0x06;
        }
        return TITAN_OK;
    }

    return TITAN_OK;
}
