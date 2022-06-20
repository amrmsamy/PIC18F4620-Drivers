/* 
 * File:   MCAL_std_types.h
 * Author: Amr Samy
 *
 * Created on June 14, 2022, 7:25 PM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/* Section: Includes */
#include "std_libraries.h"
#include "complier.h"
#include <stdio.h>
#include <stdlib.h>

/* Section: Macro Declarations */
#define STD_HIGH        0x01
#define STD_LOW         0x00



#define STD_ON          0x01
#define STD_OFF         0x00

#define STD_ACTIVE      0x01
#define STD_IDLE        0x00

#define E_OK        (Std_ReturnType)0x01
#define E_NOK       (Std_ReturnType)0x00

/* Section: Macro Functions Declarations */

/* Section: Data Type Declarations */
typedef unsigned char   uint8;
typedef unsigned short  uint16;
typedef unsigned int    uint32;
typedef signed char     sint8;
typedef signed short    sint16;
typedef signed int      sint32;

typedef uint8   Std_ReturnType;

/* Section: Function Declarations */

#endif	/* MCAL_STD_TYPES_H */

