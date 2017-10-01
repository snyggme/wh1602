#include "stm32f30x_gpio.h"
#include "stm32f30x_rcc.h"
#include "stm32f30x.h"
#include "stm32f30x_tim.h"
#include "stm32f30x_adc.h"
#include "stm32f30x_misc.h"
#include <stdio.h>

#include "lcd.h"

uint16_t delay_count = 0;
char str[] = {0};

uint16_t ADCConvertedValue, ADCConvertedVoltage;
volatile int i;
uint16_t CalibrationValue; 

TIM_TimeBaseInitTypeDef TIM_InitStructure;

void ADC_Configuration(void)
{
  ADC_InitTypeDef        ADC_InitStructure;
  ADC_CommonInitTypeDef  ADC_CommonInitStructure;
	GPIO_InitTypeDef gpio_ant;

	
	 RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);
   gpio_ant.GPIO_Pin = GPIO_Pin_1;
   gpio_ant.GPIO_Mode = GPIO_Mode_AN;
	 gpio_ant.GPIO_PuPd = GPIO_PuPd_NOPULL;
   GPIO_Init(GPIOC, &gpio_ant);
	
  /* Enable ADC1/2 clocks */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_ADC12, ENABLE);
	
	  /* ADC configuration */
  ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
  ADC_CommonInitStructure.ADC_Clock = ADC_Clock_SynClkModeDiv4;
  ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled; 
  ADC_CommonInitStructure.ADC_DMAMode = ADC_DMAMode_OneShot;
  ADC_CommonInitStructure.ADC_TwoSamplingDelay = 0;
 
  ADC_CommonInit(ADC1, &ADC_CommonInitStructure);
  
  /* ADC Calibration procedure */
  ADC_VoltageRegulatorCmd(ADC1, ENABLE);
 
  /* Insert delay equal to 10 us */
  for(i=0; i<10000; i++);
 
  ADC_SelectCalibrationMode(ADC1, ADC_CalibrationMode_Single);
  ADC_StartCalibration(ADC1);
 
  while(ADC_GetCalibrationStatus(ADC1) != RESET);
 
  CalibrationValue = ADC_GetCalibrationValue(ADC1);
 
  ADC_InitStructure.ADC_ContinuousConvMode = ADC_ContinuousConvMode_Disable; 
  ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
  ADC_InitStructure.ADC_ExternalTrigEventEdge = ADC_ExternalTrigEventEdge_None;
  ADC_InitStructure.ADC_ExternalTrigConvEvent = ADC_ExternalTrigConvEvent_0; 
  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
  ADC_InitStructure.ADC_OverrunMode = ADC_OverrunMode_Disable;
  ADC_InitStructure.ADC_AutoInjMode = ADC_AutoInjec_Disable;
  ADC_InitStructure.ADC_NbrOfRegChannel = 1;
 
  ADC_Init(ADC1, &ADC_InitStructure);
 
  ADC_RegularChannelConfig(ADC1, ADC_Channel_7, 1, ADC_SampleTime_601Cycles5);
 
  //ADC_TempSensorCmd(ADC1, ENABLE);
 
  ADC_Cmd(ADC1, ENABLE);
	
	//NVIC_EnableIRQ(ADC1_2_IRQn);
 
	//ADC_ITConfig(ADC1, ADC_IT_EOC, ENABLE);
 
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_RDY));
}

//void ADC1_2_IRQHandler(void)
//{
	
//}



void SysTick_Handler(void) {
	
	if (delay_count > 0) delay_count--;
	
}

void delay_ms(uint32_t ms) {
	
	delay_count = ms;
	while(delay_count){}	
	
}

