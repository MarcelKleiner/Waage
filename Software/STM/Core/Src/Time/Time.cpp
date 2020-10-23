/*
 * Time.cpp
 *
 *  Created on: 11.10.2020
 *      Author: marcel
 */

#include "Time.h"


Time::Time(Model *model, I2C_HandleTypeDef *hi2c) {
	this->model = model;
	this->hi2c = hi2c;

}

void Time::InitTimer() {

}


void Time::SetTime(uint8_t year, uint8_t month, uint8_t day, uint8_t hour,uint8_t minute, uint8_t seconds) {

	uint8_t txData[8] = {SECONDS};

	txData[0] = model->getSeconds();
	txData[1] = model->getMinute();
	txData[2] = model->getHour();
	txData[3] = model->getDay();
	txData[4] = model->getDayOfWeek();
	txData[5] = model->getMonth();
	txData[6] = model->getYear();

	HAL_I2C_Master_Transmit(hi2c, WRITE_ADDR, txData, sizeof(txData)/sizeof(txData[0]), I2C_TIMEOUT);

}


void Time::UpdateTime(){

	/*test = HAL_I2C_Master_Receive(hi2c, READ_ADDR<<1, rxData, 7, 100);

	model->setSeconds(rxData[0]);
	model->setMinute(rxData[1]);
	model->setHour(rxData[2]);
	model->setDay(rxData[3]);
	model->setDayOfWeek(rxData[4]);
	model->setMonth(rxData[5]);
	model->setYear(rxData[6]);*/
}
