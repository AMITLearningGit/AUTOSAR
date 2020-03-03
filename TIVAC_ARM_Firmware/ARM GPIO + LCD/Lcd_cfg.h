#ifndef LCD_CFG_H
#define LCD_CFG_H

#include "TM4C123GH6PM.h"
#include "Gpio_Types.h"

#define LCD_PORT					GPIOB->DATA	
#define LCD_CONTROL_PORT	GPIOB->DATA  

#define LCD_RS						GPIO_Channel_B0 
#define LCD_RW						GPIO_Channel_B1 
#define LCD_E							GPIO_Channel_B2  



#endif /* LCD_CFG_H_ */
