/* 
 * File:   ecu_button.h
 * Author: moham
 *
 * Created on January 6, 2024, 1:02 PM
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
    BTN_RELEASED,
    BTN_PRESSED
}btn_state_t;

typedef enum
{
    BTN_ACTIVE_HIGH,
    BTN_ACTIVE_LOW
}btn_conn_t;

typedef struct
{
    pin_config_t btn_pin;
    btn_state_t btn_state;
    btn_conn_t btn_connection;
}btn_t;
/* Section: Functions Declarations */
/**
 * @brief initialize the assigned pin to be input
 * @param btn pointer to the button configuration
 * @return the state of the function
 */
Std_ReturnType btn_init(const btn_t* btn);
/**
 * 
 * @param btn pointer to the button configuration
 * @param btn_state pointer to catch the button state
 * @return the state of the function
 */
Std_ReturnType btn_read_state(const btn_t* btn, btn_state_t* btn_state);

#endif	/* ECU_BUTTON_H */

