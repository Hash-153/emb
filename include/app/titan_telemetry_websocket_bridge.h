/**
 * @file titan_telemetry_websocket_bridge.h
 * @brief High-Rate Telemetry Streamer & COBS Packet Encoding
 */
#ifndef TITAN_TELEMETRY_WEBSOCKET_BRIDGE_H
#define TITAN_TELEMETRY_WEBSOCKET_BRIDGE_H

#include "core/titan_types.h"
#include "core/titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    u32_t sequence_id;
    f32_t pitch_deg;
    f32_t roll_deg;
    f32_t yaw_deg;
    f32_t altitude_m;
    f32_t battery_voltage_v;
    u32_t timestamp_ms;
} titan_telemetry_packet_t;

titan_status_t titan_telemetry_encode_packet(const titan_telemetry_packet_t *pkt, u8_t *out_buf, mem_size_t *out_len);
titan_status_t titan_telemetry_decode_packet(const u8_t *in_buf, mem_size_t in_len, titan_telemetry_packet_t *pkt);

#ifdef __cplusplus
}
#endif
#endif
