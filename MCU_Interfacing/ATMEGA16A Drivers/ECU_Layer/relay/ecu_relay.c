/* 
 * File:   ecu_relay.c
 * Author: moham
 *
 * Created on January 25, 2024, 2:37 PM
 */


#include "ecu_relay.h"



/**
 * @brief define the relay pin to be output and turn it on or off
 * @param relay pointer to the relay configurations
 * @return the status of the function
 *      (E_OK):     function done successfully
 *      (E_NOT_OK): function failed
 */
Std_ReturnType relay_init(const relay_t* relay){
    Std_ReturnType ret = E_OK;
    if(NULL == relay)
    {
        ret = E_NOT_OK;
    }
    else
    {
        pin_config_t pin_obj = {.port = relay->port, .pin = relay->pin, .direction = GPIO_OUTPUT, .logic = relay->status};
        GPIO_Pin_init(&pin_obj);
    }
    return ret;
}
/**
 * @brief turn relay on
 * @param relay pointer to the relay configurations
 * @return the status of the function
 *      (E_OK):     function done successfully
 *      (E_NOT_OK): function failed
 */
Std_ReturnType relay_turn_on(const relay_t* relay){
    Std_ReturnType ret = E_OK;
    if(NULL == relay)
    {
        ret = E_NOT_OK;
    }
    else
    {
        pin_config_t pin_obj = {.port = relay->port, .pin = relay->pin, .direction = GPIO_OUTPUT, .logic = relay->status};
        GPIO_Pin_write_logic(&pin_obj, GPIO_HIGH);  
    }
    return ret;   
}
/**
 * @brief turn relay off
 * @param relay pointer to the relay configurations
 * @return the status of the function
 *      (E_OK):     function done successfully
 *      (E_NOT_OK): function failed
 */
Std_ReturnType relay_turn_off(const relay_t* relay){
    Std_ReturnType ret = E_OK;
    if(NULL == relay)
    {
        ret = E_NOT_OK;
    }
    else
    {
        pin_config_t pin_obj = {.port = relay->port, .pin = relay->pin, .direction = GPIO_OUTPUT, .logic = relay->status};
        GPIO_Pin_write_logic(&pin_obj, GPIO_LOW);
    }
    return ret;
}
