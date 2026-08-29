/**
 * @file titan_flight_control.c
 * @brief Flight Dynamics, Actuator Decoupling Matrix, and Attitude Cascades
 */

#include "app/titan_flight_control.h"
#include "dsp/titan_control_pid.h"
#include "core/titan_defs.h"
#include <string.h>

titan_status_t titan_fc_init(titan_flight_controller_t *fc, f32_t dt)
{
    if (!fc || dt <= 0.0f) return TITAN_ERROR_INVALID_ARGUMENT;
    memset(fc, 0, sizeof(titan_flight_controller_t));
    titan_pid_init(&fc->roll_rate_pid, 0.15f, 0.20f, 0.004f, 0.0f, -1.0f, 1.0f, dt);
    titan_pid_init(&fc->pitch_rate_pid, 0.15f, 0.20f, 0.004f, 0.0f, -1.0f, 1.0f, dt);
    titan_pid_init(&fc->yaw_rate_pid, 0.25f, 0.10f, 0.000f, 0.0f, -1.0f, 1.0f, dt);
    titan_pid_init(&fc->roll_angle_pid, 6.0f, 0.0f, 0.0f, 0.0f, -20.0f, 20.0f, dt);
    titan_pid_init(&fc->pitch_angle_pid, 6.0f, 0.0f, 0.0f, 0.0f, -20.0f, 20.0f, dt);
    titan_pid_init(&fc->yaw_angle_pid, 4.0f, 0.0f, 0.0f, 0.0f, -20.0f, 20.0f, dt);
    return TITAN_OK;
}

void titan_fc_update(titan_flight_controller_t *fc, const titan_euler_t *target, const titan_euler_t *actual, const titan_vec3_t *gyro, f32_t throttle, f32_t dt)
{
    if (!fc || !target || !actual || !gyro) return;

    /* Cascaded Angle -> Rate Loop */
    f32_t target_rate_roll  = titan_pid_update(&fc->roll_angle_pid, target->roll, actual->roll, dt);
    f32_t target_rate_pitch = titan_pid_update(&fc->pitch_angle_pid, target->pitch, actual->pitch, dt);
    f32_t target_rate_yaw   = titan_pid_update(&fc->yaw_angle_pid, target->yaw, actual->yaw, dt);

    f32_t torque_roll  = titan_pid_update(&fc->roll_rate_pid, target_rate_roll, gyro->x, dt);
    f32_t torque_pitch = titan_pid_update(&fc->pitch_rate_pid, target_rate_pitch, gyro->y, dt);
    f32_t torque_yaw   = titan_pid_update(&fc->yaw_rate_pid, target_rate_yaw, gyro->z, dt);

    /* Quad-X Motor Mixer Matrix */
    fc->actuator_outputs[0] = TITAN_CLAMP(throttle - torque_roll + torque_pitch + torque_yaw, 0.0f, 1.0f);
    fc->actuator_outputs[1] = TITAN_CLAMP(throttle - torque_roll - torque_pitch - torque_yaw, 0.0f, 1.0f);
    fc->actuator_outputs[2] = TITAN_CLAMP(throttle + torque_roll - torque_pitch + torque_yaw, 0.0f, 1.0f);
    fc->actuator_outputs[3] = TITAN_CLAMP(throttle + torque_roll + torque_pitch - torque_yaw, 0.0f, 1.0f);
}
