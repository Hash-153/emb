/**
 * @file titan_app_telemetry.c
 * @brief COBS Frame Packaging and Serial Streaming Implementation
 */

#include "app/titan_app_telemetry.h"
#include <string.h>

titan_status_t titan_telemetry_init(titan_telemetry_streamer_t *streamer, titan_uart_handle_t *uart, u32_t rate_hz)
{
    if (!streamer || !uart || rate_hz == 0) return TITAN_ERROR_INVALID_ARGUMENT;
    streamer->uart = uart;
    streamer->packet_sequence = 0;
    streamer->stream_rate_hz = rate_hz;
    streamer->packets_transmitted = 0;
    return TITAN_OK;
}

titan_status_t titan_telemetry_broadcast(titan_telemetry_streamer_t *streamer, const titan_telemetry_packet_t *pkt)
{
    if (!streamer || !pkt) return TITAN_ERROR_NULL_POINTER;

    u8_t raw_frame[128];
    mem_size_t raw_len = 0;
    titan_frame_pack_telemetry(0x0101, streamer->packet_sequence++, (const u8_t *)pkt, sizeof(titan_telemetry_packet_t), raw_frame, &raw_len);

    u8_t cobs_frame[160];
    mem_size_t encoded_len = titan_cobs_encode(raw_frame, raw_len, cobs_frame);
    cobs_frame[encoded_len++] = 0x00; /* Delimiter byte */

    titan_hal_uart_write(streamer->uart, cobs_frame, encoded_len);
    streamer->packets_transmitted++;

    return TITAN_OK;
}
