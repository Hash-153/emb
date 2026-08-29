/**
 * @file titan_mission_trajectory_opt.h
 * @brief Geodesic Trajectory Optimizer & Dubins Curve Waypoint Path Generation
 */
#ifndef TITAN_MISSION_TRAJECTORY_OPT_H
#define TITAN_MISSION_TRAJECTORY_OPT_H

#include "core/titan_types.h"
#include "core/titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    f64_t lat_start_deg;
    f64_t lon_start_deg;
    f64_t lat_end_deg;
    f64_t lon_end_deg;
    f32_t turn_radius_m;
    f32_t cruise_speed_mps;
    f32_t estimated_flight_time_s;
} titan_trajectory_segment_t;

titan_status_t titan_trajectory_calc_segment(titan_trajectory_segment_t *seg);
f32_t          titan_trajectory_get_crosstrack_error(f64_t cur_lat, f64_t cur_lon, const titan_trajectory_segment_t *seg);

#ifdef __cplusplus
}
#endif
#endif
