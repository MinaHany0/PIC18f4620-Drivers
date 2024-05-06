/* 
 * File:   gpio_private.h
 * Author: Mina
 *
 * Created on April 14, 2024, 10:32 PM
 */

#ifndef GPIO_PRIVATE_H
#define	GPIO_PRIVATE_H


#define PORTA               (*((volatile uint8_t*)0x0F80))
#define PORTB               (*((volatile uint8_t*)0x0F81))
#define PORTC               (*((volatile uint8_t*)0x0F82))
#define PORTD               (*((volatile uint8_t*)0x0F83))
#define PORTE               (*((volatile uint8_t*)0x0F84))
#define MAP_PORT_REG(x)     (*((volatile uint8_t*)(0x0F80+(x))))

#define LATA                (*((volatile uint8_t*)0x0F89))
#define LATB                (*((volatile uint8_t*)0x0F8A))
#define LATC                (*((volatile uint8_t*)0x0F8B))
#define LATD                (*((volatile uint8_t*)0x0F8C))
#define LATE                (*((volatile uint8_t*)0x0F8D))
#define MAP_LAT_REG(x)      (*((volatile uint8_t*)(0x0F89+(x))))

#define TRISA               (*((volatile uint8_t*)0x0F92))
#define TRISB               (*((volatile uint8_t*)0x0F93))
#define TRISC               (*((volatile uint8_t*)0x0F94))
#define TRISD               (*((volatile uint8_t*)0x0F95))
#define TRISE               (*((volatile uint8_t*)0x0F96))
#define MAP_TRIS_REG(x)     (*((volatile uint8_t*)(0x0F92+(x))))

#define ADCON1              (*((volatile uint8_t*)0x0FC1))

#endif	/* GPIO_PRIVATE_H */

