/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 26 Aug 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : STD_TYPES.h                *****************/
/****************************************************************/
#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char		u8;
typedef unsigned short  u16;
typedef unsigned int    u32;
typedef unsigned long   u64;

typedef signed char 		s8;
typedef signed short 		s16;
typedef signed int 			s32;
typedef signed long  		s64;

typedef float  				  f32;
typedef double 				  f64;
typedef long double  		f96;


typedef u8              Std_ReturnType;

#define E_OK            ((Std_ReturnType)1)
#define E_NOT_OK        ((Std_ReturnType)0)

#define NULL            ((void *)0x0)


#endif /* STD_TYPES_H_ */
