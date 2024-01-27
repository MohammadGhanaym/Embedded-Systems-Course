/* 
 * File:   ecu_relay.h
 * Author: moham
 *
 * Created on January 25, 2024, 2:37 PM
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
    uint8 port   :4;
    uint8 pin    :3;
    uint8 status :1;
}relay_t;
/* Section: Functions Declarations */

/**
 * @brief define the relay pin to be output and turn it on or off
 * @param relay pointer to the relay configurations
 * @return the status of the function
 *      (E_OK):     function done successfully
 *      (E_NOT_OK): function failed
 */
Std_ReturnType relay_init(const relay_t* relay);
/**
 * @brief turn relay on
 * @param relay pointer to the relay configurations
 * @return the status of the function
 *      (E_OK):     function done successfully
 *      (E_NOT_OK): function failed
 */
Std_ReturnType relay_turn_on(const relay_t* relay);
/**
 * @brief turn relay off
 * @param relay pointer to the relay configurations
 * @return the status of the function
 *      (E_OK):     function done successfully
 *      (E_NOT_OK): function failed
 */
Std_ReturnType relay_turn_off(const relay_t* relay);


#endif	/* ECU_RELAY_H */

