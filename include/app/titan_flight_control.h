/**
 * @file titan_flight_control.h
 * @brief 6-DOF Flight Dynamics & Actuator Mixer
 */

#ifndef TITAN_FLIGHT_CONTROL_H
#define TITAN_FLIGHT_CONTROL_H

#include "core/titan_types.h"
#include "core/titan_status.h"
#include "core/titan_math.h"
#include "dsp/titan_control_pid.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    titan_pid_t roll_rate_pid;
    titan_pid_t pitch_rate_pid;
    titan_pid_t yaw_rate_pid;
    titan_pid_t roll_angle_pid;
    titan_pid_t pitch_angle_pid;
    titan_pid_t yaw_angle_pid;
    f32_t       actuator_outputs[8];
} titan_flight_controller_t;

titan_status_t titan_fc_init(titan_flight_controller_t *fc, f32_t dt);
void           titan_fc_update(titan_flight_controller_t *fc, const titan_euler_t *target, const titan_euler_t *actual, const titan_vec3_t *gyro, f32_t throttle, f32_t dt);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_FLIGHT_CONTROL_H */
