/* 
 * File:   gpio.h
 * Author: Mina
 *
 * Created on April 14, 2024, 9:52 PM
 */

#ifndef GPIO_H
#define	GPIO_H

#include "common.h"

typedef enum
{
    GPIO_PORT_A,
    GPIO_PORT_B,
    GPIO_PORT_C,
    GPIO_PORT_D,
    GPIO_PORT_E,
}GPIO_PORT_T;

typedef enum
{
    GPIO_PIN_0,
    GPIO_PIN_1,
    GPIO_PIN_2,
    GPIO_PIN_3,
    GPIO_PIN_4,
    GPIO_PIN_5,
    GPIO_PIN_6,
    GPIO_PIN_7,
}GPIO_PIN_T;

typedef enum
{
    GPIO_DIR_OUT,      
    GPIO_DIR_IN ,      
}GPIO_DIR_T;

typedef enum
{     
    GPIO_LOGIC_LOW  , 
    GPIO_LOGIC_HIGH ,      
}GPIO_LOGIC_T;

typedef struct
{
    GPIO_PORT_T port;
    GPIO_PIN_T pin;
    GPIO_DIR_T dir;
    GPIO_LOGIC_T logic;
}gpio_pin_typedef;


typedef struct
{
    GPIO_PORT_T port;
    GPIO_DIR_T dir;
    GPIO_LOGIC_T logic;
}gpio_port_typedef;

Std_ReturnType GPIO_POR_Make_Pins_DIO(void);
Std_ReturnType gpio_pin_init(const gpio_pin_typedef *_pin);
Std_ReturnType gpio_pin_read(const gpio_pin_typedef *_pin , GPIO_LOGIC_T *_logic);
Std_ReturnType gpio_pin_toggle_logic(const gpio_pin_typedef *_pin);
Std_ReturnType gpio_pin_set_logic(const gpio_pin_typedef *_pin, GPIO_LOGIC_T _logic);
Std_ReturnType gpio_port_init(const gpio_port_typedef *_pin);
Std_ReturnType gpio_port_read(const gpio_port_typedef *_pin , uint8_t *_logic);



#endif	/* GPIO_H */

    