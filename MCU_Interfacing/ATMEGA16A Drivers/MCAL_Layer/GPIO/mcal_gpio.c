/* 
 * File:   mcal_gpio.c
 * Author: moham
 *
 * Created on September 28, 2023, 12:49 PM
 */
#include "mcal_gpio.h"

volatile  uint8* ddr_registers[] = {&DDRA, &DDRB, &DDRC, &DDRD};
volatile  uint8* port_registers[] = {&PORTA, &PORTB, &PORTC, &PORTD};
volatile  uint8* pin_registers[] = {&PINA, &PINB, &PINC, &PIND};


#if GPIO_PINS_CONFIG == CONFIG_ENABLE
/**
 * @brief specify the direction of a specific pin (input, or output)
 * @param pin_config a pointer to a struct of pin configuration @ref pin_config_t
 * @return the status of the function
 *      (E_OK) the function done successfully
 *      (E_NOT_OK) the function has failed
 */
Std_ReturnType GPIO_Pin_write_direction(const pin_config_t* pin_config){
    Std_ReturnType ret = E_OK;
    if((NULL == pin_config) || (pin_config->pin > MAX_PINS_NUM - 1) 
            || (pin_config->port > MAX_PORTS_NUM -1))
    {
        ret = E_NOT_OK;
    }else
    {
        switch(pin_config->direction)
        {
            case GPIO_OUTPUT:
                SET_BIT(*ddr_registers[pin_config->port], pin_config->pin);
                break;
            case GPIO_INPUT:
                CLEAR_BIT(*ddr_registers[pin_config->port], pin_config->pin);
                break;
            default:
                ret = E_NOT_OK;
        }
    }
    
    return ret;
}

/**
 * @brief read the direction of a specific pin
 * @param pin_config a pointer to a struct of pin configuration @ref pin_config_t
 * @param direction_status a pointer to return the pin direction @ref direction_t
 * @return the status of the function
 *      (E_OK) the function done successfully
 *      (E_NOT_OK) the function has failed
 */  
Std_ReturnType GPIO_Pin_read_direction(const pin_config_t* pin_config,direction_t* direction_status){
    Std_ReturnType ret = E_OK;
    if((NULL == pin_config) || (NULL == direction_status) 
            || (pin_config->pin > MAX_PINS_NUM - 1) || (pin_config->port > MAX_PORTS_NUM -1))
    {
        ret = E_NOT_OK;
    }else
    {
        *direction_status = READ_BIT(*ddr_registers[pin_config->port], pin_config->pin);
    }
    
    return ret;
}

/**
 * @brief write logic (low, or high) in a specific pin
 * @param pin_config a pointer to a struct of pin configuration @ref pin_config_t
 * @param logic a variable to specify the logic @ref logic_t
 * @return the status of the function
 *      (E_OK) the function done successfully
 *      (E_NOT_OK) the function has failed
 */
Std_ReturnType GPIO_Pin_write_logic(const pin_config_t* pin_config, logic_t logic){

    Std_ReturnType ret = E_OK;
    if((NULL == pin_config) || (pin_config->pin > MAX_PINS_NUM - 1)
            || (pin_config->port > MAX_PORTS_NUM -1))
    {
        ret = E_NOT_OK;
    }else
    {
        switch(logic)
        {
            case GPIO_HIGH:
                SET_BIT(*port_registers[pin_config->port], pin_config->pin);
                break;
            case GPIO_LOW:
                CLEAR_BIT(*port_registers[pin_config->port], pin_config->pin);
                break;
            default:
                ret = E_NOT_OK;
        }
    }
    return ret;
}

/**
 * @ read the logic of a specific pin
 * @param pin_config a pointer to a struct of pin configuration @ref pin_config_t
 * @param logic a pointer to return the logic @ref logic_t
 * @return the status of the function
 *      (E_OK) the function done successfully
 *      (E_NOT_OK) the function has failed
 */ 
Std_ReturnType GPIO_Pin_read_logic(const pin_config_t* pin_config, logic_t* logic){
    Std_ReturnType ret = E_OK;
    if((NULL == pin_config) || (NULL == logic) || (pin_config->pin > MAX_PINS_NUM - 1)
            || (pin_config->port > MAX_PORTS_NUM -1))
    {
        ret = E_NOT_OK;
    }else
    {
        *logic = READ_BIT(*pin_registers[pin_config->port], pin_config->pin);
    }
    return ret;
}


