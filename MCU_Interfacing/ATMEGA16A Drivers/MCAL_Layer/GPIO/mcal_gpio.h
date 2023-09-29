/* 
 * File:   mcal_gpio.h
 * Author: moham
 *
 * Created on September 28, 2023, 12:49 PM
 */

#ifndef MCAL_GPIO_H
#define	MCAL_GPIO_H

/* Section: Includes */
#include <avr/io.h>
#include "../mcal_std_types.h"
#include "../device_config.h"
#include "mcal_gpio_cfg.h"
/* Section: Macro Declarations */
#define BIT_MASK (uint8)1
#define PORT_MASK 0xFF
#define MAX_PORTS_NUM 4
#define MAX_PINS_NUM 8
/* Section: Macro Functions Declarations */
#define HWREG8(_X) (*((volatile uint8*)_X))

#define SET_BIT(REG, BIT_POSN) (REG |= (BIT_MASK << BIT_POSN))
#define CLEAR_BIT(REG, BIT_POSN) (REG &= ~(BIT_MASK << BIT_POSN))
#define TOGGLE_BIT(REG, BIT_POSN) (REG ^= (BIT_MASK << BIT_POSN))
#define READ_BIT(REG, BIT_POSN) ((REG >> BIT_POSN) & BIT_MASK)

/* Section: Data Types Declarations */
typedef enum
{
    GPIO_INPUT,
    GPIO_OUTPUT
}direction_t;

typedef enum
{
    GPIO_LOW,
    GPIO_HIGH
}logic_t;

typedef enum
{
    PORTA_INDEX,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX
}port_index_t;

typedef enum
{
    PIN0_INDEX,
    PIN1_INDEX,
    PIN2_INDEX,
    PIN3_INDEX,
    PIN4_INDEX,
    PIN5_INDEX,
    PIN6_INDEX,
    PIN7_INDEX 
}pin_index_t;

typedef struct
{
    port_index_t port       :3; /* @ref port_index_t*/
    pin_index_t pin         :3; /* @ref pin_index_t*/
    direction_t direction   :1; /* @ref direction_t*/
    logic_t logic           :1; /* @ref logic_t*/
}pin_config_t;

/* Section: Functions Declarations */
Std_ReturnType GPIO_Pin_write_direction(const pin_config_t* pin_config);
Std_ReturnType GPIO_Pin_read_direction(const pin_config_t* pin_config,direction_t* direction_status);
Std_ReturnType GPIO_Pin_write_logic(const pin_config_t* pin_config, logic_t logic);
Std_ReturnType GPIO_Pin_read_logic(const pin_config_t* pin_config, logic_t* logic);
Std_ReturnType GPIO_Pin_toggle(const pin_config_t* pin_config);
Std_ReturnType GPIO_Pin_init(const pin_config_t* pin_config);



Std_ReturnType GPIO_PORT_write_direction(const port_index_t port, uint8 direction);
Std_ReturnType GPIO_PORT_read_direction(const port_index_t port, uint8* direction_status);
Std_ReturnType GPIO_PORT_write_logic(const port_index_t port, uint8 logic);
Std_ReturnType GPIO_PORT_read_logic(const port_index_t port, uint8* logic_status);
Std_ReturnType GPIO_PORT_toggle(const port_index_t port);


#endif	/* MCAL_GPIO_H */

