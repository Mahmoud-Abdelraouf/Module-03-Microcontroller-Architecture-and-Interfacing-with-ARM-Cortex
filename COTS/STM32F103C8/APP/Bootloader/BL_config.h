/**
  ******************************************************************************
  * @file         BL_config.h
  * @author       Mahmoud Abdelraouf Mahmoud
  * @company      DevLeague
  * @date         16 August 2024
  * @version      0.2
  * @brief        Configuration header for Bootloader.
  *
  * This file contains configuration definitions for the Bootloader, including
  * version information, flash memory settings, status codes, and communication
  * commands. These configurations are used throughout the Bootloader's
  * functionality to ensure consistency and reliability.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 DevLeague.
  * All rights reserved.
  *
  * This software is licensed under the terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#ifndef INC_BOOTLOADER_CONFIG_H_
#define INC_BOOTLOADER_CONFIG_H_

// Bootloader version information
#define BL_VENDOR_ID 100
#define BL_SW_MAJOR_VERSION 1
#define BL_SW_MINOR_VERSION 1
#define BL_SW_PATCH_VERSION 0

// Flash memory configurations
#define BL_FLASH_MAX_PAGE_NUMBER 16
#define BL_FLASH_MASS_ERASE 0xFF
#define STM32F103_FLASH_SIZE (64 * 1024)
#define STM32F103_FLASH_END (FLASH_BASE + STM32F103_FLASH_SIZE)
#define STM32F103_SRAM_SIZE (20 * 1024)
#define STM32F103_SRAM_END (SRAM_BASE + STM32F103_SRAM_SIZE)

// Status codes
#define INVALID_PAGE_NUMBER 0x00
#define VALID_PAGE_NUMBER 0x01
#define ERASE_FAILED 0x02
#define ERASE_SUCCESSFUL 0x03
#define FLASH_WRITE_FAILED 0x00
#define FLASH_WRITE_SUCCESSFUL 0x01
#define ADDRESS_INVALID 0x00
#define ADDRESS_VALID 0x01

// Communication-related configurations
#define BL_CMD_GET_VER 0x10
#define BL_CMD_GET_HELP 0x11
#define BL_CMD_GET_CID 0x12
#define BL_CMD_GO_TO_ADDR 0x14
#define BL_CMD_FLASH_ERASE 0x15
#define BL_CMD_MEM_WRITE 0x16

#define BL_CRC_FAILED 0x00
#define BL_CRC_SUCCESS 0x01

#define BL_SEND_NACK 0xAB
#define BL_SEND_ACK 0xCD

#define BL_HOST_BUFFER_SIZE 200

#endif /* INC_BOOTLOADER_CONFIG_H_ */
