/*
 * Flash.cpp
 *
 *  Created on: 10.11.2020
 *      Author: marce
 */

#include "Flash.h"

Flash::Flash(Model *model) {
	this->model = model;
}


void Flash::readFlash(){
	for (int i = 0; i < FLASHSIZE; i++) {
		tmpFlashArray[i] = *(uint64_t*) (FLASH_ADDR + 64 * i);
	}

	model->setParafinwachsPreis(Tools::UintToFloat(tmpFlashArray[2]));
	model->setBienenwachsPreis(Tools::UintToFloat(tmpFlashArray[1]));
	//model->setKontrast(tmpFlashArray[2]);
}

HAL_StatusTypeDef Flash::writeFlash() {

	tmpFlashArray[2] = Tools::floatToUint(model->getParafinwachsPreis());
	tmpFlashArray[1] = Tools::floatToUint(model->getBienenwachsPreis());
	//tmpFlashArray[2] = model->getKontrast();


	FLASH_EraseInitTypeDef EraseinitStruct;
	uint32_t sectorError = 0;


	//unlock flash
	if (HAL_FLASH_Unlock() != HAL_OK) {
		HAL_FLASH_Lock();
		return HAL_ERROR;
	}


	EraseinitStruct.TypeErase = FLASH_TYPEERASE_PAGES;
	EraseinitStruct.Page = 63;
	EraseinitStruct.NbPages = 1;
	EraseinitStruct.Banks = FLASH_BANK_1;

	/*Flash erase*/
	if (HAL_FLASHEx_Erase(&EraseinitStruct, &sectorError) != HAL_OK) {
		HAL_FLASH_Lock();
		return HAL_ERROR;
	}

	for (uint8_t i = 0; i < FLASHSIZE; i++) {
		HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, FLASH_ADDR+i*64,tmpFlashArray[i]);
	}

	//Lock flash
	if (HAL_FLASH_Lock() != HAL_OK) {
		return HAL_ERROR;
	}
	return HAL_OK;
}

