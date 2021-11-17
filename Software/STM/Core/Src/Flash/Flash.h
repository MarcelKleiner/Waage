/*
 * Flash.h
 *
 *  Created on: Nov 17, 2021
 *      Author: marcel
 */

#ifndef SRC_FLASH_FLASH_H_
#define SRC_FLASH_FLASH_H_



//#include "stm32l4xx_hal_flash.h"

#include <stm32l4xx_hal.h>
#include <stm32l4xx_hal_flash.h>
#include "../Model/Model.h"


#define FLASH_STAR_PAGE_ADDR	0x800F800

class Flash {


public:

	Flash(Model *model);
	Model *model;

void flashLesen(void);
HAL_StatusTypeDef WriteFlash();

private:

};

#endif /* SRC_FLASH_FLASH_H_ */
