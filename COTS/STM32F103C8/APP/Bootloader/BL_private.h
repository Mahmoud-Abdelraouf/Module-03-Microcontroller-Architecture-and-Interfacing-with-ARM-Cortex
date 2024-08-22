/**
  ******************************************************************************
  * @file         BL_private.h
  * @author       Mahmoud Abdelraouf Mahmoud
  * @company      DevLeague
  * @date         16 August 2024
  * @version      0.1
  * @brief        Private declarations for Bootloader functionalities.
  *
  * This file contains private function declarations for the Bootloader.
  * These functions handle various operations such as flash memory management,
  * CRC verification, and communication with the host.
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

#ifndef INC_BL_PRIVATE_H_
#define INC_BL_PRIVATE_H_

/**
 * @brief Retrieves the bootloader version and sends it to the host.
 * @param host_buffer Buffer containing the host command.
 */
static void getBootloaderVersion(uint8_t *host_buffer);

/**
 * @brief Provides a list of supported bootloader commands to the host.
 * @param host_buffer Buffer containing the host command.
 */
static void getSupportedCommands(uint8_t *host_buffer);

/**
 * @brief Retrieves the chip identification number and sends it to the host.
 * @param host_buffer Buffer containing the host command.
 */
static void getChipID(uint8_t *host_buffer);

/**
 * @brief Handles the flash memory erase operation based on host command.
 * @param host_buffer Buffer containing the host command.
 */
static void eraseFlashMemory(uint8_t *host_buffer);

/**
 * @brief Writes data to flash memory as per the host command.
 * @param host_buffer Buffer containing the host command.
 */
static void writeFlashMemory(uint8_t *host_buffer);

/**
 * @brief Verifies the CRC sent by the host against the calculated CRC.
 * @param data_ptr Pointer to the data to calculate the CRC on.
 * @param data_length Length of the data in bytes.
 * @param host_crc CRC value received from the host.
 * @return The status of the CRC verification (success or failure).
 */
static uint32_t verifyCRC(uint8_t *data_ptr, uint32_t data_length, uint32_t host_crc);

/**
 * @brief Performs the flash erase operation for the specified pages.
 * @param page_address Start address of the page to be erased.
 * @param page_number Number of pages to erase.
 * @return Status of the flash erase operation (success or failure).
 */
static uint8_t performFlashErase(uint32_t page_address, uint8_t page_number);

/**
 * @brief Verifies if the provided address is within the valid range.
 * @param address Address to be verified.
 * @return Address verification status (valid or invalid).
 */
static uint8_t verifyAddress(uint32_t address);

/**
 * @brief Writes a data payload to the specified flash memory address.
 * @param data_ptr Pointer to the payload data.
 * @param start_address Start address in flash memory where the data is to be written.
 * @param payload_length Length of the payload data in bytes.
 * @return Status of the flash write operation (success or failure).
 */
static uint8_t writePayloadToFlash(uint16_t *data_ptr, uint32_t start_address, uint8_t payload_length);

/**
 * @brief Sends an acknowledgment (ACK) to the host.
 * @param data_length Length of the ACK data to be sent.
 */
static void sendACK(uint8_t data_length);

/**
 * @brief Sends a negative acknowledgment (NACK) to the host.
 */
static void sendNACK(void);

#endif /* INC_BL_PRIVATE_H_ */
