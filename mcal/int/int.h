/* 
 * File:   int.h
 * Author: Mina
 *
 * Created on April 14, 2024, 9:52 PM
 */

#ifndef INT_H
#define	INT_H

#include "common.h"
#include "int_cfg.h"
#include "int_private.h"

/*************************TEMPLATE*********************************************/
/******************************************************************************/


/*************************PRIORITY ENABLE/DISABLE******************************/
#define INT_PRIO_ENABLE()                       (RCONbits->IPEN = 1)
#define INT_PRIO_DISABLE()                      (RCONbits->IPEN = 0)

/*************************ENABLING GLOBAL INTERRUPTS***************************/
#ifdef INTERRUPT_PRIO_ENABLE  
    #define INT_GLOBAL_HPRIO_ENABLE()           (INTCONbits->GIE_GIEH = 1)
    #define INT_GLOBAL_HPRIO_DISABLE()          (INTCONbits->GIE_GIEH = 0)
    #define INT_GLOBAL_LPRIO_ENABLE()           (INTCONbits->PIE_GIEL = 1)
    #define INT_GLOBAL_LPRIO_DISABLE()          (INTCONbits->PIE_GIEL = 0)
#else
    #define INT_GLOBAL_ENABLE()                 (INTCONbits->GIE_GIEH = 1)
    #define INT_GLOBAL_DISABLE()                (INTCONbits->GIE_GIEH = 0)
    #define INT_PERIPHERAL_ENABLE()             (INTCONbits->PIE_GIEL = 1)
    #define INT_PERIPHERAL_DISABLE()            (INTCONbits->PIE_GIEL = 0)
#endif

/*************************TEMPLATE*********************************************/
#define INT_TMR0_OVERFLOW_ENABLE()              (INTCONbits->TMR0IE)


Std_ReturnType int_global_init_enable(void);
void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);

#endif	/* INT_H */

    