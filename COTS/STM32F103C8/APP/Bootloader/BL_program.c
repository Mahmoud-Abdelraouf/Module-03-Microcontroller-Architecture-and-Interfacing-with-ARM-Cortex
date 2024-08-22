/**
  ******************************************************************************
  * @file         BL_program.c
  * @author       Mahmoud Abdelraouf Mahmoud
  * @company      DevLeague
  * @date         16 August 2024
  * @version      0.2
  * @brief        Implementation of Bootloader functionalities.
  *
  * This file contains the implementation of the Bootloader's core functionalities,
  * including command processing, flash memory operations, and communication
  * with the host system via UART.
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

//----------------------------< SYS -----------------------------/
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

//----------------------------< LIB -----------------------------/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "crc.h"

//----------------------------< MCAL -----------------------------/
#include "usart.h"

//----------------------------< APP -----------------------------/
#include "BL_private.h"
#include "BL_interface.h"
#include "BL_config.h"

static uint8_t BL_HostBuffer[BL_HOST_BUFFER_SIZE];


/**
 * @brief Fetch and process host commands.
 * @return BL_Status indicating whether an ACK or NACK was sent.
 */
BL_Status fetchHostCommand(void) {
    BL_Status status = BL_STATUS_NACK;
    HAL_StatusTypeDef hal_status = HAL_ERROR;
    uint8_t data_len = 0;
    memset(BL_HostBuffer, 0, BL_HOST_BUFFER_SIZE);

    hal_status = HAL_UART_Receive(&huart1, BL_HostBuffer, 1, HAL_MAX_DELAY);
    if (hal_status != HAL_OK) {
        return status;
    }

    data_len = BL_HostBuffer[0];
    hal_status = HAL_UART_Receive(&huart1, &BL_HostBuffer[1], data_len, HAL_MAX_DELAY);
    if (hal_status != HAL_OK) {
        return status;
    }

    switch (BL_HostBuffer[1]) {
        case BL_CMD_GET_VER:
            getBootloaderVersion(BL_HostBuffer);
            break;
        case BL_CMD_GET_HELP:
            getSupportedCommands(BL_HostBuffer);
            break;
        case BL_CMD_GET_CID:
            getChipID(BL_HostBuffer);
            break;
        case BL_CMD_GO_TO_ADDR:
            sendMessageToHost("Jump to address");
            break;
        case BL_CMD_FLASH_ERASE:
            eraseFlashMemory(BL_HostBuffer);
            break;
        case BL_CMD_MEM_WRITE:
            writeFlashMemory(BL_HostBuffer);
            break;
        default:
            status = BL_STATUS_NACK;
            break;
    }

    return status;
}

/**
 * @brief Send a formatted message to the host via UART.
 *
 * Formats a message string using the given format and arguments, then transmits
 * the message via UART. If an error occurs during formatting, a fallback message
 * is sent to indicate the error.
 *
 * @param format The format string, similar to printf (e.g., %d, %s).
 * @param ... Additional arguments for the format string.
 */
void sendMessageToHost(const char *format, ...) {
    char message[100];
    va_list args;

    va_start(args, format);
    int msg_len = vsnprintf(message, sizeof(message), format, args);
    va_end(args);

    // Check for encoding error
    if (msg_len < 0) {
        // Send a fallback message to indicate an error
        const char *error_message = "Error: Message encoding failed.";
        HAL_UART_Transmit(&huart1, (uint8_t*)error_message, strlen(error_message), HAL_MAX_DELAY);
        return;
    } else if (msg_len >= sizeof(message)) {
        // Handle truncation case
        msg_len = sizeof(message) - 1;
        message[msg_len] = '\0';
    }

    // Transmit the formatted message
    HAL_UART_Transmit(&huart1, (uint8_t*)message, msg_len, HAL_MAX_DELAY);
}

/**
 * @brief Retrieve the bootloader version and send it to the host.
 * @param host_buffer Buffer containing the host command.
 */
static void getBootloaderVersion(uint8_t *host_buffer) {
    uint8_t version[4] = {
        BL_VENDOR_ID,
        BL_SW_MAJOR_VERSION,
        BL_SW_MINOR_VERSION,
        BL_SW_PATCH_VERSION
    };
    uint16_t packet_len = 0;
    uint32_t crc_value = 0;

    packet_len = host_buffer[0] + 1;
    crc_value = *(uint32_t*)(host_buffer + packet_len - 4);

    if (verifyCRC(host_buffer, packet_len - 4, crc_value) == BL_CRC_SUCCESS) {
        sendACK(4);
        HAL_UART_Transmit(&huart1, version, 4, HAL_MAX_DELAY);
    } else {
        sendNACK();
    }
}

