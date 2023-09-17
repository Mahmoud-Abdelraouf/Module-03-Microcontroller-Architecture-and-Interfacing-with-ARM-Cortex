/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 26 Aug 2023                *****************/
/******* Version   : 0.2                        *****************/
/******* File Name : STD_TYPES.h                *****************/
/****************************************************************/
#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char u8;   /**< 8-bit unsigned integer type */
typedef unsigned short u16; /**< 16-bit unsigned integer type */
typedef unsigned int u32;   /**< 32-bit unsigned integer type */
typedef unsigned long u64;  /**< 64-bit unsigned integer type */

typedef signed char s8;     /**< 8-bit signed integer type */
typedef signed short s16;   /**< 16-bit signed integer type */
typedef signed int s32;     /**< 32-bit signed integer type */
typedef signed long s64;    /**< 64-bit signed integer type */

typedef float f32;          /**< Single-precision floating-point type */
typedef double f64;         /**< Double-precision floating-point type */
typedef long double f96;    /**< Extended-precision floating-point type */

typedef u8 Std_ReturnType;  /**< Standard return type for functions */
typedef s8 INVALID_VALUE;   /**< Marker for invalid or uninitialized data */

#define E_OK ((Std_ReturnType)1)        /**< Function execution successful */
#define E_NOT_OK ((Std_ReturnType)0)    /**< Function execution failed */

#define NULL ((void *)0x0)              /**< Null pointer definition */

#endif /* STD_TYPES_H_ */

