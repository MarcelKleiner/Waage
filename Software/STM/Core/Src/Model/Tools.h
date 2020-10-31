/*
 * Tools.h
 *
 *  Created on: Oct 17, 2020
 *      Author: marcel
 */

#ifndef SRC_MODEL_TOOLS_H_
#define SRC_MODEL_TOOLS_H_

#include "stm32l412xx.h"
#include "main.h"

class Tools {

public:

	static char* intToAsciiChar(int32_t data,uint8_t nachkommastellen);
	static char* byteToAscii(uint8_t data);
	static int32_t Round5Rp(int32_t prize);

	static uint8_t BCDDecoder(uint8_t data);
	static uint8_t BCDEncoder(uint8_t data);

	static void DWT_Init(void);
	static void DWT_Delay_us(volatile uint32_t microseconds);

};

#endif /* SRC_MODEL_TOOLS_H_ */
