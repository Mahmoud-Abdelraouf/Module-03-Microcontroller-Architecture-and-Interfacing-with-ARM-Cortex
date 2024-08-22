/**
  ******************************************************************************
  * @file         BIT_MATH.h
  * @author       Mahmoud Abdelraouf Mahmoud
  * @company      DevLeague
  * @date         26 August 2023
  * @version      0.4
  * @brief        Header file for bit manipulation macros for DevLeague projects.
  *
  * This file provides macros for setting, clearing, toggling, and reading bits
  * within 32-bit registers. These macros are designed to ensure safe operations
  * by including checks that prevent shifting beyond the width of the data type.
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

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#include <stdint.h>  // For uint32_t and related type definitions

// Define the bit-width of a standard register, assuming 32-bit registers.
#define BIT_WIDTH 32

/**
 * @brief Sets a specific bit in a register.
 *
 * This macro sets the specified bit in the given register to 1.
 * It first checks if the bit position is valid (i.e., less than 32).
 * If the bit position is valid, the bit is set; otherwise, no action is taken.
 *
 * @param[in,out] REG The register in which to set the bit.
 *                    This should be a 32-bit unsigned integer.
 * @param[in] BIT_NUMBER The position of the bit to set (0 to 31).
 *                       If BIT_NUMBER is greater than or equal to 32,
 *                       the macro will do nothing.
 *
 * @note The macro uses a do-while(0) loop to ensure it behaves like a function,
 *       allowing it to be used safely in any context, such as within an if-statement.
 */
#define SET_BIT(REG, BIT_NUMBER) \
    do { \
        if ((BIT_NUMBER) < BIT_WIDTH) { \
            (REG) |= (1U << (BIT_NUMBER)); \
        } \
    } while(0)

/**
 * @brief Clears a specific bit in a register.
 *
 * This macro clears (sets to 0) the specified bit in the given register.
 * It first checks if the bit position is valid (i.e., less than 32).
 * If the bit position is valid, the bit is cleared; otherwise, no action is taken.
 *
 * @param[in,out] REG The register in which to clear the bit.
 *                    This should be a 32-bit unsigned integer.
 * @param[in] BIT_NUMBER The position of the bit to clear (0 to 31).
 *                       If BIT_NUMBER is greater than or equal to 32,
 *                       the macro will do nothing.
 *
 * @note The macro uses a do-while(0) loop to ensure it behaves like a function,
 *       allowing it to be used safely in any context, such as within an if-statement.
 */
#define CLR_BIT(REG, BIT_NUMBER) \
    do { \
        if ((BIT_NUMBER) < BIT_WIDTH) { \
            (REG) &= ~(1U << (BIT_NUMBER)); \
        } \
    } while(0)

/**
 * @brief Toggles a specific bit in a register.
 *
 * This macro toggles (inverts) the specified bit in the given register.
 * It first checks if the bit position is valid (i.e., less than 32).
 * If the bit position is valid, the bit is toggled; otherwise, no action is taken.
 *
 * @param[in,out] REG The register in which to toggle the bit.
 *                    This should be a 32-bit unsigned integer.
 * @param[in] BIT_NUMBER The position of the bit to toggle (0 to 31).
 *                       If BIT_NUMBER is greater than or equal to 32,
 *                       the macro will do nothing.
 *
 * @note The macro uses a do-while(0) loop to ensure it behaves like a function,
 *       allowing it to be used safely in any context, such as within an if-statement.
 */
#define TOG_BIT(REG, BIT_NUMBER) \
    do { \
        if ((BIT_NUMBER) < BIT_WIDTH) { \
            (REG) ^= (1U << (BIT_NUMBER)); \
        } \
    } while(0)

/**
 * @brief Gets the value of a specific bit in a register.
 *
 * This macro retrieves the value of the specified bit in the given register.
 * It first checks if the bit position is valid (i.e., less than 32).
 * If the bit position is valid, the macro returns the bit's value (0 or 1).
 * If the bit position is not valid, the macro returns 0.
 *
 * @param[in] REG The register from which to get the bit value.
 *                This should be a 32-bit unsigned integer.
 * @param[in] BIT_NUMBER The position of the bit to get (0 to 31).
 *                       If BIT_NUMBER is greater than or equal to 32,
 *                       the macro will return 0.
 * @return The value of the specified bit (0 or 1).
 *
 * @note This macro is read-only and does not modify the register.
 */
#define GET_BIT(REG, BIT_NUMBER) \
    (((BIT_NUMBER) < BIT_WIDTH) ? (((REG) & (1U << (BIT_NUMBER))) >> (BIT_NUMBER)) : 0)

#endif /* BIT_MATH_H_ */
