/*
 * Log.cpp
 *
 *  Created on: Oct 31, 2020
 *      Author: marcel
 */

#include "Log.h"

Log::Log(Model *model) {
	this->model = model;
	addrPointer = 1;
}

void Log::init() {

	uint8_t txBuffer[] = { 0x00, 0x00 };
	uint8_t rxBuffer[] = { 0, 0,0 };
	HAL_I2C_Master_Transmit(&hi2c1, EEPROM_ADDR << 1, txBuffer, 2, 100);
	HAL_I2C_Master_Receive(&hi2c1, EEPROM_ADDR << 1, rxBuffer, 3, 100);

	if((addrPointer = ((rxBuffer[0]<<16) + (rxBuffer[1]<<8) + (rxBuffer[2]))) == 0){
		addrPointer = 1;
	}

	model->setAddrPointer(addrPointer);

}

uint8_t* Log::getLogBookEntry(uint32_t addr) {

	if(addr == 0){
		uint8_t txBuffer[] = {0,0};
		static uint8_t rxBuffer[3];
		HAL_I2C_Master_Transmit(&hi2c1, (EEPROM_ADDR) << 1, txBuffer, 2, 100);
		HAL_I2C_Master_Receive(&hi2c1, EEPROM_ADDR << 1, rxBuffer, 3, 100);
		return rxBuffer;
	}else{
		uint32_t addrCounter = (addr*16-13);
		uint8_t txBuffer[2];


		addr = ((addrCounter)>>16)&0xFF;
		txBuffer[0] = ((addrCounter)>>8)&0xFF;
		txBuffer[1] = (addrCounter)&0xFF;

		static uint8_t rxBuffer[16];

		HAL_I2C_Master_Transmit(&hi2c1, (EEPROM_ADDR | addr) << 1, txBuffer, 2, 100);
		HAL_I2C_Master_Receive(&hi2c1, EEPROM_ADDR << 1, rxBuffer, 16, 100);
		return rxBuffer;
	}


}

void Log::addEntriy() {

	uint8_t txBuffer[18];

	uint32_t addrCounter = (addrPointer*16-13);

	uint8_t addr = ((addrCounter)>>16)&0xFF;

	txBuffer[0] = ((addrCounter)>>8)&0xFF;
	txBuffer[1] = (addrCounter)&0xFF;
	txBuffer[2] = model->getYear();
	txBuffer[3] = model->getMonth();
	txBuffer[4] = model->getDay();
	txBuffer[5] = model->getHour();
	txBuffer[6] = model->getMinute();
	txBuffer[7] = model->getSeconds();
	txBuffer[8] = ';';
	txBuffer[9] = (model->getWeight() >> 8) & 0xFF;
	txBuffer[10] = (model->getWeight()) & 0xFF;
	txBuffer[11] = ';';
	txBuffer[12] = (model->getPrize() >> 16) & 0xFF;
	txBuffer[13] = (model->getPrize() >> 8) & 0xFF;
	txBuffer[14] = (model->getPrize()) & 0xFF;
	txBuffer[15] = ';';
	txBuffer[16] = (uint8_t) model->getWachstyp();
	txBuffer[17] = '*';

	HAL_I2C_Master_Transmit(&hi2c1, (EEPROM_ADDR | addr) << 1, txBuffer, 18, 100);
	addrPointer++;
	model->setAddrPointer(addrPointer);

	//Update Addresspointer
	txBuffer[0] = 0;
	txBuffer[1] = 0;
	txBuffer[2] = (addrPointer >> 16) & 0x0000FF;
	txBuffer[3] = (addrPointer>>8)&0x0000FF;
	txBuffer[4] = (addrPointer & 0x0000FF);

	while(HAL_I2C_Master_Transmit(&hi2c1, (EEPROM_ADDR) << 1, txBuffer, 5, 100) != HAL_OK);

//	HAL_I2C_Master_Transmit(&hi2c1, (EEPROM_ADDR) << 1, txBuffer, 5, 100);
}


void Log::resetAddrPointer() {
	addrPointer = 1;
	model->setAddrPointer(addrPointer);
	uint8_t txBuffer[5];
	//Update Addresspointer

	txBuffer[0] = 0;
	txBuffer[1] = 0;

	txBuffer[2] = 0;
	txBuffer[3] = 0;
	txBuffer[4] = 1;

	HAL_I2C_Master_Transmit(&hi2c1, (EEPROM_ADDR) << 1, txBuffer, 5, 100);
}




