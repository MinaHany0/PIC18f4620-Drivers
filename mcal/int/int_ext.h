/* 
 * File:   int_ext.h
 * Author: Mina
 *
 * Created on May 3, 2024, 10:36 AM
 */

#ifndef INT_EXT_H
#define	INT_EXT_H

#include "int_private.h"
#include "int.h"

/*************************EXTERNAL INTERRUPT IDs*******************************/
typedef enum
{
    INT_EXT0_ID,
    INT_EXT1_ID,
    INT_EXT2_ID,
}INT_EXT_ID_t;

/*************************EXTERNAL INTERRUPT EDGE******************************/
typedef enum
{
    INT_FALLING_EDGE, 
    INT_RISING_EDGE,          
}INT_EXT_EDGE_t;

/*************************EXTERNAL INTERRUPT PRIO******************************/
typedef enum
{ 
    INT_PRIO_LOW,
    INT_PRIO_HIGH,          
}INT_EXT_PRIO_t;

/*************************EXTERNAL INTERRUPT STRUCTs***************************/
typedef struct
{
    INT_EXT_ID_t int_id;
    INT_EXT_EDGE_t edge;
#ifdef INTERRUPT_PRIO_ENABLE
    INT_EXT_PRIO_t prio;
#endif
    void (*callback)(void);
    
}int_external_t;

/*************************EXTERNAL INTERRUPT MACROS****************************/
#define INT_EXT0_ENABLE()                       (INTCONbits->INT0IE = 1)
#define INT_EXT0_DISABLE()                      (INTCONbits->INT0IE = 0)
#define INT_EXT0_FLAG_CLEAR()                   (INTCONbits->INT0IF = 0)

/*************************PORT B INTERRUPT ON CHANGE***************************/
#define INT_RB_CHANGE_ENABLE()                  (INTCONbits->RBIE = 1)
#define INT_RB_CHANGE_DISABLE()                 (INTCONbits->RBIE = 0)
#define INT_RB_CHANGE_FLAG_CLEAR()              (INTCONbits->RBIF = 0)
#define INT_PORT_B_INDIVIDUAL_PU_ENABLE()       (INTCON2bits->RBPU = 0)
#define INT_PORT_B_PULLUP_DISABLE()             (INTCON2bits->RBPU = 1)





Std_ReturnType int_ext_enable(int_external_t* int_ext );
Std_ReturnType int_ext_disable(int_external_t* int_ext );
Std_ReturnType int_ext_set_edge(int_external_t* int_ext );
Std_ReturnType int_ext_set_prio(int_external_t* int_ext );
Std_ReturnType int_ext_set_callback(int_external_t* int_ext );
Std_ReturnType int_ext_init(int_external_t* int_ext );

#endif	/* INT_EXT_H */

