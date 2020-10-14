/*
 * LCD.h
 *
 *  Created on: Oct 10, 2020
 *      Author: marcel
 */

#ifndef SRC_LCD_LCD_H_
#define SRC_LCD_LCD_H_

#include "stm32l412xx.h"



class LCD {

public:
	LCD();


public:
	void Write(char lin1[], char line2[]);
	void InitLCD(void);

private:
	void WriteCommand(uint8_t command);
	void WriteData(uint8_t data);
	void WriteCommaandWwakeUp(uint8_t data);
};


#endif /* SRC_LCD_LCD_H_ */
