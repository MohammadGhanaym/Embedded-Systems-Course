/* 
 * File:   ecu_dc_motor.h
 * Author: moham
 *
 * Created on January 27, 2024, 4:50 PM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

/* Section: Includes */
#include "ecu_dc_motor_cfg.h"
#include "../../MCAL_Layer/GPIO/mcal_gpio.h"

/* Section: Macro Declarations */
#define MOTOR_ON_STATUS 0X01U
#define MOTOR_OFF_STATUS 0X00U

#define MOTOR_PIN1 0X00U
#define MOTOR_PIN2 0X01U
/* Section: Macro Functions Declarations */

/* Section: Data Types Declarations */
typedef struct
{
    pin_config_t motor_pins[2];
}dc_motor_t;

/* Section: Functions Declarations */
/**
 * @brief initialize the pins of the motor to be output
 * @param _dc_motor pointer to the motor configurations
 * @return the function status
 */
Std_ReturnType dc_motor_init(const dc_motor_t* _dc_motor);

/**
 * @brief move the motor to the right
 * @param _dc_motor pointer to the motor configurations
 * @return the function status
 */
Std_ReturnType dc_motor_move_right(const dc_motor_t* _dc_motor);

/**
 * @brief move the motor to the left
 * @param _dc_motor pointer to the motor configurations
 * @return the function status
 */
Std_ReturnType dc_motor_move_left(const dc_motor_t* _dc_motor);

/**
 * @brief stop the motor
 * @param _dc_motor pointer to the motor configurations
 * @return the function status
 */
Std_ReturnType dc_motor_stop(const dc_motor_t* _dc_motor);

#endif	/* ECU_DC_MOTOR_H */

