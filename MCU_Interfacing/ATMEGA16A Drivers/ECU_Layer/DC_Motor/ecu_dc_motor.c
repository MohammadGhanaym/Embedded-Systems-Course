/* 
 * File:   ecu_dc_motor.c
 * Author: moham
 *
 * Created on January 27, 2024, 4:50 PM
 */

#include "ecu_dc_motor.h"


/**
 * @brief initialize the pins of the motor to be output and specify its initial state
 * @param _dc_motor pointer to the motor configurations
 * @return the function status
 */
Std_ReturnType dc_motor_init(const dc_motor_t* _dc_motor){
    Std_ReturnType ret = E_OK;
    if(NULL == _dc_motor)
    {
        ret = E_NOT_OK;
    }
    else
    {
        GPIO_Pin_init(&(_dc_motor->motor_pins[0]));
        GPIO_Pin_init(&(_dc_motor->motor_pins[1]));
    }
    return ret;
}

/**
 * @brief move the motor to the right
 * @param _dc_motor pointer to the motor configurations
 * @return the function status
 */
Std_ReturnType dc_motor_move_right(const dc_motor_t* _dc_motor){
    Std_ReturnType ret = E_OK;
    if(NULL == _dc_motor)
    {
        ret = E_NOT_OK;
    }
    else
    {
        GPIO_Pin_write_logic(&(_dc_motor->motor_pins[0]), GPIO_HIGH);
        GPIO_Pin_write_logic(&(_dc_motor->motor_pins[1]), GPIO_LOW);
    }
    return ret;
}

/**
 * @brief move the motor to the left
 * @param _dc_motor pointer to the motor configurations
 * @return the function status
 */
Std_ReturnType dc_motor_move_left(const dc_motor_t* _dc_motor){
    Std_ReturnType ret = E_OK;
    if(NULL == _dc_motor)
    {
        ret = E_NOT_OK;
    }
    else
    {
        GPIO_Pin_write_logic(&(_dc_motor->motor_pins[0]), GPIO_LOW);
        GPIO_Pin_write_logic(&(_dc_motor->motor_pins[1]), GPIO_HIGH);   
    }
    return ret;
}

/**
 * @brief stop the motor
 * @param _dc_motor pointer to the motor configurations
 * @return the function status
 */
Std_ReturnType dc_motor_stop(const dc_motor_t* _dc_motor){
    Std_ReturnType ret = E_OK;
    if(NULL == _dc_motor)
    {
        ret = E_NOT_OK;
    }
    else
    {
        GPIO_Pin_write_logic(&(_dc_motor->motor_pins[0]), GPIO_LOW);
        GPIO_Pin_write_logic(&(_dc_motor->motor_pins[1]), GPIO_LOW);   
    }
    return ret;
}