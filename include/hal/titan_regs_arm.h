/**
 * @file titan_regs_arm.h
 * @brief Memory-Mapped Register Definitions for ARM Cortex-M / RISC-V Microcontrollers
 * @version 2.4.0
 * @date 2026-08-29
 */

#ifndef TITAN_REGS_ARM_H
#define TITAN_REGS_ARM_H

#include "core/titan_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Peripheral Base Addresses (Simulated STM32F4/F7/H7 & RISC-V Unified Architecture) */
#define PERIPH_BASE             (0x40000000UL)
#define APB1PERIPH_BASE         (PERIPH_BASE)
#define APB2PERIPH_BASE         (PERIPH_BASE + 0x00010000UL)
#define AHB1PERIPH_BASE         (PERIPH_BASE + 0x00020000UL)

/* RCC Register Map */
typedef struct {
    __IO u32_t CR;            /**< Clock Control Register */
    __IO u32_t PLLCFGR;       /**< PLL Configuration Register */
    __IO u32_t CFGR;          /**< Clock Configuration Register */
    __IO u32_t CIR;           /**< Clock Interrupt Register */
    __IO u32_t AHB1RSTR;      /**< AHB1 Peripheral Reset Register */
    __IO u32_t AHB2RSTR;      /**< AHB2 Peripheral Reset Register */
    __IO u32_t RESERVED0[2];
    __IO u32_t APB1RSTR;      /**< APB1 Peripheral Reset Register */
    __IO u32_t APB2RSTR;      /**< APB2 Peripheral Reset Register */
    __IO u32_t RESERVED1[2];
    __IO u32_t AHB1ENR;       /**< AHB1 Peripheral Clock Enable */
    __IO u32_t AHB2ENR;       /**< AHB2 Peripheral Clock Enable */
    __IO u32_t RESERVED2[2];
    __IO u32_t APB1ENR;       /**< APB1 Peripheral Clock Enable */
    __IO u32_t APB2ENR;       /**< APB2 Peripheral Clock Enable */
} titan_reg_rcc_t;

/* GPIO Register Map */
typedef struct {
    __IO u32_t MODER;         /**< Port Mode Register (Input, Output, AF, Analog) */
    __IO u32_t OTYPER;        /**< Output Type (Push-Pull, Open-Drain) */
    __IO u32_t OSPEEDR;       /**< Output Speed Register */
    __IO u32_t PUPDR;         /**< Pull-Up / Pull-Down Register */
    __I  u32_t IDR;           /**< Input Data Register */
    __IO u32_t ODR;           /**< Output Data Register */
    __IO u32_t BSRR;          /**< Bit Set / Reset Register */
    __IO u32_t LCKR;          /**< Configuration Lock Register */
    __IO u32_t AFR[2];        /**< Alternate Function Low and High */
} titan_reg_gpio_t;

/* USART / UART Register Map */
typedef struct {
    __IO u32_t SR;            /**< Status Register */
    __IO u32_t DR;            /**< Data Register */
    __IO u32_t BRR;           /**< Baud Rate Register */
    __IO u32_t CR1;           /**< Control Register 1 */
    __IO u32_t CR2;           /**< Control Register 2 */
    __IO u32_t CR3;           /**< Control Register 3 */
    __IO u32_t GTPR;          /**< Guard Time and Prescaler Register */
} titan_reg_uart_t;

/* SPI Register Map */
typedef struct {
    __IO u32_t CR1;           /**< SPI Control Register 1 */
    __IO u32_t CR2;           /**< SPI Control Register 2 */
    __IO u32_t SR;            /**< SPI Status Register */
    __IO u32_t DR;            /**< SPI Data Register */
    __IO u32_t CRCPR;         /**< SPI CRC Polynomial Register */
    __I  u32_t RXCRCR;        /**< SPI Rx CRC Register */
    __I  u32_t TXCRCR;        /**< SPI Tx CRC Register */
} titan_reg_spi_t;

/* I2C Register Map */
typedef struct {
    __IO u32_t CR1;           /**< Control Register 1 */
    __IO u32_t CR2;           /**< Control Register 2 */
    __IO u32_t OAR1;          /**< Own Address Register 1 */
    __IO u32_t OAR2;          /**< Own Address Register 2 */
    __IO u32_t DR;            /**< Data Register */
    __IO u32_t SR1;           /**< Status Register 1 */
    __IO u32_t SR2;           /**< Status Register 2 */
    __IO u32_t CCR;           /**< Clock Control Register */
    __IO u32_t TRISE;         /**< Rise Time Register */
} titan_reg_i2c_t;

/* CAN Controller Register Map */
typedef struct {
    __IO u32_t MCR;           /**< Master Control Register */
    __IO u32_t MSR;           /**< Master Status Register */
    __IO u32_t TSR;           /**< Transmit Status Register */
    __IO u32_t RF0R;          /**< Receive FIFO 0 Register */
    __IO u32_t RF1R;          /**< Receive FIFO 1 Register */
    __IO u32_t IER;           /**< Interrupt Enable Register */
    __IO u32_t ESR;           /**< Error Status Register */
    __IO u32_t BTR;           /**< Bit Timing Register */
    __IO u32_t RESERVED[88];
    struct {
        __IO u32_t TIR;       /**< Tx Mailbox Identifier */
        __IO u32_t TDTR;      /**< Tx Mailbox Data Length / Timestamp */
        __IO u32_t TDLR;      /**< Tx Mailbox Data Low */
        __IO u32_t TDHR;      /**< Tx Mailbox Data High */
    } TX_MAILBOX[3];
    struct {
        __IO u32_t RIR;       /**< Rx Mailbox Identifier */
        __IO u32_t RDTR;      /**< Rx Mailbox Data Length / Timestamp */
        __IO u32_t RDLR;      /**< Rx Mailbox Data Low */
        __IO u32_t RDHR;      /**< Rx Mailbox Data High */
    } RX_FIFO[2];
} titan_reg_can_t;

/* ADC Register Map */
typedef struct {
    __IO u32_t SR;            /**< Status Register */
    __IO u32_t CR1;           /**< Control Register 1 */
    __IO u32_t CR2;           /**< Control Register 2 */
    __IO u32_t SMPR[2];       /**< Sample Time Registers */
    __IO u32_t JOFR[4];       /**< Injected Channel Offsets */
    __IO u32_t HTR;           /**< Watchdog Higher Threshold */
    __IO u32_t LTR;           /**< Watchdog Lower Threshold */
    __IO u32_t SQR[3];        /**< Regular Sequence Registers */
    __IO u32_t JSQR;          /**< Injected Sequence Register */
    __I  u32_t JDR[4];        /**< Injected Data Registers */
    __I  u32_t DR;            /**< Regular Data Register */
} titan_reg_adc_t;

#ifdef __cplusplus
}
#endif

#endif /* TITAN_REGS_ARM_H */
