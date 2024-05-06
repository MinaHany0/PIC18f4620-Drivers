/* 
 * File:   int_ext.c
 * Author: Mina
 *
 * Created on May 3, 2024, 10:36 AM
 */

#include "int_ext.h"

void (*INT_EXT0_INTERRUPT_HANDLER)(void);
void (*INT_EXT1_INTERRUPT_HANDLER)(void);
void (*INT_EXT2_INTERRUPT_HANDLER)(void);


Std_ReturnType int_ext_enable(int_external_t* int_ext )
{
    Std_ReturnType ret = E_OK;
    if(NULL == int_ext)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(int_ext->int_id)
        {
            case INT_EXT0_ID:
                INTCONbits->INT0IE = 1;
                break;
            case INT_EXT1_ID:
                INTCON3bits->INT1IE = 1;
                break;
            case INT_EXT2_ID:
                INTCON3bits->INT2IE = 1;
                break;
            default:
                ret = E_NOT_OK;
                break;
        }
    }
    return ret;
}

Std_ReturnType int_ext_disable(int_external_t* int_ext)
{
    Std_ReturnType ret = E_OK;
    if(NULL == int_ext)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(int_ext->int_id)
        {
            case INT_EXT0_ID:
                INTCONbits->INT0IE = 0;
                break;
            case INT_EXT1_ID:
                INTCON3bits->INT1IE = 0;
                break;
            case INT_EXT2_ID:
                INTCON3bits->INT2IE = 0;
                break;
            default:
                ret = E_NOT_OK;
                break;
        }
    }
    return ret;
}

Std_ReturnType int_ext_set_edge(int_external_t* int_ext )
{
    Std_ReturnType ret = E_OK;
    if( NULL == int_ext)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(int_ext->int_id)
        {
            case INT_EXT0_ID:
                INTCON2bits->INTEDG0 = int_ext->edge;
                break;
            case INT_EXT1_ID:
                INTCON2bits->INTEDG1 = int_ext->edge;
                break;
            case INT_EXT2_ID:
                INTCON2bits->INTEDG2 = int_ext->edge;
                break;
            default:
                ret = E_NOT_OK;
                break;
        }
    }
    return ret;
}

Std_ReturnType int_ext_set_prio(int_external_t* int_ext )
{
    Std_ReturnType ret = E_OK;
    if( NULL == int_ext)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(int_ext->int_id)
        {
            case INT_EXT0_ID:
                /* ALWAYS HIGH PRIO BY HW */
                break;
            case INT_EXT1_ID:
                INTCON3bits->INT1IP = int_ext->prio;
                break;
            case INT_EXT2_ID:
                INTCON3bits->INT2IP = int_ext->prio;
                break;
            default:
                ret = E_NOT_OK;
                break;
        }
    }
    return ret;
}

Std_ReturnType int_ext_set_callback(int_external_t* int_ext )
{
    Std_ReturnType ret = E_OK;
    if( NULL == int_ext)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(int_ext->int_id)
        {
            case INT_EXT0_ID:
                INT_EXT0_INTERRUPT_HANDLER = int_ext->callback;
                break;
            case INT_EXT1_ID:
                INT_EXT1_INTERRUPT_HANDLER = int_ext->callback;
                break;
            case INT_EXT2_ID:
                INT_EXT2_INTERRUPT_HANDLER = int_ext->callback;
                break;
            default:
                ret = E_NOT_OK;
                break;
        }
    }
    return ret;
}

Std_ReturnType int_ext_init(int_external_t* int_ext )
{
    Std_ReturnType ret = E_OK;
    if(NULL == int_ext)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret |= int_ext_enable(int_ext );
        ret |= int_ext_set_edge(int_ext );
#ifdef INTERRUPT_PRIO_ENABLE
        ret |= int_ext_set_prio(int_ext );
#endif
        ret |= int_ext_set_callback(int_ext );
    }
    return ret;
}


void INT0_ISR(void)
{
 if( INT_EXT0_INTERRUPT_HANDLER )   
 {
    INT_EXT0_INTERRUPT_HANDLER();
 }
}
void INT1_ISR(void)
{
 if( INT_EXT1_INTERRUPT_HANDLER )   
 {
    INT_EXT1_INTERRUPT_HANDLER();
 }
}

void INT2_ISR(void)
{
 if( INT_EXT2_INTERRUPT_HANDLER )   
 {
    INT_EXT2_INTERRUPT_HANDLER();
 }
}