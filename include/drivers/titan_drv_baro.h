/**
 * @file titan_drv_baro.h
 * @brief High-Precision Barometric Pressure, Altitude & Temperature Sensor Driver
 */

#ifndef TITAN_DRV_BARO_H
#define TITAN_DRV_BARO_H

#include "core/titan_types.h"
#include "core/titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    f32_t pressure_pa;
    f32_t temperature_c;
    f32_t altitude_m;
    f32_t sea_level_pressure_pa;
} titan_baro_data_t;

typedef struct {
    u16_t dig_T1;
    s16_t dig_T2;
    s16_t dig_T3;
    u16_t dig_P1;
    s16_t dig_P2;
    s16_t dig_P3;
    s16_t dig_P4;
    s16_t dig_P5;
    s16_t dig_P6;
    s16_t dig_P7;
    s16_t dig_P8;
    s16_t dig_P9;
} titan_baro_calib_params_t;

typedef struct {
    u8_t                      i2c_bus_id;
    u8_t                      i2c_addr;
    titan_baro_calib_params_t calib;
    f32_t                     sea_level_ref;
    bool_t                    initialized;
} titan_drv_baro_t;

titan_status_t titan_drv_baro_init(titan_drv_baro_t *dev, u8_t i2c_bus, u8_t i2c_addr);
titan_status_t titan_drv_baro_read(titan_drv_baro_t *dev, titan_baro_data_t *data);
titan_status_t titan_drv_baro_set_sea_level_pressure(titan_drv_baro_t *dev, f32_t sea_level_pa);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_DRV_BARO_H */
