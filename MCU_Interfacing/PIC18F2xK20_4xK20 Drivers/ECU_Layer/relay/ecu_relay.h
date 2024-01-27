/* 
 * File:   ecu_relay.h
 * Author: moham
 *
 * Created on January 25, 2024, 10:49 AM
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H

/* Section: Includes */
#include "ecu_relay_cfg.h"
#include "../../MCAL_Layer/GPIO/mcal_gpio.h"

/* Section: Macro Declarations */
#define RELAY_ON_STATUS  0X01U
#define RELAY_OFF_STATUS 0X00U

/* Section: Macro Functions Declarations */

/* Section: Data Types Declarations */
typedef struct 
{
    uint8 relay_port   :4;
    uint8 relay_pin    :3;
    uint8 relay_status :1;
}relay_t;

/* Section: Functions Declarations */
Std_ReturnType relay_init(const relay_t* relay);
Std_ReturnType relay_turn_on(const relay_t* relay);
Std_ReturnType relay_turn_off(const relay_t* relay);


#endif	/* ECU_RELAY_H */

