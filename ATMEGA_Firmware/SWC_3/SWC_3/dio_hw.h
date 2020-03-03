/*
 * dio_hw.h
 *
 * Created: 2/1/2020 12:01:11 PM
 *  Author: User
 */ 


#ifndef DIO_HW_H_
#define DIO_HW_H_

#include "STD_Types.h"

#define PINCOUNT 32

#define PORTA		*((volatile uint8*)0x3B)
#define PORTB		*((volatile uint8*)0x38)
#define PORTC		*((volatile uint8*)0x35)
#define PORTD		*((volatile uint8*)0x32)

#define PINA		*((const volatile uint8*)0x39 )
#define PINB		*((const volatile uint8*)0x36 )
#define PINC		*((const volatile uint8*)0x33 )
#define PIND		*((const volatile uint8*)0x30 )


#define DDRA		*((volatile uint8*)0x3A)
#define DDRB		*((volatile uint8*)0x37)
#define DDRC		*((volatile uint8*)0x34)
#define DDRD		*((volatile uint8*)0x31)



#endif /* DIO_HW_H_ */