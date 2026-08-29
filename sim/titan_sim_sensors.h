/**
 * @file titan_sim_sensors.h
 * @brief Synthetic 6-DOF Aircraft / Spacecraft Physics & Atmospheric Sensor Simulator
 */

#ifndef TITAN_SIM_SENSORS_H
#define TITAN_SIM_SENSORS_H

#include "core/titan_types.h"
#include "core/titan_math.h"
#include "drivers/titan_drv_imu_6dof.h"
#include "drivers/titan_drv_baro.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    titan_vec3_t position_ned_m;
    titan_vec3_t velocity_ned_mps;
    titan_euler_t attitude_rad;
    titan_vec3_t angular_velocity_radps;
    f32_t        wind_speed_mps;
    f32_t        ambient_temp_c;
} titan_sim_physics_state_t;

void titan_sim_physics_init(void);
void titan_sim_physics_step(f32_t dt);
void titan_sim_get_imu_sample(titan_imu_sample_t *sample);
void titan_sim_get_baro_sample(titan_baro_data_t *baro);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_SIM_SENSORS_H */
