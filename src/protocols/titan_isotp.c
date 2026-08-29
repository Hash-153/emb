/**
 * @file titan_isotp.c
 * @brief ISO-TP Consecutive Frame Reassembly & Flow Control Engine
 */

#include "protocols/titan_isotp.h"
#include <string.h>

titan_status_t titan_isotp_init(titan_isotp_link_t *link, u32_t rx_id, u32_t tx_id)
{
    if (!link) return TITAN_ERROR_NULL_POINTER;
    memset(link, 0, sizeof(titan_isotp_link_t));
    link->rx_can_id = rx_id;
    link->tx_can_id = tx_id;
    return TITAN_OK;
}

titan_status_t titan_isotp_process_can_frame(titan_isotp_link_t *link, const titan_can_msg_t *msg, u8_t **out_payload, u16_t *out_len)
{
    if (!link || !msg || !out_payload || !out_len) return TITAN_ERROR_NULL_POINTER;
    if (msg->id != link->rx_can_id) return TITAN_OK;

    u8_t pci = msg->data[0] >> 4;

    switch (pci) {
        case TITAN_ISOTP_FRAME_SINGLE: {
            u8_t len = msg->data[0] & 0x0F;
            if (len == 0 || len > 7) return TITAN_PROTO_ERR_FRAME_INVALID;
            memcpy(link->rx_buffer, &msg->data[1], len);
            *out_payload = link->rx_buffer;
            *out_len = len;
            return TITAN_OK;
        }
        case TITAN_ISOTP_FRAME_FIRST: {
            link->rx_expected_len = (((u16_t)(msg->data[0] & 0x0F)) << 8) | msg->data[1];
            if (link->rx_expected_len > TITAN_ISOTP_MAX_BUF_SIZE) return TITAN_ERROR_OUT_OF_BOUNDS;
            memcpy(link->rx_buffer, &msg->data[2], 6);
            link->rx_current_len = 6;
            link->rx_seq_num = 1;
            link->rx_in_progress = TRUE;
            return TITAN_OK;
        }
        case TITAN_ISOTP_FRAME_CONSECUTIVE: {
            if (!link->rx_in_progress) return TITAN_OK;
            u8_t seq = msg->data[0] & 0x0F;
            if (seq != (link->rx_seq_num & 0x0F)) {
                link->rx_in_progress = FALSE;
                return TITAN_PROTO_ERR_SEQ_NUMBER;
            }
            link->rx_seq_num++;

            u16_t remain = link->rx_expected_len - link->rx_current_len;
            u16_t chunk = (remain > 7) ? 7 : remain;
            memcpy(&link->rx_buffer[link->rx_current_len], &msg->data[1], chunk);
            link->rx_current_len += chunk;

            if (link->rx_current_len >= link->rx_expected_len) {
                link->rx_in_progress = FALSE;
                *out_payload = link->rx_buffer;
                *out_len = link->rx_expected_len;
            }
            return TITAN_OK;
        }
        default:
            break;
    }

    return TITAN_OK;
}
