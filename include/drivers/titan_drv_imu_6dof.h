/**
 * @file titan_drv_imu_6dof.h
 * @brief 6-Axis Inertial Measurement Unit (Accelerometer + Gyroscope) SPI Driver
 * @version 2.4.0
 * @date 2026-08-29
 */

#ifndef TITAN_DRV_IMU_6DOF_H
#define TITAN_DRV_IMU_6DOF_H

#include "core/titan_types.h"
#include "core/titan_status.h"
#include "core/titan_math.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    TITAN_IMU_ACCEL_2G  = 0,
    TITAN_IMU_ACCEL_4G  = 1,
    TITAN_IMU_ACCEL_8G  = 2,
    TITAN_IMU_ACCEL_16G = 3
} titan_imu_accel_scale_t;

typedef enum {
    TITAN_IMU_GYRO_250DPS  = 0,
    TITAN_IMU_GYRO_500DPS  = 1,
    TITAN_IMU_GYRO_1000DPS = 2,
    TITAN_IMU_GYRO_2000DPS = 3
} titan_imu_gyro_scale_t;

typedef struct {
    titan_vec3_t accel_mps2;    /**< Acceleration in m/s^2 (X, Y, Z) */
    titan_vec3_t gyro_radps;    /**< Angular velocity in rad/s (X, Y, Z) */
    f32_t        temperature_c; /**< Internal die temperature in Celsius */
    u64_t        sample_time_us;
} titan_imu_sample_t;

typedef struct {
    titan_vec3_t accel_offset;
    titan_vec3_t gyro_offset;
    f32_t        accel_scale_factor;
    f32_t        gyro_scale_factor;
    bool_t       is_calibrated;
} titan_imu_calib_t;

typedef struct {
    u8_t              spi_bus_id;
    u8_t              cs_pin;
    titan_imu_calib_t calib;
    bool_t            initialized;
} titan_drv_imu_t;

titan_status_t titan_drv_imu_init(titan_drv_imu_t *dev, u8_t spi_bus_id, u8_t cs_pin);
titan_status_t titan_drv_imu_read_sample(titan_drv_imu_t *dev, titan_imu_sample_t *sample);
titan_status_t titan_drv_imu_calibrate(titan_drv_imu_t *dev, u32_t sample_count);
titan_status_t titan_drv_imu_self_test(titan_drv_imu_t *dev);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_DRV_IMU_6DOF_H */
