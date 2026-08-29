/**
 * @file titan_app_telemetry.h
 * @brief High-Rate Periodic Telemetry Streaming & Bandwidth Throttler
 */

#ifndef TITAN_APP_TELEMETRY_H
#define TITAN_APP_TELEMETRY_H

#include "core/titan_types.h"
#include "core/titan_status.h"
#include "hal/titan_hal_uart.h"
#include "protocols/titan_stream_framer.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    u32_t timestamp_ms;
    f32_t roll_deg;
    f32_t pitch_deg;
    f32_t yaw_deg;
    f32_t altitude_m;
    f32_t battery_voltage_v;
    f32_t battery_current_a;
    u8_t  system_state;
    u8_t  fault_flags;
} TITAN_PACKED titan_telemetry_packet_t;

typedef struct {
    titan_uart_handle_t *uart;
    u32_t                packet_sequence;
    u32_t                stream_rate_hz;
    u32_t                packets_transmitted;
} titan_telemetry_streamer_t;

titan_status_t titan_telemetry_init(titan_telemetry_streamer_t *streamer, titan_uart_handle_t *uart, u32_t rate_hz);
titan_status_t titan_telemetry_broadcast(titan_telemetry_streamer_t *streamer, const titan_telemetry_packet_t *pkt);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_APP_TELEMETRY_H */
