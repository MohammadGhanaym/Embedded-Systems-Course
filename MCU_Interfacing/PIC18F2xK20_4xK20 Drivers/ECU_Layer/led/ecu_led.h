/* 
 * File:   ecu_led.h
 * Author: moham
 *
 * Created on September 17, 2023, 7:01 PM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H

/* Section: Includes */
#include "../../MCAL_Layer/GPIO/mcal_gpio.h"
#include "ecu_led_cfg.h"

/* Section: Macro Declarations */

/* Section: Macro Functions Declarations */

/* Section: Data Types Declarations */
typedef enum
{
    LED_OFF,
    LED_ON
}led_status_t;

typedef struct
{
    uint8 port_num      :4;
    uint8 pin           :3;
    uint8 led_status    :1;
}led_t;

/* Section: Functions Declarations */
Std_ReturnType led_init(const led_t* led);
Std_ReturnType led_turn_on(const led_t* led);
Std_ReturnType led_turn_off(const led_t* led);
Std_ReturnType led_toggle(const led_t* led);

#endif	/* ECU_LED_H */

