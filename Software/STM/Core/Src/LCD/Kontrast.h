/*
 * Kontrast.h
 *
 *  Created on: Oct 20, 2020
 *      Author: marcel
 */

#ifndef SRC_LCD_KONTRAST_H_
#define SRC_LCD_KONTRAST_H_

#include "main.h"
#include "stm32l412xx.h"

#define POTI_ADDR	0b00101110

class Kontrast {
public:
	Kontrast();

	void setContrast(uint8_t data);

};

#endif /* SRC_LCD_KONTRAST_H_ */
