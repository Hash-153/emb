/**
 * @file titan_modbus_rtu.h
 * @brief Industrial Modbus RTU Slave/Master Protocol Stack
 */

#ifndef TITAN_MODBUS_RTU_H
#define TITAN_MODBUS_RTU_H

#include "core/titan_types.h"
#include "core/titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TITAN_MODBUS_MAX_ADU_LEN 256

typedef enum {
    TITAN_MODBUS_FC_READ_COILS               = 0x01,
    TITAN_MODBUS_FC_READ_DISCRETE_INPUTS     = 0x02,
    TITAN_MODBUS_FC_READ_HOLDING_REGISTERS   = 0x03,
    TITAN_MODBUS_FC_READ_INPUT_REGISTERS     = 0x04,
    TITAN_MODBUS_FC_WRITE_SINGLE_COIL        = 0x05,
    TITAN_MODBUS_FC_WRITE_SINGLE_REGISTER    = 0x06,
    TITAN_MODBUS_FC_WRITE_MULTIPLE_REGISTERS = 0x10
} titan_modbus_fc_t;

typedef struct {
    u8_t   slave_address;
    u16_t *holding_regs;
    u16_t  holding_reg_count;
    u16_t *input_regs;
    u16_t  input_reg_count;
} titan_modbus_server_t;

titan_status_t titan_modbus_init(titan_modbus_server_t *srv, u8_t slave_addr, u16_t *holding, u16_t h_count, u16_t *inputs, u16_t i_count);
titan_status_t titan_modbus_process_frame(titan_modbus_server_t *srv, const u8_t *req, mem_size_t req_len, u8_t *resp, mem_size_t *resp_len);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_MODBUS_RTU_H */
