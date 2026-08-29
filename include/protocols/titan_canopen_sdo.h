/**
 * @file titan_canopen_sdo.h
 * @brief CANopen Service Data Object (SDO) Server Protocol Engine
 */

#ifndef TITAN_CANOPEN_SDO_H
#define TITAN_CANOPEN_SDO_H

#include "protocols/titan_canopen_od.h"
#include "hal/titan_hal_can.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    TITAN_SDO_STATE_IDLE = 0,
    TITAN_SDO_STATE_SEGMENTED_UPLOAD,
    TITAN_SDO_STATE_SEGMENTED_DOWNLOAD
} titan_sdo_state_t;

typedef struct {
    titan_canopen_od_t *od;
    u8_t                node_id;
    u32_t               rx_cob_id;
    u32_t               tx_cob_id;
    titan_sdo_state_t   state;
    u16_t               active_index;
    u8_t                active_subindex;
    u8_t                toggle_bit;
} titan_sdo_server_t;

titan_status_t titan_sdo_server_init(titan_sdo_server_t *sdo, titan_canopen_od_t *od, u8_t node_id);
titan_status_t titan_sdo_process_frame(titan_sdo_server_t *sdo, const titan_can_msg_t *rx_msg, titan_can_msg_t *tx_msg);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_CANOPEN_SDO_H */
