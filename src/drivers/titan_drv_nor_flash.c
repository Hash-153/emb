/**
 * @file titan_drv_nor_flash.c
 * @brief NOR Flash Command Engine and Page Programming Routines
 */

#include "drivers/titan_drv_nor_flash.h"
#include <string.h>

#define SIMULATED_FLASH_SIZE (4 * 1024 * 1024) /* 4MB Virtual Flash */
static u8_t s_virtual_flash[SIMULATED_FLASH_SIZE];

titan_status_t titan_nor_flash_init(titan_drv_nor_flash_t *flash, u8_t spi_id, u8_t cs_pin)
{
    if (!flash) return TITAN_ERROR_NULL_POINTER;
    flash->total_size_bytes = SIMULATED_FLASH_SIZE;
    flash->sector_size = TITAN_NOR_SECTOR_SIZE;
    flash->page_size = TITAN_NOR_PAGE_SIZE;
    flash->jedec_id = 0xEF4016; /* Winbond W25Q32 emulation */
    flash->spi_id = spi_id;
    flash->cs_pin = cs_pin;
    flash->is_busy = FALSE;

    /* Initialize flash array with 0xFF */
    memset(s_virtual_flash, 0xFF, sizeof(s_virtual_flash));
    return TITAN_OK;
}

titan_status_t titan_nor_flash_read(titan_drv_nor_flash_t *flash, u32_t addr, u8_t *buf, mem_size_t len)
{
    if (!flash || !buf) return TITAN_ERROR_NULL_POINTER;
    if (addr + len > flash->total_size_bytes) return TITAN_ERROR_OUT_OF_BOUNDS;

    memcpy(buf, &s_virtual_flash[addr], len);
    return TITAN_OK;
}

titan_status_t titan_nor_flash_write_page(titan_drv_nor_flash_t *flash, u32_t addr, const u8_t *buf, mem_size_t len)
{
    if (!flash || !buf) return TITAN_ERROR_NULL_POINTER;
    if (len > TITAN_NOR_PAGE_SIZE || addr + len > flash->total_size_bytes) {
        return TITAN_ERROR_INVALID_ARGUMENT;
    }

    /* Flash bitwise AND write constraint */
    for (mem_size_t i = 0; i < len; ++i) {
        s_virtual_flash[addr + i] &= buf[i];
    }
    return TITAN_OK;
}

titan_status_t titan_nor_flash_erase_sector(titan_drv_nor_flash_t *flash, u32_t sector_addr)
{
    if (!flash) return TITAN_ERROR_NULL_POINTER;
    u32_t aligned_addr = sector_addr & ~(TITAN_NOR_SECTOR_SIZE - 1);
    if (aligned_addr >= flash->total_size_bytes) return TITAN_ERROR_OUT_OF_BOUNDS;

    memset(&s_virtual_flash[aligned_addr], 0xFF, TITAN_NOR_SECTOR_SIZE);
    return TITAN_OK;
}

titan_status_t titan_nor_flash_erase_chip(titan_drv_nor_flash_t *flash)
{
    if (!flash) return TITAN_ERROR_NULL_POINTER;
    memset(s_virtual_flash, 0xFF, flash->total_size_bytes);
    return TITAN_OK;
}
