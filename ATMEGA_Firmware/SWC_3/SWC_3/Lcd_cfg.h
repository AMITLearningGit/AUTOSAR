/*
 * Lcd_cfg.h
 *
 * Created: 2/3/2020 03:28:12 PM
 *  Author: User
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_
#include "dio_hw.h"
#include "dio_types.h"

#define LCD_PORT			PORTA //GPIOB->DATA
#define LCD_CONTROL_PORT	PORTB  //GPIOB->DATA

#define LCD_RS		Dio_Channel_B1 
#define LCD_RW		Dio_Channel_B2 
#define LCD_E		Dio_Channel_B3  



#endif /* LCD_CFG_H_ */