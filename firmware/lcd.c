#include "lcd.h"

void LCD_GPIO_ini(void) 
{
	GPIO_InitTypeDef GPIO_Init_LCD;
	
	RS_RCC_FUNC(RS_RCC, ENABLE);
	
	GPIO_Init_LCD.GPIO_Pin = RS_PIN;
	GPIO_Init_LCD.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_LCD.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_LCD.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_LCD.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(RS_PORT, &GPIO_Init_LCD);

	RW_RCC_FUNC(RS_RCC, ENABLE);
	
	GPIO_Init_LCD.GPIO_Pin = RW_PIN;
	GPIO_Init_LCD.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_LCD.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_LCD.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_LCD.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(RW_PORT, &GPIO_Init_LCD);
	
	EN_RCC_FUNC(EN_RCC, ENABLE);
	
	GPIO_Init_LCD.GPIO_Pin = EN_PIN;
	GPIO_Init_LCD.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_LCD.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_LCD.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_LCD.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(EN_PORT, &GPIO_Init_LCD);
	
	DB0_RCC_FUNC(DB0_RCC, ENABLE);
	
	GPIO_Init_LCD.GPIO_Pin = DB0_PIN;
	GPIO_Init_LCD.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_LCD.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_LCD.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_LCD.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(DB0_PORT, &GPIO_Init_LCD);
	
	DB1_RCC_FUNC(DB1_RCC, ENABLE);
	
	GPIO_Init_LCD.GPIO_Pin = DB1_PIN;
	GPIO_Init_LCD.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_LCD.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_LCD.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_LCD.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(DB1_PORT, &GPIO_Init_LCD);

  DB2_RCC_FUNC(DB2_RCC, ENABLE);
	
	GPIO_Init_LCD.GPIO_Pin = DB2_PIN;
	GPIO_Init_LCD.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_LCD.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_LCD.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_LCD.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(DB2_PORT, &GPIO_Init_LCD);
	
	DB3_RCC_FUNC(DB3_RCC, ENABLE);
	
	GPIO_Init_LCD.GPIO_Pin = DB3_PIN;
	GPIO_Init_LCD.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_LCD.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_LCD.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_LCD.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(DB3_PORT, &GPIO_Init_LCD);
	
	DB4_RCC_FUNC(DB4_RCC, ENABLE);
	
	GPIO_Init_LCD.GPIO_Pin = DB4_PIN;
	GPIO_Init_LCD.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_LCD.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_LCD.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_LCD.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(DB4_PORT, &GPIO_Init_LCD);
	
	DB5_RCC_FUNC(DB5_RCC, ENABLE);
	
	GPIO_Init_LCD.GPIO_Pin = DB5_PIN;
	GPIO_Init_LCD.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_LCD.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_LCD.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_LCD.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(DB5_PORT, &GPIO_Init_LCD);
	
	DB6_RCC_FUNC(DB6_RCC, ENABLE);
	
	GPIO_Init_LCD.GPIO_Pin = DB6_PIN;
	GPIO_Init_LCD.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_LCD.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_LCD.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_LCD.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(DB6_PORT, &GPIO_Init_LCD);
	
	DB7_RCC_FUNC(DB7_RCC, ENABLE);
	
	GPIO_Init_LCD.GPIO_Pin = DB7_PIN;
	GPIO_Init_LCD.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_LCD.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_LCD.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_LCD.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(DB7_PORT, &GPIO_Init_LCD);
	
	RW(0);
}

void LCD_Set_Data(uint8_t data) 
{
	if (((data >> 7) & 0x01) == 1) { DB7(1); } else { DB7(0); }
	if (((data >> 6) & 0x01) == 1) { DB6(1); } else { DB6(0); }
	if (((data >> 5) & 0x01) == 1) { DB5(1); } else { DB5(0); }
	if (((data >> 4) & 0x01) == 1) { DB4(1); } else { DB4(0); }
	if (((data >> 3) & 0x01) == 1) { DB3(1); } else { DB3(0); }
	if (((data >> 2) & 0x01) == 1) { DB2(1); } else { DB2(0); }
	if (((data >> 1) & 0x01) == 1) { DB1(1); } else { DB1(0); }
	if (((data >> 0) & 0x01) == 1) { DB0(1); } else { DB0(0); }
}

void LCD_delay (void)
{
	uint16_t i;
	
	for (i = 0; i < 1000; i++){}
}

void LCD_SendCommand (uint8_t data) 
{
	RS(0);
	
	LCD_Set_Data(data);
	
	EN(1);
	LCD_delay();
	EN(0);
}

void LCD_SendData (uint8_t data) 
{
	RS(1);
	
	LCD_Set_Data(data);
	
	EN(1);
	LCD_delay();
	EN(0);
}

void LCD_ini(void)
{
	LCD_GPIO_ini();
	
	LCD_SendCommand(0x38);
	delay_ms(1);
	LCD_SendCommand(0x38);
	delay_ms(1);	
	LCD_SendCommand(0x0F);
	delay_ms(1);
	LCD_SendCommand(0x01);
	delay_ms(2);
	LCD_SendCommand(0x06);
	delay_ms(1);
	LCD_SendCommand(0x02);
	delay_ms(2);
}

void LCD_SendString(uint8_t StringNum, char* str)
{
	uint8_t i = 0;
	
	if (StringNum == 0) 
	{
		LCD_SendCommand(0x80);
	} else
	{
		LCD_SendCommand(0xC0);
	}
	delay_ms(1);
	
	while (str[i] != 0)
	{
		LCD_SendData(str[i]);
		LCD_delay();
		i++;
	}
}