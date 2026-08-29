/**
 * @file titan_mission_planner.c
 * @brief Geodetic Waypoint Navigation, Cubic Spline Smoothing and Flight Corridors
 */

#include "app/titan_mission_planner.h"
#include "core/titan_math.h"
#include <string.h>

#define EARTH_RADIUS_METERS (6371000.0)

titan_status_t titan_mission_init(titan_mission_plan_t *plan)
{
    if (!plan) return TITAN_ERROR_NULL_POINTER;
    memset(plan, 0, sizeof(titan_mission_plan_t));
    return TITAN_OK;
}

titan_status_t titan_mission_add_waypoint(titan_mission_plan_t *plan, const titan_waypoint_t *wp)
{
    if (!plan || !wp) return TITAN_ERROR_NULL_POINTER;
    if (plan->count >= TITAN_MAX_MISSION_WAYPOINTS) return TITAN_ERROR_BUFFER_FULL;
    plan->waypoints[plan->count++] = *wp;
    return TITAN_OK;
}

titan_status_t titan_mission_start(titan_mission_plan_t *plan)
{
    if (!plan || plan->count == 0) return TITAN_ERROR_INVALID_ARGUMENT;
    plan->active_index = 0;
    plan->mission_active = TRUE;
    return TITAN_OK;
}

titan_status_t titan_mission_get_active_target(const titan_mission_plan_t *plan, titan_waypoint_t *wp)
{
    if (!plan || !wp || !plan->mission_active) return TITAN_ERROR_INVALID_ARGUMENT;
    *wp = plan->waypoints[plan->active_index];
    return TITAN_OK;
}

f64_t titan_mission_haversine_distance_m(f64_t lat1, f64_t lon1, f64_t lat2, f64_t lon2)
{
    f64_t dlat = (lat2 - lat1) * (3.141592653589793 / 180.0);
    f64_t dlon = (lon2 - lon1) * (3.141592653589793 / 180.0);
    f64_t a = sin(dlat * 0.5) * sin(dlat * 0.5) +
              cos(lat1 * (3.141592653589793 / 180.0)) * cos(lat2 * (3.141592653589793 / 180.0)) *
              sin(dlon * 0.5) * sin(dlon * 0.5);
    f64_t c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));
    return EARTH_RADIUS_METERS * c;
}
