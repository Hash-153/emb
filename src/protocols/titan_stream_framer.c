/**
 * @file titan_stream_framer.c
 * @brief Zero-Delimiter Packet Encoding with Checksum Encapsulation
 */

#include "protocols/titan_stream_framer.h"
#include "core/titan_crc.h"
#include <string.h>

mem_size_t titan_cobs_encode(const u8_t *src, mem_size_t src_len, u8_t *dst)
{
    if (!src || !dst || src_len == 0) return 0;
    const u8_t *src_end = src + src_len;
    u8_t *dst_start = dst;
    u8_t *code_ptr = dst++;
    u8_t code = 0x01;

    while (src < src_end) {
        if (*src == 0) {
            *code_ptr = code;
            code_ptr = dst++;
            code = 0x01;
            src++;
        } else {
            *dst++ = *src++;
            code++;
            if (code == 0xFF) {
                *code_ptr = code;
                code_ptr = dst++;
                code = 0x01;
            }
        }
    }
    *code_ptr = code;
    return (mem_size_t)(dst - dst_start);
}

mem_size_t titan_cobs_decode(const u8_t *src, mem_size_t src_len, u8_t *dst)
{
    if (!src || !dst || src_len == 0) return 0;
    const u8_t *src_end = src + src_len;
    u8_t *dst_start = dst;

    while (src < src_end) {
        u8_t code = *src++;
        if (code == 0) return 0; /* Unexpected zero */
        for (u8_t i = 1; i < code; ++i) {
            if (src >= src_end) return 0;
            *dst++ = *src++;
        }
        if (code < 0xFF && src < src_end) {
            *dst++ = 0;
        }
    }
    return (mem_size_t)(dst - dst_start);
}

titan_status_t titan_frame_pack_telemetry(u16_t pkt_id, u32_t seq, const u8_t *payload, mem_size_t len, u8_t *out_frame, mem_size_t *out_len)
{
    if (!out_frame || !out_len) return TITAN_ERROR_NULL_POINTER;

    titan_telemetry_hdr_t hdr;
    hdr.sync_marker = 0xAA55;
    hdr.packet_id = pkt_id;
    hdr.sequence = seq;
    hdr.payload_len = (u32_t)len;
    hdr.crc32 = titan_crc32_calc(payload, len, 0xFFFFFFFF);

    memcpy(out_frame, &hdr, sizeof(titan_telemetry_hdr_t));
    if (payload && len > 0) {
        memcpy(out_frame + sizeof(titan_telemetry_hdr_t), payload, len);
    }
    *out_len = sizeof(titan_telemetry_hdr_t) + len;
    return TITAN_OK;
}
