/*
 * Flash.h
 *
<<<<<<< HEAD
 *  Created on: 10.11.2020
 *      Author: marce
=======
 *  Created on: Nov 17, 2021
 *      Author: marcel
>>>>>>> 348a3f77483c3755c12efedca17e651192db11cb
 */

#ifndef SRC_FLASH_FLASH_H_
#define SRC_FLASH_FLASH_H_

<<<<<<< HEAD
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

=======


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

>>>>>>> 348a3f77483c3755c12efedca17e651192db11cb
};

#endif /* SRC_FLASH_FLASH_H_ */
