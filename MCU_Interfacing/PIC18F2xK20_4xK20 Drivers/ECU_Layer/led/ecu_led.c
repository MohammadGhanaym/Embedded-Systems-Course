/* 
 * File:   ecu_led.c
 * Author: moham
 *
 * Created on September 17, 2023, 7:01 PM
 */
#include "ecu_led.h"

/**
 * @brief init the assigned pin to be output and turn the led off
 * @param led pointer to the led module configuration
 * @return status of the function
 */
Std_ReturnType led_init(const led_t* led){
    Std_ReturnType ret = E_OK;
    
    if(NULL == led)
    {
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin_obj = {
        .port = led->port_num, 
        .pin = led->pin, 
        .direction = GPIO_OUTPUT, 
        .logic = led->led_status
        };
        gpio_pin_intialize(&pin_obj);
    }
    return ret;
}

/**
 * @brief turn the led on
 * @param led pointer to the led module configuration
 * @return status of the function
 */
Std_ReturnType led_turn_on(const led_t* led){
    Std_ReturnType ret = E_OK;
    if(NULL == led)
    {
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin_obj = {
            .port = led->port_num, 
            .pin = led->pin, 
            .direction = GPIO_OUTPUT, 
            .logic = led->led_status
            };
        gpio_pin_write_logic(&pin_obj, GPIO_HIGH);
    }
    return ret;    
}

/**
 * @brief turn the led off
 * @param led pointer to the led module configuration
 * @return status of the function
 */
Std_ReturnType led_turn_off(const led_t* led){
    Std_ReturnType ret = E_OK;
    if(NULL == led)
    {
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin_obj = {
            .port = led->port_num, 
            .pin = led->pin, 
            .direction = GPIO_OUTPUT, 
            .logic = led->led_status
            };
        gpio_pin_write_logic(&pin_obj, GPIO_LOW);
    }
    return ret;    
}

/**
 * @brief toggle the led status
 * @param led pointer to the led module configuration
 * @return status of the function
 */
Std_ReturnType led_toggle(const led_t* led){
    Std_ReturnType ret = E_OK;
    if(NULL == led)
    {
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin_obj = {
            .port = led->port_num, 
            .pin = led->pin, 
            .direction = GPIO_OUTPUT, 
            .logic = led->led_status
            };
        gpio_pin_toggle_logic(&pin_obj);
    }
    return ret;    
}