/**
 * @file titan_hal_gpio.h
 * @brief General Purpose I/O Pin Configuration, Alternate Functions and Interrupt Triggers
 */

#ifndef TITAN_HAL_GPIO_H
#define TITAN_HAL_GPIO_H

#include "hal/titan_regs_arm.h"
#include "core/titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    TITAN_GPIO_PORT_A = 0,
    TITAN_GPIO_PORT_B,
    TITAN_GPIO_PORT_C,
    TITAN_GPIO_PORT_D,
    TITAN_GPIO_PORT_E,
    TITAN_GPIO_PORT_F,
    TITAN_GPIO_PORT_COUNT
} titan_gpio_port_t;

typedef enum {
    TITAN_GPIO_PIN_0 = 0,
    TITAN_GPIO_PIN_1,
    TITAN_GPIO_PIN_2,
    TITAN_GPIO_PIN_3,
    TITAN_GPIO_PIN_4,
    TITAN_GPIO_PIN_5,
    TITAN_GPIO_PIN_6,
    TITAN_GPIO_PIN_7,
    TITAN_GPIO_PIN_8,
    TITAN_GPIO_PIN_9,
    TITAN_GPIO_PIN_10,
    TITAN_GPIO_PIN_11,
    TITAN_GPIO_PIN_12,
    TITAN_GPIO_PIN_13,
    TITAN_GPIO_PIN_14,
    TITAN_GPIO_PIN_15
} titan_gpio_pin_t;

typedef enum {
    TITAN_GPIO_MODE_INPUT = 0,
    TITAN_GPIO_MODE_OUTPUT_PP,
    TITAN_GPIO_MODE_OUTPUT_OD,
    TITAN_GPIO_MODE_AF_PP,
    TITAN_GPIO_MODE_AF_OD,
    TITAN_GPIO_MODE_ANALOG
} titan_gpio_mode_t;

typedef enum {
    TITAN_GPIO_PULL_NONE = 0,
    TITAN_GPIO_PULL_UP,
    TITAN_GPIO_PULL_DOWN
} titan_gpio_pull_t;

typedef enum {
    TITAN_GPIO_SPEED_LOW = 0,
    TITAN_GPIO_SPEED_MEDIUM,
    TITAN_GPIO_SPEED_HIGH,
    TITAN_GPIO_SPEED_VERY_HIGH
} titan_gpio_speed_t;

typedef struct {
    titan_gpio_port_t   port;
    titan_gpio_pin_t    pin;
    titan_gpio_mode_t   mode;
    titan_gpio_pull_t   pull;
    titan_gpio_speed_t  speed;
    u8_t                alternate_function;
} titan_gpio_config_t;

titan_status_t titan_hal_gpio_init(const titan_gpio_config_t *cfg);
void           titan_hal_gpio_write(titan_gpio_port_t port, titan_gpio_pin_t pin, bool_t state);
bool_t         titan_hal_gpio_read(titan_gpio_port_t port, titan_gpio_pin_t pin);
void           titan_hal_gpio_toggle(titan_gpio_port_t port, titan_gpio_pin_t pin);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_HAL_GPIO_H */
