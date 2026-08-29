/**
 * @file titan_isotp.h
 * @brief ISO 15765-2 (DoCAN) Transport Layer Multi-Frame Segmentation & Assembly
 */

#ifndef TITAN_ISOTP_H
#define TITAN_ISOTP_H

#include "core/titan_types.h"
#include "core/titan_status.h"
#include "hal/titan_hal_can.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TITAN_ISOTP_MAX_BUF_SIZE 4095

typedef enum {
    TITAN_ISOTP_FRAME_SINGLE       = 0x00,
    TITAN_ISOTP_FRAME_FIRST        = 0x01,
    TITAN_ISOTP_FRAME_CONSECUTIVE  = 0x02,
    TITAN_ISOTP_FRAME_FLOW_CONTROL = 0x03
} titan_isotp_frame_type_t;

typedef struct {
    u32_t           rx_can_id;
    u32_t           tx_can_id;
    u8_t            rx_buffer[TITAN_ISOTP_MAX_BUF_SIZE];
    u16_t           rx_expected_len;
    u16_t           rx_current_len;
    u8_t            rx_seq_num;
    bool_t          rx_in_progress;
} titan_isotp_link_t;

titan_status_t titan_isotp_init(titan_isotp_link_t *link, u32_t rx_id, u32_t tx_id);
titan_status_t titan_isotp_process_can_frame(titan_isotp_link_t *link, const titan_can_msg_t *msg, u8_t **out_payload, u16_t *out_len);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_ISOTP_H */
