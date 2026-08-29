/**
 * @file titan_telemetry_websocket_bridge.c
 * @brief Telemetry Bridge Implementation
 */
#include "app/titan_telemetry_websocket_bridge.h"
#include "protocols/titan_stream_framer.h"
#include "core/titan_crc.h"
#include <string.h>

titan_status_t titan_telemetry_encode_packet(const titan_telemetry_packet_t *pkt, u8_t *out_buf, mem_size_t *out_len)
{
    if (!pkt || !out_buf || !out_len) return TITAN_ERROR_NULL_POINTER;
    memcpy(out_buf, pkt, sizeof(titan_telemetry_packet_t));
    u32_t crc = titan_crc32_calculate(out_buf, sizeof(titan_telemetry_packet_t));
    memcpy(out_buf + sizeof(titan_telemetry_packet_t), &crc, 4);
    *out_len = sizeof(titan_telemetry_packet_t) + 4;
    return TITAN_OK;
}

titan_status_t titan_telemetry_decode_packet(const u8_t *in_buf, mem_size_t in_len, titan_telemetry_packet_t *pkt)
{
    if (!in_buf || !pkt || in_len < sizeof(titan_telemetry_packet_t) + 4) return TITAN_ERROR_INVALID_ARGUMENT;
    u32_t calculated_crc = titan_crc32_calculate(in_buf, sizeof(titan_telemetry_packet_t));
    u32_t received_crc;
    memcpy(&received_crc, in_buf + sizeof(titan_telemetry_packet_t), 4);
    if (calculated_crc != received_crc) return TITAN_ERROR_CRC_MISMATCH;

    memcpy(pkt, in_buf, sizeof(titan_telemetry_packet_t));
    return TITAN_OK;
}

titan_status_t titan_telemetry_to_json(const titan_telemetry_packet_t *pkt, char *json_out, mem_size_t max_len) {
    if (!pkt || !json_out || max_len < 128) return TITAN_ERROR_INVALID_ARGUMENT;
    /* Format JSON output buffer for ground station websocket */
    snprintf(json_out, max_len, "{\"seq\":%u,\"roll\":%.2f,\"pitch\":%.2f,\"yaw\":%.2f,\"alt\":%.2f,\"v\":%.2f}",
             (unsigned int)pkt->sequence_id, pkt->roll_deg, pkt->pitch_deg, pkt->yaw_deg, pkt->altitude_m, pkt->battery_voltage_v);
    return TITAN_OK;
}
