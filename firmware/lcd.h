#ifndef LCD_H
#define LCD_H

#include "stm32f30x.h"
#include "stm32f30x_gpio.h"
#include "stm32f30x_rcc.h"

#define RS_RCC_FUNC 		RCC_AHBPeriphClockCmd  
#define RS_RCC 					RCC_AHBPeriph_GPIOD
#define RS_PIN 					GPIO_Pin_10
#define RS_PORT 				GPIOD

#define RW_RCC_FUNC 		RCC_AHBPeriphClockCmd
#define RW_RCC 					RCC_AHBPeriph_GPIOD
#define RW_PIN 					GPIO_Pin_9
#define RW_PORT 				GPIOD

#define EN_RCC_FUNC 		RCC_AHBPeriphClockCmd
#define EN_RCC 					RCC_AHBPeriph_GPIOD
#define EN_PIN 					GPIO_Pin_8
#define EN_PORT 				GPIOD

#define DB0_RCC_FUNC 		RCC_AHBPeriphClockCmd
#define DB0_RCC 				RCC_AHBPeriph_GPIOD
#define DB0_PIN 				GPIO_Pin_1
#define DB0_PORT 				GPIOD

#define DB1_RCC_FUNC 		RCC_AHBPeriphClockCmd
#define DB1_RCC 				RCC_AHBPeriph_GPIOD
#define DB1_PIN 				GPIO_Pin_3
#define DB1_PORT 				GPIOD

#define DB2_RCC_FUNC 		RCC_AHBPeriphClockCmd
#define DB2_RCC 				RCC_AHBPeriph_GPIOD
#define DB2_PIN 				GPIO_Pin_0
#define DB2_PORT 				GPIOD

#define DB3_RCC_FUNC	 	RCC_AHBPeriphClockCmd
#define DB3_RCC 				RCC_AHBPeriph_GPIOD
#define DB3_PIN 				GPIO_Pin_2
#define DB3_PORT 				GPIOD

#define DB4_RCC_FUNC 		RCC_AHBPeriphClockCmd
#define DB4_RCC 				RCC_AHBPeriph_GPIOD
#define DB4_PIN 				GPIO_Pin_4
#define DB4_PORT 				GPIOD

#define DB5_RCC_FUNC	 	RCC_AHBPeriphClockCmd
#define DB5_RCC 				RCC_AHBPeriph_GPIOD
#define DB5_PIN 				GPIO_Pin_6
#define DB5_PORT 				GPIOD

#define DB6_RCC_FUNC	 	RCC_AHBPeriphClockCmd
#define DB6_RCC 				RCC_AHBPeriph_GPIOD
#define DB6_PIN 				GPIO_Pin_5
#define DB6_PORT 				GPIOD

#define DB7_RCC_FUNC 		RCC_AHBPeriphClockCmd
#define DB7_RCC 				RCC_AHBPeriph_GPIOD
#define DB7_PIN 				GPIO_Pin_7
#define DB7_PORT 				GPIOD


#define RS(a)						GPIO_WriteBit(RS_PORT, RS_PIN, (BitAction)a)
#define RW(a)						GPIO_WriteBit(RW_PORT, RW_PIN, (BitAction)a)
#define EN(a)						GPIO_WriteBit(EN_PORT, EN_PIN, (BitAction)a)

#define DB0(a)					GPIO_WriteBit(DB0_PORT, DB0_PIN, (BitAction)a)
#define DB1(a)					GPIO_WriteBit(DB1_PORT, DB1_PIN, (BitAction)a)
#define DB2(a)					GPIO_WriteBit(DB2_PORT, DB2_PIN, (BitAction)a)
#define DB3(a)					GPIO_WriteBit(DB3_PORT, DB3_PIN, (BitAction)a)
#define DB4(a)					GPIO_WriteBit(DB4_PORT, DB4_PIN, (BitAction)a)
#define DB5(a)					GPIO_WriteBit(DB5_PORT, DB5_PIN, (BitAction)a)
#define DB6(a)					GPIO_WriteBit(DB6_PORT, DB6_PIN, (BitAction)a)
#define DB7(a)					GPIO_WriteBit(DB7_PORT, DB7_PIN, (BitAction)a)

void LCD_ini(void);
void LCD_SendString(uint8_t StringNum, char* str);

#endif