/**
 * @brief toggle the logic of a specific pin
 * @param pin_config a pointer to a struct of pin configuration @ref pin_config_t
 * @return the status of the function
 *      (E_OK) the function done successfully
 *      (E_NOT_OK) the function has failed
 */ 
Std_ReturnType GPIO_Pin_toggle(const pin_config_t* pin_config){
    Std_ReturnType ret = E_OK;
    if((NULL == pin_config) || (pin_config->pin > MAX_PINS_NUM - 1)
            || (pin_config->port > MAX_PORTS_NUM -1))
    {
        ret = E_NOT_OK;
    }else
    {
        TOGGLE_BIT(*port_registers[pin_config->port], pin_config->pin);
    }
    return ret;
}

/**
 * @brief initialize a specific pin
 * @param pin_config a pointer to a struct of pin configuration @ref pin_config_t
 * @return the status of the function
 *      (E_OK) the function done successfully
 *      (E_NOT_OK) the function has failed
 */ 

Std_ReturnType GPIO_Pin_init(const pin_config_t* pin_config){
    Std_ReturnType ret = E_OK;
    if((NULL == pin_config) || (pin_config->pin > MAX_PINS_NUM - 1)
            || (pin_config->port > MAX_PORTS_NUM -1)|| (pin_config->port > MAX_PORTS_NUM -1))
    {
        ret = E_NOT_OK;
    }else
    {
        GPIO_Pin_write_direction(pin_config);
        GPIO_Pin_write_logic(pin_config, GPIO_LOW);
    }
    return ret;
}
#endif


#if GPIO_PORTS_CONFIG == CONFIG_ENABLE
/**
 * @brief write direction of a specific port 
 * @param port a variable specify port index @ref port_index_t
 * @param direction a variable to specify the direction of the port
 * @return the status of the function
 *      (E_OK) the function done successfully
 *      (E_NOT_OK) the function has failed
 */ 
Std_ReturnType GPIO_PORT_write_direction(const port_index_t port, uint8 direction){
    Std_ReturnType ret = E_OK;
    if(port > MAX_PORTS_NUM - 1)
    {
        ret = E_NOT_OK;
    }else
    {
        *ddr_registers[port] = direction;
    }
    return ret;
}

/**
 * @brief read the direction of a specific port
 * @param port a variable specify port index @ref port_index_t
 * @param direction_status a pointer to return the direction of the port
 * @return the status of the function
 *      (E_OK) the function done successfully
 *      (E_NOT_OK) the function has failed
 */ 
Std_ReturnType GPIO_PORT_read_direction(const port_index_t port, uint8* direction_status){
    Std_ReturnType ret = E_OK;
    if((port > MAX_PORTS_NUM - 1) || (NULL == direction_status))
    {
        ret = E_NOT_OK;
    }else
    {
        *direction_status = *ddr_registers[port];
    }
    return ret;
}

/**
 * @brief write logic of a specific port
 * @param port a variable specify port index @ref port_index_t
 * @param logic a variable to specify the logic of a port
 * @return the status of the function
 *      (E_OK) the function done successfully
 *      (E_NOT_OK) the function has failed
 */ 
Std_ReturnType GPIO_PORT_write_logic(const port_index_t port, uint8 logic){
    Std_ReturnType ret = E_OK;
    if(port > MAX_PORTS_NUM - 1)
    {
        ret = E_NOT_OK;
    }else
    {   
        *port_registers[port] = logic;
    }
    return ret;
}

/**
 * @brief read the logic of a specific port
 * @param port a variable specify port index @ref port_index_t
 * @param logic_status a pointer to return the logic of the port
 * @return the status of the function
 *      (E_OK) the function done successfully
 *      (E_NOT_OK) the function has failed
 */ 
Std_ReturnType GPIO_PORT_read_logic(const port_index_t port, uint8* logic_status){
    Std_ReturnType ret = E_OK;
    if((port > MAX_PORTS_NUM - 1) || (NULL == logic_status))
    {
        ret = E_NOT_OK;
    }else
    {
       *logic_status = *pin_registers[port]; 
    }
    return ret;
}

/**
 * @toggle the logic of a specific port
 * @param port a variable specify port index @ref port_index_t
 * @return the status of the function
 *      (E_OK) the function done successfully
 *      (E_NOT_OK) the function has failed
 */ 
Std_ReturnType GPIO_PORT_toggle(const port_index_t port){
    Std_ReturnType ret = E_OK;
    if(port > MAX_PORTS_NUM - 1)
    {
        ret = E_NOT_OK;
    }else
    {
        *port_registers[port] ^= PORT_MASK;
    }
    return ret;
}

#endif