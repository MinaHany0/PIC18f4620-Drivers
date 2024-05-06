/* 
 * File:   int_private.h
 * Author: Mina
 *
 * Created on April 14, 2024, 10:32 PM
 */

#ifndef INT_PRIVATE_H
#define	INT_PRIVATE_H

#include "common.h" 


/**********************************INTCON Register******************************/
typedef union 
{
    struct 
    {
        uint8_t RBIF        : 1;
        uint8_t INT0IF      : 1;
        uint8_t TMR0IF      : 1;
        uint8_t RBIE        : 1;
        uint8_t INT0IE      : 1;
        uint8_t TMR0IE      : 1;
        uint8_t PIE_GIEL    : 1;
        uint8_t GIE_GIEH    : 1;
    };
    uint8_t INTCON;
}INTCONbits_t;

/**********************************INTCON2 Register******************************/
typedef union 
{
    struct 
    {
        uint8_t RBIP        :1;
        uint8_t reserved1   :1;
        uint8_t TMR0IP      :1;
        uint8_t reserved2   :1;
        uint8_t INTEDG2     :1;
        uint8_t INTEDG1     :1;
        uint8_t INTEDG0     :1;
        uint8_t RBPU        :1;
    };
    uint8_t INTCON2;
}INTCON2bits_t;

/**********************************INTCON3 Register******************************/
typedef union 
{
    struct 
    {
        uint8_t INT1IF      :1;
        uint8_t INT2IF      :1;
        uint8_t reserved0   :1;
        uint8_t INT1IE      :1;
        uint8_t INT2IE      :1;
        uint8_t reserved1   :1;
        uint8_t INT1IP      :1;
        uint8_t INT2IP      :1;
    };
    uint8_t INTCON3;
}INTCON3bits_t;

/**********************************RCON Register********************************/
typedef union 
{
    struct 
    {
        uint8_t BOR :1;
        uint8_t POR :1;
        uint8_t PD :1;
        uint8_t TO :1;
        uint8_t RI :1;
        uint8_t reserved :1;
        uint8_t SBOREN :1;
        uint8_t IPEN :1;
    };
    uint8_t RCON;
}RCONbits_t;

/**********************************PIR1 Register******************************/
typedef union 
{
    struct
    {
        uint8_t TMR1IF :1;
        uint8_t TMR2IF :1;
        uint8_t CCP1IF :1;
        uint8_t SSPIF  :1;
        uint8_t TXIF   :1;
        uint8_t RCIF   :1;
        uint8_t ADIF   :1;
        uint8_t PSPIF  :1;
    };
    uint8_t PIR1;
}PIR1bits_t;

/**********************************PIR2 Register******************************/
typedef union 
{
    struct
    {
        uint8_t CCP2IF :1;
        uint8_t TMR3IF :1;
        uint8_t HLVDIF :1;
        uint8_t BCLIF  :1;
        uint8_t EEIF   :1;
        uint8_t reserved :1;
        uint8_t CMIF    :1;
        uint8_t OSCFIF  :1;
    };
    uint8_t PIR2;
}PIR2bits_t;

/**********************************PIE1 Register******************************/
typedef union 
{
    struct 
    {
        uint8_t TMR1IE  :1;
        uint8_t TMR2IE  :1;
        uint8_t CCP1IE  :1;
        uint8_t SSPIE   :1;
        uint8_t TXIE    :1;
        uint8_t RCIE    :1;
        uint8_t ADIE    :1;
        uint8_t PSPIE   :1;
    };
    uint8_t PIE1;    
}PIE1bits_t;

/**********************************PIE2 Register******************************/
typedef union 
{
    struct 
    {
        uint8_t CCP2IE :1;
        uint8_t TMR3IE :1;
        uint8_t HLVDIE :1;
        uint8_t BCLIE  :1;
        uint8_t EEIE   :1;
        uint8_t reserved :1;
        uint8_t CMIE    :1;
        uint8_t OSCFIE  :1;

    };
    uint8_t PIE2;
}PIE2bits_t;

/**********************************IPR1 Register******************************/
typedef union
{
    struct 
    {
        uint8_t TMR1IP :1;
        uint8_t TMR2IP :1;
        uint8_t CCP1IP :1;
        uint8_t SSPIP  :1;
        uint8_t TXIP   :1;
        uint8_t RCIP   :1;
        uint8_t ADIP   :1;
        uint8_t PSPIP  :1; 
    };
    uint8_t IPR1;   
}IPR1bits_t;

/**********************************IPR2 Register******************************/
typedef union 
{
    struct 
    {
        uint8_t CCP2IE :1;
        uint8_t TMR3IP :1;
        uint8_t HLVDIP :1;
        uint8_t BCLIP  :1;
        uint8_t EEIP   :1;
        uint8_t reserved :1;
        uint8_t CMIP   :1;
        uint8_t OSCFIP :1;
    };
    uint8_t IPR2;    
}IPR2bits_t;

volatile INTCONbits_t *INTCONbits =         ((volatile INTCONbits_t* )0x0FF2);
volatile INTCON2bits_t *INTCON2bits =       ((volatile INTCON2bits_t*)0x0FF1);
volatile INTCON3bits_t *INTCON3bits =       ((volatile INTCON3bits_t*)0x0FF0);
volatile RCONbits_t *RCONbits=              ((volatile RCONbits_t*   )0x0FD0);
volatile PIR1bits_t *PIR1bits =             ((volatile PIR1bits_t*   )0x0F9E);
volatile PIR2bits_t *PIR2bits =             ((volatile PIR2bits_t*   )0x0FA1);
volatile PIE1bits_t *PIE1bits =             ((volatile PIE1bits_t*   )0x0F9D);
volatile PIE2bits_t *PIE2bits =             ((volatile PIE2bits_t*   )0x0FA0);
volatile IPR1bits_t *IPR1bits =             ((volatile IPR1bits_t*   )0x0F9F);
volatile IPR2bits_t *IPR2bits =             ((volatile IPR2bits_t*   )0x0FA2);

#endif	/* INT_PRIVATE_H */

