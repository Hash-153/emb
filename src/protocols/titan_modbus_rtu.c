/**
 * @file titan_modbus_rtu.c
 * @brief Modbus RTU CRC16 Verification and Function Code Dispatch
 */

#include "protocols/titan_modbus_rtu.h"
#include "core/titan_crc.h"
#include <string.h>

titan_status_t titan_modbus_init(titan_modbus_server_t *srv, u8_t slave_addr, u16_t *holding, u16_t h_count, u16_t *inputs, u16_t i_count)
{
    if (!srv) return TITAN_ERROR_NULL_POINTER;
    srv->slave_address = slave_addr;
    srv->holding_regs = holding;
    srv->holding_reg_count = h_count;
    srv->input_regs = inputs;
    srv->input_reg_count = i_count;
    return TITAN_OK;
}

titan_status_t titan_modbus_process_frame(titan_modbus_server_t *srv, const u8_t *req, mem_size_t req_len, u8_t *resp, mem_size_t *resp_len)
{
    if (!srv || !req || !resp || !resp_len || req_len < 4) {
        return TITAN_ERROR_INVALID_ARGUMENT;
    }

    /* Check CRC16 */
    u16_t calc_crc = titan_crc16_modbus(req, req_len - 2);
    u16_t frame_crc = (u16_t)req[req_len - 2] | ((u16_t)req[req_len - 1] << 8);
    if (calc_crc != frame_crc) {
        return TITAN_PROTO_ERR_CRC_FAIL;
    }

    /* Check Address */
    if (req[0] != srv->slave_address && req[0] != 0) {
        return TITAN_OK; /* Not for this node */
    }

    u8_t fc = req[1];
    resp[0] = srv->slave_address;
    resp[1] = fc;

    switch (fc) {
        case TITAN_MODBUS_FC_READ_HOLDING_REGISTERS: {
            u16_t start_addr = ((u16_t)req[2] << 8) | req[3];
            u16_t reg_count  = ((u16_t)req[4] << 8) | req[5];
            if (start_addr + reg_count > srv->holding_reg_count) {
                resp[1] = fc | 0x80;
                resp[2] = 0x02; /* Illegal Data Address */
                *resp_len = 3;
                break;
            }
            resp[2] = (u8_t)(reg_count * 2);
            for (u16_t i = 0; i < reg_count; ++i) {
                u16_t val = srv->holding_regs[start_addr + i];
                resp[3 + i * 2] = (u8_t)(val >> 8);
                resp[4 + i * 2] = (u8_t)(val & 0xFF);
            }
            *resp_len = 3 + reg_count * 2;
            break;
        }
        case TITAN_MODBUS_FC_WRITE_SINGLE_REGISTER: {
            u16_t reg_addr = ((u16_t)req[2] << 8) | req[3];
            u16_t reg_val  = ((u16_t)req[4] << 8) | req[5];
            if (reg_addr >= srv->holding_reg_count) {
                resp[1] = fc | 0x80;
                resp[2] = 0x02;
                *resp_len = 3;
                break;
            }
            srv->holding_regs[reg_addr] = reg_val;
            memcpy(&resp[2], &req[2], 4);
            *resp_len = 6;
            break;
        }
        default:
            resp[1] = fc | 0x80;
            resp[2] = 0x01; /* Illegal Function Code */
            *resp_len = 3;
            break;
    }

    /* Append response CRC */
    u16_t resp_crc = titan_crc16_modbus(resp, *resp_len);
    resp[*resp_len] = (u8_t)(resp_crc & 0xFF);
    resp[*resp_len + 1] = (u8_t)(resp_crc >> 8);
    *resp_len += 2;

    return TITAN_OK;
}
