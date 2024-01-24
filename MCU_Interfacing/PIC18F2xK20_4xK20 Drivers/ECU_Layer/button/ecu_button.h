/* 
 * File:   ecu_button.h
 * Author: moham
 *
 * Created on January 5, 2024, 6:15 PM
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H


/* Section: Includes */
#include "../../MCAL_Layer/GPIO/mcal_gpio.h"
#include "ecu_button_cfg.h"

/* Section: Macro Declarations */

/* Section: Macro Functions Declarations */

/* Section: Data Types Declarations */
typedef enum
{
    BUTTON_PRESSED,
    BUTTON_RELEASED
}button_state_t;

typedef enum
{
    BUTTON_ACTIVE_HIGH,
    BUTTON_ACTIVE_LOW
}btn_conn_t;

typedef struct
{
    pin_config_t btn_pin;
    button_state_t button_state;
    btn_conn_t button_connection;
    
}button_t;
/* Section: Functions Declarations */
Std_ReturnType button_init(const button_t* button);
Std_ReturnType button_read_state(const button_t* button, button_state_t* button_state);



#endif	/* ECU_BUTTON_H */

