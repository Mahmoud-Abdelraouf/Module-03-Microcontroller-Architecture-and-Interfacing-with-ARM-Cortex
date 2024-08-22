/**
  ******************************************************************************
  * @file         BL_interface.h
  * @author       Mahmoud Abdelraouf Mahmoud
  * @company      DevLeague
  * @date         16 August 2024
  * @version      0.2
  * @brief        Interface for Bootloader functionalities.
  *
  * This file provides public function declarations for the Bootloader.
  * These functions include operations such as command fetching,
  * message sending, and communication with the host.
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

#ifndef INC_BOOTLOADER_INTERFACE_H_
#define INC_BOOTLOADER_INTERFACE_H_

/**
 * @brief Bootloader status codes.
 */
typedef enum
{
    BL_STATUS_NACK = 0, /**< Negative acknowledgment */
    BL_STATUS_ACK       /**< Acknowledgment */
} BL_Status;

/**
 * @brief Fetch and process host commands.
 * @return BL_Status indicating whether an ACK or NACK was sent.
 */
BL_Status fetchHostCommand(void);

/**
 * @brief Send a formatted message to the host via UART.
 * @param format String format to be transmitted.
 * @param ... Additional arguments for the format string.
 */
void sendMessageToHost(const char *format, ...);

#endif /* INC_BOOTLOADER_INTERFACE_H_ */
