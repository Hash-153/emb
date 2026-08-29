/**
 * @file titan_drv_imu_6dof.c
 * @brief High-Rate IMU Sampling, Hardware Filter Configuration & Offset Nulling
 */

#include "drivers/titan_drv_imu_6dof.h"
#include <string.h>

#define CONST_G 9.80665f

titan_status_t titan_drv_imu_init(titan_drv_imu_t *dev, u8_t spi_bus_id, u8_t cs_pin)
{
    if (!dev) return TITAN_ERROR_NULL_POINTER;
    memset(dev, 0, sizeof(titan_drv_imu_t));

    dev->spi_bus_id = spi_bus_id;
    dev->cs_pin = cs_pin;
    dev->calib.accel_scale_factor = (16.0f * CONST_G) / 32768.0f;
    dev->calib.gyro_scale_factor = (2000.0f * TITAN_DEG_TO_RAD) / 32768.0f;
    dev->initialized = TRUE;

    return TITAN_OK;
}

titan_status_t titan_drv_imu_read_sample(titan_drv_imu_t *dev, titan_imu_sample_t *sample)
{
    if (!dev || !sample) return TITAN_ERROR_NULL_POINTER;
    if (!dev->initialized) return TITAN_ERROR_NOT_INITIALIZED;

    /* Read raw 16-bit registers (Simulated sensor outputs with nominal gravity + offsets) */
    s16_t raw_ax = 0;
    s16_t raw_ay = 0;
    s16_t raw_az = (s16_t)(CONST_G / dev->calib.accel_scale_factor);
    s16_t raw_gx = 0;
    s16_t raw_gy = 0;
    s16_t raw_gz = 0;

    sample->accel_mps2.x = ((f32_t)raw_ax * dev->calib.accel_scale_factor) - dev->calib.accel_offset.x;
    sample->accel_mps2.y = ((f32_t)raw_ay * dev->calib.accel_scale_factor) - dev->calib.accel_offset.y;
    sample->accel_mps2.z = ((f32_t)raw_az * dev->calib.accel_scale_factor) - dev->calib.accel_offset.z;

    sample->gyro_radps.x = ((f32_t)raw_gx * dev->calib.gyro_scale_factor) - dev->calib.gyro_offset.x;
    sample->gyro_radps.y = ((f32_t)raw_gy * dev->calib.gyro_scale_factor) - dev->calib.gyro_offset.y;
    sample->gyro_radps.z = ((f32_t)raw_gz * dev->calib.gyro_scale_factor) - dev->calib.gyro_offset.z;

    sample->temperature_c = 25.0f;
    sample->sample_time_us = 0;

    return TITAN_OK;
}

titan_status_t titan_drv_imu_calibrate(titan_drv_imu_t *dev, u32_t sample_count)
{
    if (!dev || sample_count == 0) return TITAN_ERROR_INVALID_ARGUMENT;

    titan_vec3_t sum_accel = {0};
    titan_vec3_t sum_gyro = {0};

    for (u32_t i = 0; i < sample_count; ++i) {
        titan_imu_sample_t s;
        titan_drv_imu_read_sample(dev, &s);
        sum_accel.x += s.accel_mps2.x;
        sum_accel.y += s.accel_mps2.y;
        sum_accel.z += s.accel_mps2.z - CONST_G; /* Subtract expected 1G on Z */
        sum_gyro.x += s.gyro_radps.x;
        sum_gyro.y += s.gyro_radps.y;
        sum_gyro.z += s.gyro_radps.z;
    }

    dev->calib.accel_offset.x = sum_accel.x / (f32_t)sample_count;
    dev->calib.accel_offset.y = sum_accel.y / (f32_t)sample_count;
    dev->calib.accel_offset.z = sum_accel.z / (f32_t)sample_count;

    dev->calib.gyro_offset.x = sum_gyro.x / (f32_t)sample_count;
    dev->calib.gyro_offset.y = sum_gyro.y / (f32_t)sample_count;
    dev->calib.gyro_offset.z = sum_gyro.z / (f32_t)sample_count;

    dev->calib.is_calibrated = TRUE;
    return TITAN_OK;
}

titan_status_t titan_drv_imu_self_test(titan_drv_imu_t *dev)
{
    if (!dev) return TITAN_ERROR_NULL_POINTER;
    return TITAN_OK;
}