/**
 * @brief Retrieve the list of supported commands and send it to the host.
 * @param host_buffer Buffer containing the host command.
 */
static void getSupportedCommands(uint8_t *host_buffer) {
    uint8_t supported_commands[6] = {
        BL_CMD_GET_VER,
        BL_CMD_GET_HELP,
        BL_CMD_GET_CID,
        BL_CMD_GO_TO_ADDR,
        BL_CMD_FLASH_ERASE,
        BL_CMD_MEM_WRITE
    };
    uint16_t packet_len = 0;
    uint32_t crc_value = 0;

    packet_len = host_buffer[0] + 1;
    crc_value = *(uint32_t*)(host_buffer + packet_len - 4);

    if (verifyCRC(host_buffer, packet_len - 4, crc_value) == BL_CRC_SUCCESS) {
        sendACK(6);
        HAL_UART_Transmit(&huart1, supported_commands, 6, HAL_MAX_DELAY);
    } else {
        sendNACK();
    }
}

/**
 * @brief Retrieve the chip identification number and send it to the host.
 * @param host_buffer Buffer containing the host command.
 */
static void getChipID(uint8_t *host_buffer) {
    uint16_t chip_id = 0;
    uint16_t packet_len = 0;
    uint32_t crc_value = 0;

    packet_len = host_buffer[0] + 1;
    crc_value = *(uint32_t*)(host_buffer + packet_len - 4);

    if (verifyCRC(host_buffer, packet_len - 4, crc_value) == BL_CRC_SUCCESS) {
        chip_id = (uint16_t)(DBGMCU->IDCODE & 0x00000FFF);
        sendACK(2);
        HAL_UART_Transmit(&huart1, (uint8_t*)&chip_id, 2, HAL_MAX_DELAY);
    } else {
        sendNACK();
    }
}

/**
 * @brief Handle the flash memory erase operation based on host command.
 * @param host_buffer Buffer containing the host command.
 */
static void eraseFlashMemory(uint8_t *host_buffer) {
    uint8_t erase_status = ERASE_FAILED;
    uint16_t packet_len = 0;
    uint32_t crc_value = 0;

    packet_len = host_buffer[0] + 1;
    crc_value = *(uint32_t*)(host_buffer + packet_len - 4);

    if (verifyCRC(host_buffer, packet_len - 4, crc_value) == BL_CRC_SUCCESS) {
        erase_status = performFlashErase(*(uint32_t*)&host_buffer[7], host_buffer[6]);
        sendACK(1);
        HAL_UART_Transmit(&huart1, &erase_status, 1, HAL_MAX_DELAY);
    } else {
        sendNACK();
    }
}

/**
 * @brief Write data to flash memory as per the host command.
 * @param host_buffer Buffer containing the host command.
 */
static void writeFlashMemory(uint8_t *host_buffer) {
    uint8_t address_status = ADDRESS_INVALID;
    uint32_t host_address = 0;
    uint8_t data_len = 0;
    uint8_t write_status = FLASH_WRITE_FAILED;
    uint16_t packet_len = 0;
    uint32_t crc_value = 0;

    packet_len = host_buffer[0] + 1;
    crc_value = *(uint32_t*)(host_buffer + packet_len - 4);

    if (verifyCRC(host_buffer, packet_len - 4, crc_value) == BL_CRC_SUCCESS) {
        sendACK(1);
        host_address = *(uint32_t*)&host_buffer[2];
        data_len = host_buffer[6];
        address_status = verifyAddress(host_address);

        if (address_status == ADDRESS_VALID) {
            write_status = writePayloadToFlash((uint16_t*)&host_buffer[7], host_address, data_len);
            HAL_UART_Transmit(&huart1, &write_status, 1, HAL_MAX_DELAY);
        } else {
            HAL_UART_Transmit(&huart1, &address_status, 1, HAL_MAX_DELAY);
        }
    } else {
        sendNACK();
    }
}

