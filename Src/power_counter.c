/*
 * power_counter.c
 *
 *  Created on: Jul 31, 2018
 *      Author: z1rex
 */
#include "power_counter.h"
#include "adc.h"
power_counter_flags_t pcf;

void restoreState(void)
{
	EE_ReadVariable32bits(0x0000, (uint32_t)(&pcf));
}

uint32_t getHallMesure(void)
{
	uint32_t ADCValue = 0;
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 100);
	ADCValue = HAL_ADC_GetValue(&hadc1);
	HAL_ADC_Stop(&hadc1);
	return ADCValue;
}

void toggelReley(loadState_t state, relay_t *relay)
{
	switch(state)
	{
		case off:
			  HAL_GPIO_WritePin(RELAY_DIR_GPIO_Port, RELAY_DIR_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(relay->port, relay->pinmask, GPIO_PIN_SET);
			  HAL_Delay(100);
			  HAL_GPIO_WritePin(relay->port, relay->pinmask, GPIO_PIN_RESET);
			break;
		case on:
			  HAL_GPIO_WritePin(RELAY_DIR_GPIO_Port, RELAY_DIR_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(relay->port, relay->pinmask, GPIO_PIN_SET);
			  HAL_Delay(100);
			  HAL_GPIO_WritePin(relay->port, relay->pinmask, GPIO_PIN_RESET);
			break;
	}
}
