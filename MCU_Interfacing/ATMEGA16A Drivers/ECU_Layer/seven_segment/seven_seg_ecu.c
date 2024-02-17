/* 
 * File:   seven_seg_ecu.c
 * Author: moham
 *
 * Created on February 17, 2024, 9:10 PM
 */

#include "seven_seg_ecu.h"

Std_ReturnType seven_segment_initialize(const segment_t* seg){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == seg)
    {
        ret = E_NOT_OK;
    }
    else
    {
        GPIO_Pin_init(&(seg->segment_pins[SEGMENT_PIN0]));
        GPIO_Pin_init(&(seg->segment_pins[SEGMENT_PIN1]));
        GPIO_Pin_init(&(seg->segment_pins[SEGMENT_PIN2]));
        GPIO_Pin_init(&(seg->segment_pins[SEGMENT_PIN3]));
    }
    return ret;
}


Std_ReturnType seven_segment_write_number(const segment_t* seg, uint8 number){
    Std_ReturnType ret = E_NOT_OK;
    if((NULL == seg) || (number > 9))
    {
        ret = E_NOT_OK;
    }
    else
    {
        GPIO_Pin_write_logic(&(seg->segment_pins[SEGMENT_PIN0]), READ_BIT(number, 0));
        GPIO_Pin_write_logic(&(seg->segment_pins[SEGMENT_PIN1]), READ_BIT(number, 1));
        GPIO_Pin_write_logic(&(seg->segment_pins[SEGMENT_PIN2]), READ_BIT(number, 2));
        GPIO_Pin_write_logic(&(seg->segment_pins[SEGMENT_PIN3]), READ_BIT(number, 3));
    }
    return ret;
}