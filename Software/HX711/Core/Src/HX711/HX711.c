/*
 * HX711.c
 *
 *  Created on: Oct 15, 2020
 *      Author: marcel
 */

#include "HX711.h"
#include "main.h"
#include "stm32f303x8.h"
#include "stdbool.h"
extern UART_HandleTypeDef huart2;

uint8_t init = 0;

void readData(){

	if(!init){
		DWT_Init();
		init = 1;
	}


	uint32_t data = 0;
	HAL_GPIO_WritePin(CKL_GPIO_Port, CKL_Pin, GPIO_PIN_RESET);
	if(HAL_GPIO_ReadPin(DATA_GPIO_Port, DATA_Pin) == GPIO_PIN_RESET){
		for(int i = 0; i<25; i++){
			HAL_GPIO_WritePin(CKL_GPIO_Port, CKL_Pin, GPIO_PIN_SET);
			DWT_Delay_us(10);
			HAL_GPIO_WritePin(CKL_GPIO_Port, CKL_Pin, GPIO_PIN_RESET);
			data = data + HAL_GPIO_ReadPin(DATA_GPIO_Port, DATA_Pin);
			data = data << 1;
			DWT_Delay_us(10);
		}
		uint8_t txData[4];
		txData[0] = (uint8_t)data;
		txData[1] = (uint8_t)(data>>8);
		txData[2] = (uint8_t)(data>>16);
		txData[3] = (uint8_t)(data>>24);
		txData[4] = '\n';

		HAL_UART_Transmit(&huart2,txData, 4, 100);
	}

}


/*
 * Mikrosenkunden delay Initialisieren
 */
void DWT_Init(void) {
	CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
	DWT->CYCCNT = 0;
	DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
}

/*
 * Mikrosenkunden delay für Push-Pull ansteuerung
 */
void DWT_Delay_us(volatile uint32_t microseconds) {
	uint32_t clk_cycle_start = DWT->CYCCNT;
	/* Go to number of cycles for system */
	microseconds *= (HAL_RCC_GetHCLKFreq() / 1000000);
	/* Delay till end */
	while ((DWT->CYCCNT - clk_cycle_start) < microseconds)
		;
}
