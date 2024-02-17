/* 
 * File:   seven_seg_ecu.h
 * Author: moham
 *
 * Created on February 17, 2024, 9:10 PM
 */

#ifndef SEVEN_SEG_ECU_H
#define	SEVEN_SEG_ECU_H


/* Section: Includes */
#include "seven_seg_cfg.h"
#include "../../MCAL_Layer/GPIO/mcal_gpio.h"

/* Section: Macro Declarations */
#define SEGMENT_PIN0 0
#define SEGMENT_PIN1 1
#define SEGMENT_PIN2 2
#define SEGMENT_PIN3 3
/* Section: Macro Functions Declarations */

/* Section: Data Types Declarations */
typedef enum
{
    SEGMENT_COMMON_ANODE,
    SEGMENT_COMMON_CATHODE
}segment_type_t;

typedef struct
{
    pin_config_t segment_pins[4];
    segment_type_t seg_type;
}segment_t;

/* Section: Functions Declarations */
Std_ReturnType seven_segment_initialize(const segment_t* seg);
Std_ReturnType seven_segment_write_number(const segment_t* seg, uint8 number);



#endif	/* SEVEN_SEG_ECU_H */

