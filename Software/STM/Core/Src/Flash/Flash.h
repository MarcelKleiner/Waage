/*
 * Flash.h
 *
 *  Created on: 10.11.2020
 *      Author: marce
 */

#ifndef SRC_FLASH_FLASH_H_
#define SRC_FLASH_FLASH_H_

#include "../Model/Model.h"
#include "../Model/Tools.h"

#define FLASH_ADDR	0x0800FC00
#define FLASHSIZE  5

class Flash {
public:
	Flash(Model *model);
	void readFlash();
	HAL_StatusTypeDef writeFlash();

private:


	uint64_t tmpFlashArray[FLASHSIZE];
	Model *model;

};

#endif /* SRC_FLASH_FLASH_H_ */
