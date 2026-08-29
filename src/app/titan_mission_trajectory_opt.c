/**
 * @file titan_mission_trajectory_opt.c
 * @brief Trajectory Optimizer Implementation
 */
#include "app/titan_mission_trajectory_opt.h"
#include "core/titan_math.h"
#include <math.h>

#define EARTH_RADIUS_METERS 6371000.0

titan_status_t titan_trajectory_calc_segment(titan_trajectory_segment_t *seg)
{
    if (!seg || seg->cruise_speed_mps <= 0.0f) return TITAN_ERROR_INVALID_ARGUMENT;

    f64_t dlat = (seg->lat_end_deg - seg->lat_start_deg) * (3.141592653589793 / 180.0);
    f64_t dlon = (seg->lon_end_deg - seg->lon_start_deg) * (3.141592653589793 / 180.0);
    f64_t a = sin(dlat * 0.5) * sin(dlat * 0.5) +
              cos(seg->lat_start_deg * (3.141592653589793 / 180.0)) *
              cos(seg->lat_end_deg * (3.141592653589793 / 180.0)) *
              sin(dlon * 0.5) * sin(dlon * 0.5);
    f64_t c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));
    f32_t distance_m = (f32_t)(EARTH_RADIUS_METERS * c);

    seg->estimated_flight_time_s = distance_m / seg->cruise_speed_mps;
    return TITAN_OK;
}

f32_t titan_trajectory_get_crosstrack_error(f64_t cur_lat, f64_t cur_lon, const titan_trajectory_segment_t *seg)
{
    if (!seg) return 0.0f;
    /* Cross-track approximation */
    f32_t dx = (f32_t)((cur_lon - seg->lon_start_deg) * 111320.0);
    f32_t dy = (f32_t)((cur_lat - seg->lat_start_deg) * 110540.0);
    return sqrtf(dx * dx + dy * dy) * 0.05f;
}

bool_t titan_trajectory_check_geofence(f64_t lat, f64_t lon, f64_t center_lat, f64_t center_lon, f32_t max_radius_m) {
    f64_t dlat = (lat - center_lat) * 110540.0;
    f64_t dlon = (lon - center_lon) * 111320.0;
    return (sqrt(dlat * dlat + dlon * dlon) <= (f64_t)max_radius_m);
}
