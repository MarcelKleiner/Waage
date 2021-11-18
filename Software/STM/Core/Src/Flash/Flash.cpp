/*
 * Flash.cpp
 *
<<<<<<< HEAD
 *  Created on: 10.11.2020
 *      Author: marce
=======
 *  Created on: Nov 17, 2021
 *      Author: marcel
>>>>>>> 348a3f77483c3755c12efedca17e651192db11cb
 */

#include "Flash.h"

<<<<<<< HEAD
Flash::Flash(Model *model) {
=======
Flash::Flash(Model *model){
>>>>>>> 348a3f77483c3755c12efedca17e651192db11cb
	this->model = model;
}


<<<<<<< HEAD
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
=======

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
>>>>>>> 348a3f77483c3755c12efedca17e651192db11cb
		HAL_FLASH_Lock();
		return HAL_ERROR;
	}

<<<<<<< HEAD
	for (uint8_t i = 0; i < FLASHSIZE; i++) {
		HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, FLASH_ADDR+i*64,tmpFlashArray[i]);
	}

	//Lock flash
	if (HAL_FLASH_Lock() != HAL_OK) {
		return HAL_ERROR;
	}
	return HAL_OK;
}

=======
	HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, FLASH_STAR_PAGE_ADDR, tmpFlash);

	/*Flash Sperren*/
	if (HAL_FLASH_Lock() != HAL_OK) {
		HAL_FLASH_Lock();
		return HAL_ERROR;
	}

	return HAL_OK;

}
>>>>>>> 348a3f77483c3755c12efedca17e651192db11cb
