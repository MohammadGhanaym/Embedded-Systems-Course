/* 
 * File:   ecu_relay.c
 * Author: moham
 *
 * Created on January 25, 2024, 10:49 AM
 */
#include "ecu_relay.h"

/**
 * @brief initialize the relay pin to be output and turn the relay on or off
 * @param relay pointer to the relay configuration
 * @return the status of the function
 */
Std_ReturnType relay_init(const relay_t* relay){
    Std_ReturnType ret = E_OK;
    if(NULL == relay)
    {
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin_obj ={
        .port = relay->relay_port,
        .pin = relay->relay_pin,
        .direction = GPIO_OUTPUT,
        .logic = relay->relay_status 
        };
        gpio_pin_intialize(&pin_obj);
    }
    return ret;
}
/**
 * 
 * @brief turn the relay on
 * @param relay pointer to the relay configuration
 * @return the status of the function
 */
Std_ReturnType relay_turn_on(const relay_t* relay){
    Std_ReturnType ret = E_OK;
    if(NULL == relay)
    {
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin_obj ={
        .port = relay->relay_port,
        .pin = relay->relay_pin,
        .direction = GPIO_OUTPUT,
        .logic = relay->relay_status 
        };   
        
        gpio_pin_write_logic(&pin_obj, GPIO_HIGH);
    }
    return ret;  
}
/**
 * 
 * @brief turn the relay off
 * @param relay pointer to the relay configuration
 * @return the status of the function
 */
Std_ReturnType relay_turn_off(const relay_t* relay){
    Std_ReturnType ret = E_OK;
    if(NULL == relay)
    {
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin_obj ={
        .port = relay->relay_port,
        .pin = relay->relay_pin,
        .direction = GPIO_OUTPUT,
        .logic = relay->relay_status 
        }; 
        
        gpio_pin_write_logic(&pin_obj, GPIO_LOW);
    }
    return ret; 
}