void LCD_GPIO_ini(void) 
{
	GPIO_InitTypeDef GPIO_Init_LCD;
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOD, ENABLE);
	
	GPIO_Init_LCD.GPIO_Pin = RS_PIN;
	GPIO_Init_LCD.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_LCD.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_LCD.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_LCD.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(RS_PORT, &GPIO_Init_LCD);

	
	
	GPIO_Init_LCD.GPIO_Pin = RW_PIN;
	GPIO_Init_LCD.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_LCD.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_LCD.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_LCD.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(RW_PORT, &GPIO_Init_LCD);
	
	
	
	GPIO_Init_LCD.GPIO_Pin = EN_PIN;
	GPIO_Init_LCD.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_LCD.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_LCD.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_LCD.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(EN_PORT, &GPIO_Init_LCD);
	
	
	
	GPIO_Init_LCD.GPIO_Pin = DB0_PIN;
	GPIO_Init_LCD.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_LCD.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_LCD.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_LCD.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(DB0_PORT, &GPIO_Init_LCD);
	
	
	
	GPIO_Init_LCD.GPIO_Pin = DB1_PIN;
	GPIO_Init_LCD.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_LCD.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_LCD.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_LCD.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(DB1_PORT, &GPIO_Init_LCD);

  
	
	GPIO_Init_LCD.GPIO_Pin = DB2_PIN;
	GPIO_Init_LCD.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_LCD.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_LCD.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_LCD.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(DB2_PORT, &GPIO_Init_LCD);
	
	
	
	GPIO_Init_LCD.GPIO_Pin = DB3_PIN;
	GPIO_Init_LCD.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_LCD.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_LCD.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_LCD.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(DB3_PORT, &GPIO_Init_LCD);
	
	
	
	GPIO_Init_LCD.GPIO_Pin = DB4_PIN;
	GPIO_Init_LCD.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_LCD.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_LCD.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_LCD.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(DB4_PORT, &GPIO_Init_LCD);
	
	
	
	GPIO_Init_LCD.GPIO_Pin = DB5_PIN;
	GPIO_Init_LCD.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_LCD.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_LCD.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_LCD.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(DB5_PORT, &GPIO_Init_LCD);
	
	
	
	GPIO_Init_LCD.GPIO_Pin = DB6_PIN;
	GPIO_Init_LCD.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_LCD.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_LCD.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_LCD.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(DB6_PORT, &GPIO_Init_LCD);
	
	
	
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
	delay_ms(5);		
	LCD_SendCommand(0x38);
	delay_ms(2);
	LCD_SendCommand(0x0C);
	delay_ms(1);	
	LCD_SendCommand(0x01);
	delay_ms(1);	
	LCD_SendCommand(0x06);
	delay_ms(1);	
	
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

int main(void)
{
	uint16_t adc_val_cel, adc_val_des, adc_val_sot, adc_val_tis;
	
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6,ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	
  TIM_TimeBaseStructInit(&TIM_InitStructure);
  TIM_InitStructure.TIM_Prescaler = 8000;  
  TIM_InitStructure.TIM_Period = 1000; 
  TIM_TimeBaseInit(TIM6, &TIM_InitStructure);
	TIM_Cmd(TIM6, ENABLE);
		  	
	SysTick_Config(SystemCoreClock/1000);
	delay_ms(50);
	LCD_ini();
	ADC_Configuration();

  while (1)
  {
		
		ADC_StartConversion(ADC1);
		while (!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC)) {}
			
		ADCConvertedValue = ADC_GetConversionValue(ADC1);
		
		ADCConvertedVoltage = (ADCConvertedValue *3000)/0xFFF;
			
		TIM_SetCounter(TIM6, 0);
		while(TIM_GetCounter(TIM6) < 500){}
		ADC_StopConversion(ADC1);
			
		adc_val_cel = ADCConvertedVoltage/1000;
		adc_val_des = (ADCConvertedVoltage/100)%10;	
		adc_val_sot = (ADCConvertedVoltage/10)%10;
		adc_val_tis = ADCConvertedVoltage%10;
			
		LCD_SendCommand(0x01);
		delay_ms(1);	
		sprintf(str, "U = %d.%d%d%dV", adc_val_cel, adc_val_des, adc_val_sot, adc_val_tis);	
		LCD_SendString(0, str);	
			
  }
}


