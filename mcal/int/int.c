#include "int.h"
#include "int_private.h"

#ifdef INTERRUPT_PRIO_ENABLE 

void __interrupt() InterruptManagerHigh(void)
{
    if( 1 == INTCONbits->INT0IE && 1 == INTCONbits->INT0IF) 
    {
        INTCONbits->INT0IF = 0;
        INT0_ISR();
    }
    else {/*NOTHING*/}
    if( 1 == INTCON3bits->INT1IE && 1 == INTCON3bits->INT1IF) 
    {
        INTCON3bits->INT1IF = 0;
        INT1_ISR();
    }
    else {/*NOTHING*/}
    
}
void __interrupt(low_priority) InterruptManagerLow(void)
{
    if( 1 == INTCON3bits->INT2IE && 1 == INTCON3bits->INT2IF) 
    {
        INTCON3bits->INT2IF = 0;
        INT2_ISR();
    }
    else {/*NOTHING*/}
}

#else

void __interrupt() InterruptManager(void)
{
    if( 1 == INTCONbits->INT0IE && 1 == INTCONbits->INT0IF) 
    {
        INTCONbits->INT0IF = 0;
        INT0_ISR();
    }
    else {/*NOTHING*/}
    if( 1 == INTCON3bits->INT1IE && 1 == INTCON3bits->INT1IF) 
    {
        INTCON3bits->INT1IF = 0;
        INT1_ISR();
    }
    else {/*NOTHING*/}
    if( 1 == INTCON3bits->INT2IE && 1 == INTCON3bits->INT2IF) 
    {
        INTCON3bits->INT2IF = 0;
        INT2_ISR();
    }
    else {/*NOTHING*/}
    
}
#endif

Std_ReturnType int_global_init_enable(void)
{
#ifdef INTERRUPT_PRIO_ENABLE
    INT_PRIO_ENABLE();
    INT_GLOBAL_HPRIO_ENABLE();
    INT_GLOBAL_LPRIO_ENABLE();
#else
    INT_PRIO_DISABLE();
    INT_GLOBAL_ENABLE();
    INT_PERIPHERAL_ENABLE();
#endif
    return E_OK;
}

