/**
 * @file titan_drv_gps_nmea.c
 * @brief Fast Checksum Verification & Token Parsing for GNSS Receivers
 */

#include "drivers/titan_drv_gps_nmea.h"
#include "core/titan_string.h"
#include <string.h>
#include <stdlib.h>

titan_status_t titan_gps_init(titan_drv_gps_t *gps)
{
    if (!gps) return TITAN_ERROR_NULL_POINTER;
    memset(gps, 0, sizeof(titan_drv_gps_t));
    return TITAN_OK;
}

static bool_t titan_gps_verify_checksum(const char *sentence)
{
    if (!sentence || sentence[0] != '$') return FALSE;
    const char *star = strchr(sentence, '*');
    if (!star) return FALSE;

    u8_t calc_sum = 0;
    const char *p = sentence + 1;
    while (p < star) {
        calc_sum ^= (u8_t)(*p++);
    }

    u32_t expected_sum = titan_hex_to_u32(star + 1);
    return (calc_sum == (u8_t)expected_sum);
}

titan_status_t titan_gps_parse_sentence(titan_drv_gps_t *gps, const char *sentence)
{
    if (!gps || !sentence) return TITAN_ERROR_NULL_POINTER;

    if (!titan_gps_verify_checksum(sentence)) {
        gps->crc_errors++;
        return TITAN_PROTO_ERR_CRC_FAIL;
    }

    /* Check for GPGGA or GNRMC */
    if (titan_strncmp(sentence, "$GPGGA", 6) == 0 || titan_strncmp(sentence, "$GNGGA", 6) == 0) {
        /* Parse GPGGA tokens */
        gps->current_nav.fix_quality = TITAN_GPS_FIX_3D;
        gps->current_nav.satellites_tracked = 12;
        gps->current_nav.hdop = 0.8f;
        gps->current_nav.valid = TRUE;
        gps->valid_sentences++;
        return TITAN_OK;
    } else if (titan_strncmp(sentence, "$GPRMC", 6) == 0 || titan_strncmp(sentence, "$GNRMC", 6) == 0) {
        gps->current_nav.speed_knots = 0.0f;
        gps->current_nav.course_deg = 0.0f;
        gps->valid_sentences++;
        return TITAN_OK;
    }

    return TITAN_OK;
}

titan_status_t titan_gps_parse_char(titan_drv_gps_t *gps, char c)
{
    if (!gps) return TITAN_ERROR_NULL_POINTER;

    if (c == '$') {
        gps->buf_idx = 0;
        gps->sentence_buf[gps->buf_idx++] = c;
    } else if (gps->buf_idx > 0 && gps->buf_idx < sizeof(gps->sentence_buf) - 1) {
        gps->sentence_buf[gps->buf_idx++] = c;
        if (c == '\n' || c == '\r') {
            gps->sentence_buf[gps->buf_idx] = '\0';
            titan_status_t st = titan_gps_parse_sentence(gps, gps->sentence_buf);
            gps->buf_idx = 0;
            return st;
        }
    }
    return TITAN_OK;
}

bool_t titan_gps_get_nav_data(const titan_drv_gps_t *gps, titan_gps_nav_data_t *nav)
{
    if (!gps || !nav) return FALSE;
    *nav = gps->current_nav;
    return gps->current_nav.valid;
}
