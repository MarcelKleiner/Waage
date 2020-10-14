/*
 * LCD.cpp
 *
 *  Created on: Oct 10, 2020
 *      Author: marcel
 */

#include "LCD.h"
#include "main.h"



LCD::LCD() {
	// TODO Auto-generated constructor stub

}


void LCD::InitLCD(){

	HAL_Delay(100);
	HAL_GPIO_WritePin(DB0_GPIO_Port, DB0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(DB1_GPIO_Port, DB1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(DB2_GPIO_Port, DB2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(DB3_GPIO_Port, DB3_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_RW_GPIO_Port, LCD_RW_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_RESET);


	HAL_Delay(100);
	WriteCommaandWwakeUp(0x30);
	HAL_Delay(30);

	WriteCommaandWwakeUp(0x30);

	HAL_Delay(10);

	WriteCommaandWwakeUp(0x30);

	HAL_Delay(10);

	WriteCommaandWwakeUp(0x20);
	HAL_Delay(10);
	WriteCommand(0x28);
	HAL_Delay(10);
	WriteCommand(0x10); //Set cursor
	HAL_Delay(10);
	WriteCommand(0x0F); //Display ON; Blinking cursor
	HAL_Delay(10);
	WriteCommand(0x06);


	HAL_Delay(50);
	WriteData(0x31);
	HAL_Delay(10);
	WriteData(0x32);
	HAL_Delay(10);
	WriteData(0x33);
	HAL_Delay(10);
	WriteData(0x34);
	HAL_GPIO_WritePin(LED_PW_GPIO_Port, LED_PW_Pin, GPIO_PIN_RESET);
}

void LCD::Write(char* lin1, char* line2){

}

void LCD::WriteCommaandWwakeUp(uint8_t data){

	uint8_t data1 = data>>4;
	HAL_GPIO_WritePin(DB0_GPIO_Port, DB0_Pin, (GPIO_PinState)(data1 & 0x01));
	HAL_GPIO_WritePin(DB1_GPIO_Port, DB1_Pin, (GPIO_PinState)(data1 & 0x02));
	HAL_GPIO_WritePin(DB2_GPIO_Port, DB2_Pin, (GPIO_PinState)(data1 & 0x04));
	HAL_GPIO_WritePin(DB3_GPIO_Port, DB3_Pin, (GPIO_PinState)(data1 & 0x08));
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_RESET);
}

void LCD::WriteCommand(uint8_t data){

	HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_RW_GPIO_Port, LCD_RW_Pin, GPIO_PIN_RESET);

	uint8_t data1 = data>>4;
	HAL_GPIO_WritePin(DB0_GPIO_Port, DB0_Pin, (GPIO_PinState)(data1 & 0x01));
	HAL_GPIO_WritePin(DB1_GPIO_Port, DB1_Pin, (GPIO_PinState)(data1 & 0x02));
	HAL_GPIO_WritePin(DB2_GPIO_Port, DB2_Pin, (GPIO_PinState)(data1 & 0x04));
	HAL_GPIO_WritePin(DB3_GPIO_Port, DB3_Pin, (GPIO_PinState)(data1 & 0x08));

	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_RESET);



	HAL_GPIO_WritePin(DB0_GPIO_Port, DB0_Pin, (GPIO_PinState)(data & 0x01));
	HAL_GPIO_WritePin(DB1_GPIO_Port, DB1_Pin, (GPIO_PinState)(data & 0x02));
	HAL_GPIO_WritePin(DB2_GPIO_Port, DB2_Pin, (GPIO_PinState)(data & 0x04));
	HAL_GPIO_WritePin(DB3_GPIO_Port, DB3_Pin, (GPIO_PinState)(data & 0x08));

	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_RESET);
}

void LCD::WriteData(uint8_t data){
	HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCD_RW_GPIO_Port, LCD_RW_Pin, GPIO_PIN_RESET);


	uint8_t data1 = data>>4;
	HAL_GPIO_WritePin(DB0_GPIO_Port, DB0_Pin, (GPIO_PinState)(data1 & 0x01));
	HAL_GPIO_WritePin(DB1_GPIO_Port, DB1_Pin, (GPIO_PinState)(data1 & 0x02));
	HAL_GPIO_WritePin(DB2_GPIO_Port, DB2_Pin, (GPIO_PinState)(data1 & 0x04));
	HAL_GPIO_WritePin(DB3_GPIO_Port, DB3_Pin, (GPIO_PinState)(data1 & 0x08));

	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_RESET);


	HAL_GPIO_WritePin(DB0_GPIO_Port, DB0_Pin, (GPIO_PinState)(data & 0x01));
	HAL_GPIO_WritePin(DB1_GPIO_Port, DB1_Pin, (GPIO_PinState)(data & 0x02));
	HAL_GPIO_WritePin(DB2_GPIO_Port, DB2_Pin, (GPIO_PinState)(data & 0x04));
	HAL_GPIO_WritePin(DB3_GPIO_Port, DB3_Pin, (GPIO_PinState)(data & 0x08));

	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_RESET);
}




