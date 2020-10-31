/*
 * LCD.cpp
 *
 *  Created on: Oct 10, 2020
 *      Author: marcel
 */

#include "LCD.h"
#include "main.h"




LCD::LCD() {

}


void LCD::InitLCD(){


	HAL_GPIO_WritePin(DB0_GPIO_Port, DB0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(DB1_GPIO_Port, DB1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(DB2_GPIO_Port, DB2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(DB3_GPIO_Port, DB3_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_RW_GPIO_Port, LCD_RW_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_RESET);

	WriteCommaandWwakeUp(0x30);
	WriteCommaandWwakeUp(0x30);
	WriteCommaandWwakeUp(0x30);
	WriteCommaandWwakeUp(0x20);
	WriteCommand(0x28);
	WriteCommand(0x10); //Set cursor
	WriteCommand(0x0F); //Display ON; Blinking cursor
	WriteCommand(0x06);
	WriteCommand(0x01);

}


void LCD::Write(char* line1, uint8_t lengthL1,uint8_t startl1, char* line2, uint8_t lengthL2, uint8_t startl2){

	WriteCommand(0x80);
	for(uint8_t a = 0; a<startl1; a++){
		WriteData(0x10);
	}
	for(uint8_t i = 0; i<12; i++){
		if(lengthL1 > i){
			WriteData(line1[i]);
		}else{
			WriteData(0x10);
		}
	}
	WriteCommand(0x80+0x40);
	for(uint8_t a = 0; a<startl2; a++){
		WriteData(0x10);
	}

	for(uint8_t i = 0; i<12-startl2; i++){
		if(lengthL2 > i){
			WriteData(line2[i]);
		}else{
			WriteData(0x10);
		}
	}
}


void LCD::Write(const char* line1, uint8_t lenght1,uint8_t startl1, char* line2, uint8_t lengthL2, uint8_t startl2){
	WriteCommand(0x80+startl1);
	for(uint8_t i = 0; i<12-startl1; i++){
		if(lenght1 > i){
			WriteData(line1[i]);
		}else{
			WriteData(0x10);
		}
	}


	WriteCommand(0x80+0x40);
	for(uint8_t a = 0; a<startl2; a++){
		WriteData(0x10);
	}

	for(uint8_t i = 0; i<12-startl2; i++){
		if(lengthL2 > i){
			WriteData(line2[i]);
		}else{
			WriteData(0x10);
		}
	}


}


void LCD::Write(){
	for(int i = 0; i<12; i++){
		WriteData(0x30 + i);
	}

	for(int i = 0; i<12; i++){
		WriteData(0x30 + i);
	}

}


void LCD::SetCursorPosition(uint8_t position, uint8_t line, bool cursorBlink){

	if(line == 1){
		WriteCommand(0x80 + position);
	}else if(line == 2){
		WriteCommand(0x80+0x40+position);
	}

	if(cursorBlink){
		WriteCommand(0x0F);
	}else{
		WriteCommand(0x0F);
	}




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
	HAL_Delay(1);
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
	HAL_Delay(1);
}




