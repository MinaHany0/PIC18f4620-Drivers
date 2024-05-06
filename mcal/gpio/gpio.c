#include "gpio.h"
#include "gpio_private.h"


Std_ReturnType GPIO_POR_Make_Pins_DIO(void)
{
    ADCON1 |= 0x0F;
    return E_OK;
}

Std_ReturnType gpio_pin_init(const gpio_pin_typedef *_pin)
{
    Std_ReturnType ret = E_OK;
    if(NULL == _pin)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(_pin->dir == GPIO_DIR_IN)
        {
            MAP_TRIS_REG(_pin->port) |= ( 1 << _pin->pin); 
        }
        else if(_pin->dir == GPIO_DIR_OUT)
        {
            MAP_TRIS_REG(_pin->port) &=~ ( 1 << _pin->pin);            
        }
        ret |= gpio_pin_set_logic( _pin, _pin->logic);
    }
    return ret;
}

Std_ReturnType gpio_pin_read(const gpio_pin_typedef *_pin , GPIO_LOGIC_T *_logic)
{
    Std_ReturnType ret = E_OK;
    if(NULL == _pin || NULL == _logic)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *_logic = ((MAP_PORT_REG(_pin->port) >> _pin->pin) & 0x01);
    }
    return ret;
}

Std_ReturnType gpio_pin_toggle_logic(const gpio_pin_typedef *_pin)
{
    Std_ReturnType ret = E_OK;
    if(NULL == _pin)
    {
        ret = E_NOT_OK;
    }
    else
    {
        MAP_LAT_REG(_pin->port) ^= ( 1 << _pin->pin);
    }
    return ret;
}

Std_ReturnType gpio_pin_set_logic(const gpio_pin_typedef *_pin, GPIO_LOGIC_T _logic)
{
    Std_ReturnType ret = E_OK;
    if(NULL == _pin)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(GPIO_LOGIC_HIGH == _logic)
        {
            MAP_LAT_REG(_pin->port) |= ( 1 << _pin->pin);
        }
        else if(GPIO_LOGIC_LOW == _logic)
        {
            MAP_LAT_REG(_pin->port) &=~ ( 1 << _pin->pin);
        }
    }
    return ret;
}

Std_ReturnType gpio_port_init(const gpio_port_typedef *_port)
 {
    Std_ReturnType ret = E_OK;
    if(NULL == _port)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(GPIO_DIR_OUT == _port->dir)
        {
            MAP_TRIS_REG(_port->port) = 0x00;
            MAP_LAT_REG(_port->port)  = _port->logic;
        }
        else if(GPIO_DIR_IN == _port->dir)
        {
            MAP_TRIS_REG(_port->port) = 0xFF;
        }
    }
    return ret;
 }

Std_ReturnType gpio_port_read(const gpio_port_typedef *_port , uint8_t *_logic)
 {
    Std_ReturnType ret = E_OK;
    if(NULL == _port || NULL == _logic)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *_logic = MAP_PORT_REG(_port->port);
    }
    return ret;
 }