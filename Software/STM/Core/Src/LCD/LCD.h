/*
 * LCD.h
 *
 *  Created on: Oct 10, 2020
 *      Author: marcel
 */

#ifndef SRC_LCD_LCD_H_
#define SRC_LCD_LCD_H_

#include "stm32l412xx.h"
using namespace std;



class LCD {

public:
	LCD();


public:

	void Write(char* line1, uint8_t lengthL1,uint8_t startl1, char* line2, uint8_t lengthL2, uint8_t startl2);
	void Write(const char* line1, uint8_t length1, uint8_t startl1, char* line2, uint8_t lengthL2, uint8_t startl2);
	void Write(void);
	void InitLCD(void);

	void SetCursorPosition(uint8_t position, uint8_t line, bool cursorBlink);
private:
	void WriteCommand(uint8_t command);
	void WriteData(uint8_t data);
	void WriteCommaandWwakeUp(uint8_t data);
};


#endif /* SRC_LCD_LCD_H_ */
