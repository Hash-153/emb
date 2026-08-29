/**
 * @file titan_mission_planner.h
 * @brief Autonomous Waypoint Navigation & Geodesic Trajectory Engine
 */

#ifndef TITAN_MISSION_PLANNER_H
#define TITAN_MISSION_PLANNER_H

#include "core/titan_types.h"
#include "core/titan_status.h"
#include "core/titan_math.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    TITAN_WP_NAV_TAKEOFF = 0,
    TITAN_WP_NAV_FLY_TO,
    TITAN_WP_NAV_ORBIT,
    TITAN_WP_NAV_SURVEY_GRID,
    TITAN_WP_NAV_RTH,
    TITAN_WP_NAV_LAND
} titan_wp_action_t;

typedef struct {
    u16_t             id;
    f64_t             latitude_deg;
    f64_t             longitude_deg;
    f32_t             altitude_msl_m;
    f32_t             acceptance_radius_m;
    f32_t             cruise_speed_mps;
    titan_wp_action_t action;
} titan_waypoint_t;

#define TITAN_MAX_MISSION_WAYPOINTS 600

typedef struct {
    titan_waypoint_t waypoints[TITAN_MAX_MISSION_WAYPOINTS];
    u16_t            count;
    u16_t            active_index;
    bool_t           mission_active;
} titan_mission_plan_t;

titan_status_t titan_mission_init(titan_mission_plan_t *plan);
titan_status_t titan_mission_add_waypoint(titan_mission_plan_t *plan, const titan_waypoint_t *wp);
titan_status_t titan_mission_start(titan_mission_plan_t *plan);
titan_status_t titan_mission_get_active_target(const titan_mission_plan_t *plan, titan_waypoint_t *wp);
f64_t          titan_mission_haversine_distance_m(f64_t lat1, f64_t lon1, f64_t lat2, f64_t lon2);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_MISSION_PLANNER_H */
