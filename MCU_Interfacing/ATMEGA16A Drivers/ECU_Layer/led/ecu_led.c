/* 
 * File:   led.h
 * Author: moham
 *
 * Created on September 28, 2023, 1:01 PM
 */

#include "ecu_led.h"

/**
 * @brief initialize the assigned pin to output and turn the led off
 * @param led pointer to the led configuration
 * @return return the status of the function
 */
Std_ReturnType led_init(const led_t*led){
    Std_ReturnType ret = E_OK;
    if(NULL == led)
    {
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin = {.port = led->port_name, .pin = led->pin, .direction = GPIO_OUTPUT, .logic = led->led_status};
        GPIO_Pin_init(&pin);
    }
    return ret;
}

/**
 * @brief turn the led on
 * @param led pointer to the led configuration
 * @return return the status of the function
 */
Std_ReturnType led_turn_on(const led_t*led){
    Std_ReturnType ret = E_OK;
    if(NULL == led)
    {
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin = {.port = led->port_name, .pin = led->pin, .direction = GPIO_OUTPUT, .logic = led->led_status};
        GPIO_Pin_write_logic(&pin, GPIO_HIGH);   
    }
    return ret;
}

/**
 * @brief turn the led off
 * @param led pointer to the led configuration
 * @return return the status of the function
 */
Std_ReturnType led_turn_off(const led_t*led){
    Std_ReturnType ret = E_OK;
    if(NULL == led)
    {
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin = {.port = led->port_name, .pin = led->pin, .direction = GPIO_OUTPUT, .logic = led->led_status};
        GPIO_Pin_write_logic(&pin, GPIO_LOW);    
    }
    return ret;
}

/**
 * @brief toggle the state of the led
 * @param led pointer to the led configuration
 * @return return the status of the function
 */
Std_ReturnType led_toggle(const led_t*led){
    Std_ReturnType ret = E_OK;
    if(NULL == led)
    {
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin = {.port = led->port_name, .pin = led->pin, .direction = GPIO_OUTPUT, .logic = led->led_status};
        GPIO_Pin_toggle(&pin);     
    }
    return ret;
}
         
         
