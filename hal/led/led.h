/* 
 * File:   led.h
 * Author: Mina
 *
 * Created on April 17, 2024, 7:31 AM
 */

#ifndef LED_H
#define	LED_H

#include "gpio.h"

typedef enum
{
    LED_OFF,
    LED_ON,
}LED_STATE_T;

typedef struct
{
    GPIO_PORT_T port;
    GPIO_PIN_T pin;
    LED_STATE_T state;
}led_typedef;


Std_ReturnType led_init(led_typedef *_led);
Std_ReturnType led_off(led_typedef *_led);
Std_ReturnType led_on(led_typedef *_led);
Std_ReturnType led_toggle(led_typedef *_led);
#endif	/* LED_H */

