/**
 * @file titan_stream_framer.h
 * @brief Consistent Overhead Byte Stuffing (COBS) & Frame Delimiting Engine
 */

#ifndef TITAN_STREAM_FRAMER_H
#define TITAN_STREAM_FRAMER_H

#include "core/titan_types.h"
#include "core/titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

mem_size_t titan_cobs_encode(const u8_t *src, mem_size_t src_len, u8_t *dst);
mem_size_t titan_cobs_decode(const u8_t *src, mem_size_t src_len, u8_t *dst);

typedef struct {
    u16_t sync_marker;
    u16_t packet_id;
    u32_t sequence;
    u32_t payload_len;
    u32_t crc32;
} TITAN_PACKED titan_telemetry_hdr_t;

titan_status_t titan_frame_pack_telemetry(u16_t pkt_id, u32_t seq, const u8_t *payload, mem_size_t len, u8_t *out_frame, mem_size_t *out_len);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_STREAM_FRAMER_H */
