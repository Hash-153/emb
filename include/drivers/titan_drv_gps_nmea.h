/**
 * @file titan_drv_gps_nmea.h
 * @brief NMEA 0183 (GGA, RMC, GSA) GNSS Sentence Parser & Geodetic Converter
 */

#ifndef TITAN_DRV_GPS_NMEA_H
#define TITAN_DRV_GPS_NMEA_H

#include "core/titan_types.h"
#include "core/titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    TITAN_GPS_FIX_NONE = 0,
    TITAN_GPS_FIX_2D   = 1,
    TITAN_GPS_FIX_3D   = 2,
    TITAN_GPS_FIX_DGPS = 3,
    TITAN_GPS_FIX_RTK  = 4
} titan_gps_fix_t;

typedef struct {
    f64_t           latitude_deg;
    f64_t           longitude_deg;
    f32_t           altitude_msl_m;
    f32_t           speed_knots;
    f32_t           course_deg;
    f32_t           hdop;
    u8_t            satellites_tracked;
    titan_gps_fix_t fix_quality;
    u32_t           utc_time_hhmmss;
    u32_t           utc_date_ddmmyy;
    bool_t          valid;
} titan_gps_nav_data_t;

typedef struct {
    char                 sentence_buf[128];
    u16_t                buf_idx;
    titan_gps_nav_data_t current_nav;
    u32_t                valid_sentences;
    u32_t                crc_errors;
} titan_drv_gps_t;

titan_status_t titan_gps_init(titan_drv_gps_t *gps);
titan_status_t titan_gps_parse_char(titan_drv_gps_t *gps, char c);
titan_status_t titan_gps_parse_sentence(titan_drv_gps_t *gps, const char *sentence);
bool_t         titan_gps_get_nav_data(const titan_drv_gps_t *gps, titan_gps_nav_data_t *nav);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_DRV_GPS_NMEA_H */
