/**
  ******************************************************************************
  * @file         STD_TYPES.h
  * @company      DevLeague
  * @date         26 August 2023
  * @version      0.3
  * @brief        Standard type definitions for fixed-size data types.
  *
  * This file provides standard type definitions for unsigned and signed
  * integers of various sizes, as well as floating-point types. Additionally,
  * it defines common return types and error codes used throughout the project.
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

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/**< Include standard integer types for fixed-size definitions */
#include <stdint.h>

/**< Unsigned integer types */
typedef uint8_t  u8;           /**< 8-bit unsigned integer type */
typedef uint16_t u16;          /**< 16-bit unsigned integer type */
typedef uint32_t u32;          /**< 32-bit unsigned integer type */
typedef uint64_t u64;          /**< 64-bit unsigned integer type */

/**< Signed integer types */
typedef int8_t  s8;            /**< 8-bit signed integer type */
typedef int16_t s16;           /**< 16-bit signed integer type */
typedef int32_t s32;           /**< 32-bit signed integer type */
typedef int64_t s64;           /**< 64-bit signed integer type */

/**< Floating-point types */
typedef float  f32;            /**< Single-precision floating-point type */
typedef double f64;            /**< Double-precision floating-point type */
typedef long double f96;       /**< Extended-precision floating-point type */

/**< Standard return type for functions */
typedef u8 Std_ReturnType;

/**< Marker for invalid or uninitialized data */
typedef s8 INVALID_VALUE;

/**< Null pointer definition */
#define NULL ((void *)0x0)

/**< Function execution status codes */
#define E_OK            ((Std_ReturnType)1)       /**< Function execution successful */
#define E_NOT_OK        ((Std_ReturnType)0)       /**< Function execution failed */
#define E_INVALID_PARAMETER  ((INVALID_VALUE)-1)  /**< Invalid parameter marker */

#endif /* STD_TYPES_H_ */

