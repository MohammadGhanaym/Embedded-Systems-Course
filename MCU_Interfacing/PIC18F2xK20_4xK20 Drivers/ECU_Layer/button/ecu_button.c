/* 
 * File:   ecu_button.c
 * Author: moham
 *
 * Created on January 5, 2024, 6:15 PM
 */

#include "ecu_button.h"

/**
 * @brief initialize the assigned pin to be input
 * @param button pointer to the button configuration
 * @return the states of the function
 */
Std_ReturnType button_init(const button_t* button){
  Std_ReturnType ret = E_NOT_OK;
  if(NULL == button)
  {
      ret = E_NOT_OK;
  }else{
      gpio_pin_direction_intialize(&(button->btn_pin));
      ret = E_OK;
  }
  return ret;
}

/**
 * @brief read the states of the button
 * @param button pointer to the button configuration
 * @param button_state a pointer to catch the button state
 * @return the states of the function
 */
Std_ReturnType button_read_state(const button_t* button, button_state_t* button_state){
  Std_ReturnType ret = E_NOT_OK;
  if((NULL == button) || (NULL == button_state))
  {
      ret = E_NOT_OK;
  }else{
      logic_t pin_logic_status = GPIO_LOW;
      
      gpio_pin_read_logic(&(button->btn_pin), &pin_logic_status);
      
      if(BUTTON_ACTIVE_HIGH == button->button_connection)
      {
          if(GPIO_HIGH == pin_logic_status)
          {
              *button_state = BUTTON_PRESSED;
          }
          else
          {
              *button_state = BUTTON_RELEASED;
          }
      }
      else if(BUTTON_ACTIVE_LOW == button->button_connection){
          if(GPIO_LOW == pin_logic_status)
          {
              *button_state = BUTTON_PRESSED;
          }   
          else
          {
              *button_state = BUTTON_RELEASED;
          }
      }
      else{
          
      }
      ret = E_OK;
  }
  return ret;  
}