/* 
 * File:   mcal_std_types.h
 * Author: moham
 *
 * Created on September 28, 2023, 12:54 PM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/* Section: Includes */
#include "compiler.h"
#include "std_libraries.h"

/* Section: Data Types Declarations */
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;

typedef uint8 Std_ReturnType;
/* Section: Macro Declarations */
#define STD_HIGH    0X01
#define STD_LOW     0X00

#define STD_ON      0X01
#define STD_OFF     0X00

#define STD_ACTIVE  0X01
#define STD_IDLE    0X00

#define E_OK        (Std_ReturnType)0X01
#define E_NOT_OK    (Std_ReturnType)0X00    

/* Section: Macro Functions Declarations */

/* Section: Functions Declarations */

#endif	/* MCAL_STD_TYPES_H */

