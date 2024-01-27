/* 
 * File:   ecu_dc_motor.c
 * Author: moham
 *
 * Created on January 27, 2024, 10:52 AM
 */


#include "ecu_dc_motor.h"

Std_ReturnType dc_motor_init(const dc_motor_t* _dc_motor){
   Std_ReturnType ret = E_OK;
   if(NULL == _dc_motor)
   {
       ret = E_NOT_OK;
   }
   else
   {
      
        
        gpio_pin_intialize(&(_dc_motor->motor_pins[DC_MOTOR_PIN1]));
        gpio_pin_intialize(&(_dc_motor->motor_pins[DC_MOTOR_PIN2]));
   }
   return ret;
}
Std_ReturnType dc_motor_move_right(const dc_motor_t* _dc_motor){
   Std_ReturnType ret = E_OK;
   if(NULL == _dc_motor)
   {
       ret = E_NOT_OK;
   }
   else
   {
       gpio_pin_write_logic(&(_dc_motor->motor_pins[DC_MOTOR_PIN1]), GPIO_HIGH);
       gpio_pin_write_logic(&(_dc_motor->motor_pins[DC_MOTOR_PIN2]), GPIO_LOW);
   }
   return ret;  
}
Std_ReturnType dc_motor_move_left(const dc_motor_t* _dc_motor){
   Std_ReturnType ret = E_OK;
   if(NULL == _dc_motor)
   {
       ret = E_NOT_OK;
   }
   else
   {
       gpio_pin_write_logic(&(_dc_motor->motor_pins[DC_MOTOR_PIN1]), GPIO_LOW);
       gpio_pin_write_logic(&(_dc_motor->motor_pins[DC_MOTOR_PIN2]), GPIO_HIGH); 
   }
   return ret; 
}
Std_ReturnType dc_motor_stop(const dc_motor_t* _dc_motor){
   Std_ReturnType ret = E_OK;
   if(NULL == _dc_motor)
   {
       ret = E_NOT_OK;
   }
   else
   {
       gpio_pin_write_logic(&(_dc_motor->motor_pins[DC_MOTOR_PIN1]), GPIO_LOW);
       gpio_pin_write_logic(&(_dc_motor->motor_pins[DC_MOTOR_PIN2]), GPIO_LOW);
   }
   return ret; 
}