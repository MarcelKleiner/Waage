/*
 * Log.cpp
 *
 *  Created on: Oct 31, 2020
 *      Author: marcel
 */

#include "Log.h"

Log::Log(Model *model) {
	this->model = model;
	addrPointer = 0;
}

void Log::init() {

	uint8_t txBuffer[] = { 0x00, 0x00 };
	uint8_t rxBuffer[] = { 0, 0 };
	HAL_I2C_Master_Transmit(&hi2c1, EEPROM_ADDR << 1, txBuffer, 2, 100);
	HAL_I2C_Master_Receive(&hi2c1, EEPROM_ADDR << 1, rxBuffer, 2, 100);
	if((addrPointer = ((rxBuffer[0] << 8) + rxBuffer[1])) < 1){
		addrPointer = 1;
	}

	model->setAddrPointer(addrPointer);

}

uint8_t* Log::getLogBookEntry(uint32_t addr) {

	addr = addr*16;
	uint8_t txBuffer[2];

	txBuffer[0] = (addr>>16)&0xFF;
	txBuffer[1] = (addr>>8)&0xFF;
	txBuffer[2] = addr&0xFF;

	static uint8_t rxBuffer[16];

	HAL_I2C_Master_Transmit(&hi2c1, EEPROM_ADDR << 1, txBuffer, 2, 100);
	HAL_I2C_Master_Receive(&hi2c1, EEPROM_ADDR << 1, rxBuffer, 16, 100);
	return rxBuffer;
}

void Log::addEntriy() {

	uint8_t txBuffer[18];

	uint8_t addr = (addrPointer>>16)&0xFF;

	txBuffer[0] = (addrPointer>>8)&0xFF;
	txBuffer[1] = addrPointer&0xFF;
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
	txBuffer[2] = (addrPointer>>8)&0xFF;
	txBuffer[3] = (addrPointer & 0xFF);
	HAL_I2C_Master_Transmit(&hi2c1, (EEPROM_ADDR | addr) << 1, txBuffer, 4, 100);
}


void Log::resetAddrPointer() {
	addrPointer = 0;

	uint8_t txBuffer[4];
	//Update Addresspointer
	txBuffer[0] = 0;
	txBuffer[1] = 0;
	txBuffer[2] = (addrPointer>>8)&0xFF;
	txBuffer[3] = (addrPointer & 0xFF);
	HAL_I2C_Master_Transmit(&hi2c1, (EEPROM_ADDR) << 1, txBuffer, 4, 100);
}




