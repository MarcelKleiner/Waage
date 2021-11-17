/*
 * Flash.cpp
 *
 *  Created on: Nov 17, 2021
 *      Author: marcel
 */

#include "Flash.h"

Flash::Flash(Model *model){
	this->model = model;
}



/*
 * Auslesen vom Flash und speichern in tmpFlashArray
 *
 * @param None
 * @return None
 */
void Flash::flashLesen() {
	uint32_t tmpFlash = 0;
	tmpFlash = *(uint32_t*) (FLASH_STAR_PAGE_ADDR);

	if(tmpFlash / 100000000 != 1){
		//load default values
	}else{
		//read flash
		uint16_t priceBW = (tmpFlash%10000);
		uint16_t pricePW = ((tmpFlash/10000)%10000);

		model->setParafinwachsPreis(pricePW);
		model->setBienenwachsPreis(priceBW);
	}
}



HAL_StatusTypeDef Flash::WriteFlash(){
	uint16_t pricePW = model->getParafinwachsPreis();
	uint16_t priceBW = model->getBienenwachsPreis();

	uint32_t tmpFlash = 100000000 + pricePW*10000 + priceBW;

	FLASH_EraseInitTypeDef EraseInitStruct;
	uint32_t sectorError = 0;

	if (HAL_FLASH_Unlock() != HAL_OK) {
			HAL_FLASH_Lock();
			return HAL_ERROR;
	}

	EraseInitStruct.TypeErase = FLASH_TYPEERASE_PAGES;
	EraseInitStruct.Page = 31;
	EraseInitStruct.NbPages = 1;
	EraseInitStruct.Banks = 1;



	if (HAL_FLASHEx_Erase(&EraseInitStruct, &sectorError) != HAL_OK) {
		HAL_FLASH_Lock();
		return HAL_ERROR;
	}

	HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, FLASH_STAR_PAGE_ADDR, tmpFlash);

	/*Flash Sperren*/
	if (HAL_FLASH_Lock() != HAL_OK) {
		HAL_FLASH_Lock();
		return HAL_ERROR;
	}

	return HAL_OK;

}
