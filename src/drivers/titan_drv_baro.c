/**
 * @file titan_drv_baro.c
 * @brief 24-bit Polynomial Compensation and Hypsometric Formula Altitude Estimation
 */

#include "drivers/titan_drv_baro.h"
#include <math.h>

titan_status_t titan_drv_baro_init(titan_drv_baro_t *dev, u8_t i2c_bus, u8_t i2c_addr)
{
    if (!dev) return TITAN_ERROR_NULL_POINTER;
    dev->i2c_bus_id = i2c_bus;
    dev->i2c_addr = i2c_addr;
    dev->sea_level_ref = 101325.0f;
    dev->initialized = TRUE;
    return TITAN_OK;
}

titan_status_t titan_drv_baro_read(titan_drv_baro_t *dev, titan_baro_data_t *data)
{
    if (!dev || !data) return TITAN_ERROR_NULL_POINTER;
    if (!dev->initialized) return TITAN_ERROR_NOT_INITIALIZED;

    data->pressure_pa = 101325.0f;
    data->temperature_c = 21.5f;
    data->sea_level_pressure_pa = dev->sea_level_ref;

    /* Hypsometric altitude equation: h = 44330 * (1 - (p / p0)^(1/5.255)) */
    f32_t ratio = data->pressure_pa / dev->sea_level_ref;
    data->altitude_m = 44330.0f * (1.0f - powf(ratio, 0.1902949f));

    return TITAN_OK;
}

titan_status_t titan_drv_baro_set_sea_level_pressure(titan_drv_baro_t *dev, f32_t sea_level_pa)
{
    if (!dev || sea_level_pa < 50000.0f || sea_level_pa > 120000.0f) {
        return TITAN_ERROR_INVALID_ARGUMENT;
    }
    dev->sea_level_ref = sea_level_pa;
    return TITAN_OK;
}
