/**
 * @file titan_drv_nor_flash.h
 * @brief Quad-SPI / Standard SPI NOR Flash Memory Driver (SFDP Discovery & Wear Guard)
 */

#ifndef TITAN_DRV_NOR_FLASH_H
#define TITAN_DRV_NOR_FLASH_H

#include "core/titan_types.h"
#include "core/titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TITAN_NOR_PAGE_SIZE     256
#define TITAN_NOR_SECTOR_SIZE   4096
#define TITAN_NOR_BLOCK_SIZE    65536

typedef struct {
    u32_t total_size_bytes;
    u32_t sector_size;
    u32_t page_size;
    u32_t jedec_id;
    u8_t  spi_id;
    u8_t  cs_pin;
    bool_t is_busy;
} titan_drv_nor_flash_t;

titan_status_t titan_nor_flash_init(titan_drv_nor_flash_t *flash, u8_t spi_id, u8_t cs_pin);
titan_status_t titan_nor_flash_read(titan_drv_nor_flash_t *flash, u32_t addr, u8_t *buf, mem_size_t len);
titan_status_t titan_nor_flash_write_page(titan_drv_nor_flash_t *flash, u32_t addr, const u8_t *buf, mem_size_t len);
titan_status_t titan_nor_flash_erase_sector(titan_drv_nor_flash_t *flash, u32_t sector_addr);
titan_status_t titan_nor_flash_erase_chip(titan_drv_nor_flash_t *flash);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_DRV_NOR_FLASH_H */
