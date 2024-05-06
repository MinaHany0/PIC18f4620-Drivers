#include "led.h"


Std_ReturnType led_init(led_typedef *_led)
{
    Std_ReturnType ret = E_OK;
    if(NULL == _led)
    {
        ret |= E_NOT_OK;
    }
    else
    {
        gpio_pin_typedef _pin;
        _pin.port = _led->port;
        _pin.pin  = _led->pin;
        _pin.dir = GPIO_DIR_OUT;
        _pin.logic = (GPIO_LOGIC_T)(_led->state);
        
        ret |= gpio_pin_init(&_pin);
    }
    return ret;        
}
Std_ReturnType led_off(led_typedef *_led)
{
    Std_ReturnType ret = E_OK;
    if(NULL == _led)
    {
        ret |= E_NOT_OK;
    }
    else
    {
        gpio_pin_typedef _pin;
        _pin.port = _led->port;
        _pin.pin  = _led->pin;
        _pin.dir = GPIO_DIR_OUT;
        _pin.logic = (GPIO_LOGIC_T)(_led->state);
        
        ret |= gpio_pin_set_logic(&_pin , GPIO_LOGIC_LOW);
        if(E_OK == ret)
        {
            _led->state = LED_OFF;
        }
        else
        {
            ret |= E_NOT_OK;
        }
    }
    return ret;  
}

Std_ReturnType led_on(led_typedef *_led)
{
    Std_ReturnType ret = E_OK;
    if(NULL == _led)
    {
        ret |= E_NOT_OK;
    }
    else
    {
        gpio_pin_typedef _pin;
        _pin.port = _led->port;
        _pin.pin  = _led->pin;
        _pin.dir = GPIO_DIR_OUT;
        _pin.logic = (GPIO_LOGIC_T)(_led->state);
        
        ret |= gpio_pin_set_logic(&_pin , GPIO_LOGIC_HIGH);
        if(E_OK == ret)
        {
            _led->state = LED_ON;
        }
        else
        {
            ret |= E_NOT_OK;
        }
    }
    return ret;  
}
Std_ReturnType led_toggle(led_typedef *_led)
{
    Std_ReturnType ret = E_OK;
    if(NULL == _led)
    {
        ret |= E_NOT_OK;
    }
    else
    {
        gpio_pin_typedef _pin;
        _pin.port = _led->port;
        _pin.pin  = _led->pin;
        _pin.dir = GPIO_DIR_OUT;
        _pin.logic = (GPIO_LOGIC_T)(_led->state);
        
        ret |= gpio_pin_toggle_logic(&_pin);
        
        if(E_OK == ret)
        {
            if(LED_OFF == _led->state)
            {
                _led->state = LED_ON;
            }
            else
            {
                _led->state = LED_OFF;
            }
        }
        else
        {
            /*DO NOTHING AS RET IS ALREADY E_NOT_OK*/
        }
    }
    return ret;  
}