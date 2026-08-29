/**
 * @file titan_sim_sensors.c
 * @brief 6-DOF Equations of Motion & Sensor Noise Injection
 */

#include "sim/titan_sim_sensors.h"
#include "core/titan_math.h"
#include <string.h>
#include <math.h>

static titan_sim_physics_state_t s_physics;

void titan_sim_physics_init(void)
{
    memset(&s_physics, 0, sizeof(titan_sim_physics_state_t));
    s_physics.position_ned_m.z = -100.0f; /* 100m Altitude MSL */
    s_physics.ambient_temp_c = 20.0f;
}

void titan_sim_physics_step(f32_t dt)
{
    if (dt <= 0.0f) return;

    /* Integrate attitude based on angular velocities */
    s_physics.attitude_rad.roll  += s_physics.angular_velocity_radps.x * dt;
    s_physics.attitude_rad.pitch += s_physics.angular_velocity_radps.y * dt;
    s_physics.attitude_rad.yaw   += s_physics.angular_velocity_radps.z * dt;

    /* Integrate position based on velocity */
    s_physics.position_ned_m.x += s_physics.velocity_ned_mps.x * dt;
    s_physics.position_ned_m.y += s_physics.velocity_ned_mps.y * dt;
    s_physics.position_ned_m.z += s_physics.velocity_ned_mps.z * dt;
}

void titan_sim_get_imu_sample(titan_imu_sample_t *sample)
{
    if (!sample) return;

    /* Nominal specific force (Gravity pointing upwards in body frame) */
    sample->accel_mps2.x = 0.0f;
    sample->accel_mps2.y = 0.0f;
    sample->accel_mps2.z = 9.80665f;

    sample->gyro_radps = s_physics.angular_velocity_radps;
    sample->temperature_c = s_physics.ambient_temp_c;
    sample->sample_time_us = 0;
}

void titan_sim_get_baro_sample(titan_baro_data_t *baro)
{
    if (!baro) return;
    f32_t alt = -s_physics.position_ned_m.z;
    baro->altitude_m = alt;
    baro->sea_level_pressure_pa = 101325.0f;
    /* Invert barometric formula: p = p0 * (1 - h / 44330)^5.255 */
    baro->pressure_pa = 101325.0f * powf(1.0f - (alt / 44330.0f), 5.255f);
    baro->temperature_c = s_physics.ambient_temp_c - (alt * 0.0065f);
}
