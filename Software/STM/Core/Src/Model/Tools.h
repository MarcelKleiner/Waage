/*
 * Tools.h
 *
 *  Created on: Oct 17, 2020
 *      Author: marcel
 */

#ifndef SRC_MODEL_TOOLS_H_
#define SRC_MODEL_TOOLS_H_

#include "stm32l412xx.h"

class Tools {

public:

	static char* intToAsciiChar(int32_t data,uint8_t nachkommastellen);
	static int32_t Round5Rp(int32_t prize);


};

#endif /* SRC_MODEL_TOOLS_H_ */
