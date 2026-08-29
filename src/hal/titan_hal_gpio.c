/**
 * @file titan_hal_gpio.c
 * @brief Hardware Register Level GPIO Operations
 */

#include "hal/titan_hal_gpio.h"

/* Memory space simulated port banks */
static titan_reg_gpio_t s_gpio_ports[TITAN_GPIO_PORT_COUNT];

titan_status_t titan_hal_gpio_init(const titan_gpio_config_t *cfg)
{
    if (!cfg || cfg->port >= TITAN_GPIO_PORT_COUNT) {
        return TITAN_ERROR_INVALID_ARGUMENT;
    }

    titan_reg_gpio_t *port = &s_gpio_ports[cfg->port];
    u32_t pin_pos = (u32_t)cfg->pin;

    /* Set mode bits (2 bits per pin) */
    port->MODER &= ~(0x3UL << (pin_pos * 2));
    port->MODER |= ((u32_t)cfg->mode & 0x3UL) << (pin_pos * 2);

    /* Set pull up / pull down */
    port->PUPDR &= ~(0x3UL << (pin_pos * 2));
    port->PUPDR |= ((u32_t)cfg->pull & 0x3UL) << (pin_pos * 2);

    /* Set speed */
    port->OSPEEDR &= ~(0x3UL << (pin_pos * 2));
    port->OSPEEDR |= ((u32_t)cfg->speed & 0x3UL) << (pin_pos * 2);

    /* Alternate function configuration */
    if (cfg->mode == TITAN_GPIO_MODE_AF_PP || cfg->mode == TITAN_GPIO_MODE_AF_OD) {
        u32_t afr_idx = pin_pos >> 3;
        u32_t afr_pos = (pin_pos & 0x7) * 4;
        port->AFR[afr_idx] &= ~(0xFUL << afr_pos);
        port->AFR[afr_idx] |= ((u32_t)cfg->alternate_function & 0xFUL) << afr_pos;
    }

    return TITAN_OK;
}

void titan_hal_gpio_write(titan_gpio_port_t port, titan_gpio_pin_t pin, bool_t state)
{
    if (port >= TITAN_GPIO_PORT_COUNT) return;
    titan_reg_gpio_t *p = &s_gpio_ports[port];
    if (state) {
        p->BSRR = (1UL << (u32_t)pin);
        p->ODR |= (1UL << (u32_t)pin);
    } else {
        p->BSRR = (1UL << ((u32_t)pin + 16));
        p->ODR &= ~(1UL << (u32_t)pin);
    }
}

bool_t titan_hal_gpio_read(titan_gpio_port_t port, titan_gpio_pin_t pin)
{
    if (port >= TITAN_GPIO_PORT_COUNT) return FALSE;
    return (s_gpio_ports[port].IDR & (1UL << (u32_t)pin)) != 0;
}

void titan_hal_gpio_toggle(titan_gpio_port_t port, titan_gpio_pin_t pin)
{
    if (port >= TITAN_GPIO_PORT_COUNT) return;
    bool_t current = titan_hal_gpio_read(port, pin);
    titan_hal_gpio_write(port, pin, !current);
}