/**
 * @brief Verify the CRC received from the host against the calculated CRC.
 * @param data_ptr Pointer to the data to calculate the CRC on.
 * @param data_length Length of the data in bytes.
 * @param host_crc CRC value received from the host.
 * @return The status of the CRC verification (success or failure).
 */
static uint32_t verifyCRC(uint8_t *data_ptr, uint32_t data_length, uint32_t host_crc) {
    uint32_t mcu_crc = 0;
    uint32_t data_buffer = 0;

    for (uint32_t i = 0; i < data_length; i++) {
        data_buffer = (uint32_t)data_ptr[i];
        mcu_crc = HAL_CRC_Accumulate(&hcrc, &data_buffer, 1);
    }

    __HAL_CRC_DR_RESET(&hcrc);

    return (host_crc == mcu_crc) ? BL_CRC_SUCCESS : BL_CRC_FAILED;
}

/**
 * @brief Perform the flash erase operation for the specified pages.
 * @param page_address Start address of the page to be erased.
 * @param page_number Number of pages to erase.
 * @return Status of the flash erase operation (success or failure).
 */
static uint8_t performFlashErase(uint32_t page_address, uint8_t page_number) {
    FLASH_EraseInitTypeDef erase_init_struct;
    HAL_StatusTypeDef hal_status = HAL_ERROR;
    uint32_t page_error = 0;
    uint8_t status = INVALID_PAGE_NUMBER;

    if (page_number > BL_FLASH_MAX_PAGE_NUMBER) {
        return INVALID_PAGE_NUMBER;
    }

    if (page_address == BL_FLASH_MASS_ERASE || page_address <= STM32F103_FLASH_END) {
        erase_init_struct.TypeErase = FLASH_TYPEERASE_PAGES;
        erase_init_struct.PageAddress = page_address == BL_FLASH_MASS_ERASE ? FLASH_BASE : page_address;
        erase_init_struct.NbPages = page_address == BL_FLASH_MASS_ERASE ? BL_FLASH_MAX_PAGE_NUMBER : page_number;
        erase_init_struct.Banks = FLASH_BANK_1;

        HAL_FLASH_Unlock();
        hal_status = HAL_FLASHEx_Erase(&erase_init_struct, &page_error);
        HAL_FLASH_Lock();

        status = (hal_status == HAL_OK) ? ERASE_SUCCESSFUL : ERASE_FAILED;
    }

    return status;
}

/**
 * @brief Verify if the provided address is within the valid range.
 * @param address Address to be verified.
 * @return Address verification status (valid or invalid).
 */
static uint8_t verifyAddress(uint32_t address) {
    if ((address >= FLASH_BASE && address <= STM32F103_FLASH_END) ||
        (address >= SRAM_BASE && address <= STM32F103_SRAM_END)) {
        return ADDRESS_VALID;
    } else {
        return ADDRESS_INVALID;
    }
}

/**
 * @brief Write a data payload to the specified flash memory address.
 * @param data_ptr Pointer to the payload data.
 * @param start_address Start address in flash memory where the data is to be written.
 * @param payload_length Length of the payload data in bytes.
 * @return Status of the flash write operation (success or failure).
 */
static uint8_t writePayloadToFlash(uint16_t *data_ptr, uint32_t start_address, uint8_t payload_length) {
    uint32_t current_address = start_address;
    uint8_t status = FLASH_WRITE_FAILED;

    HAL_FLASH_Unlock();

    for (uint8_t i = 0; i < payload_length / 2; i++) {
        if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, current_address, data_ptr[i]) == HAL_OK) {
            status = FLASH_WRITE_SUCCESSFUL;
            current_address += 2;
        } else {
            status = FLASH_WRITE_FAILED;
            break;
        }
    }

    HAL_FLASH_Lock();

    return status;
}

/**
 * @brief Send an acknowledgment (ACK) to the host.
 * @param data_length Length of the ACK data to be sent.
 */
static void sendACK(uint8_t data_length) {
    uint8_t ack_value[2] = {BL_SEND_ACK, data_length};
    HAL_UART_Transmit(&huart1, ack_value, sizeof(ack_value), HAL_MAX_DELAY);
}

/**
 * @brief Send a negative acknowledgment (NACK) to the host.
 */
static void sendNACK(void) {
    uint8_t nack_value = BL_SEND_NACK;
    HAL_UART_Transmit(&huart1, &nack_value, sizeof(nack_value), HAL_MAX_DELAY);
}
