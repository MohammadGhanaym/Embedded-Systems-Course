/* 
 * File:   ecu_button.c
 * Author: moham
 *
 * Created on January 6, 2024, 1:02 PM
 */

#include "ecu_button.h"


/**
 * @brief initialize the assigned pin to be input
 * @param btn pointer to the button configuration
 * @return the state of the function
 */
Std_ReturnType btn_init(const btn_t* btn)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == btn)
    {
        ret = E_NOT_OK;
    }
    else
    {
        GPIO_Pin_init(&(btn->btn_pin));
        ret = E_OK;
    }
    return ret;
}
/**
 * 
 * @param btn pointer to the button configuration
 * @param btn_state pointer to catch the button state
 * @return the state of the function
 */
Std_ReturnType btn_read_state(const btn_t* btn, btn_state_t* btn_state)
{
    Std_ReturnType ret = E_NOT_OK;
    if((NULL == btn) || (NULL == btn_state))
    {
        ret = E_NOT_OK;
    }
    else
    {
        logic_t btn_logic = GPIO_LOW;
        GPIO_Pin_read_logic(&(btn->btn_pin), &btn_logic);
        if(BTN_ACTIVE_HIGH == btn->btn_connection)
        {
            if(GPIO_HIGH == btn_logic)
            {
                *btn_state = BTN_PRESSED;
            }
            else
            {
                *btn_state = BTN_RELEASED;
            }
        }
        else if(BTN_ACTIVE_LOW == btn->btn_connection)
        {
            if(GPIO_LOW == btn_logic)
            {
                *btn_state = BTN_PRESSED;
            }
            else
            {
                *btn_state = BTN_RELEASED;
            }  
        }
        else
        {
            /* Nothing */
        }
    }
    return ret; 
}