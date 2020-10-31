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

void Time::SetTime() {

	SetTime(model->getYear(),model->getMonth(),model->getDay(),model->getHour(),model->getMinute(),model->getSeconds());

}

void Time::InitTimer() {

}


void Time::SetTime(uint8_t year, uint8_t month, uint8_t day, uint8_t hour,uint8_t minute, uint8_t seconds) {

	uint8_t txData[8];

	txData[0] = 0x02;
	txData[1] = Tools::BCDEncoder(seconds);
	txData[2] = Tools::BCDEncoder(minute);
	txData[3] = Tools::BCDEncoder(hour);
	txData[4] = Tools::BCDEncoder(day);
	txData[5] = 0x01;
	txData[6] = Tools::BCDEncoder(month);
	txData[7] = Tools::BCDEncoder(year);

	HAL_I2C_Master_Transmit(hi2c, TIME_ADDR<<1, txData, sizeof(txData)/sizeof(txData[0]), I2C_TIMEOUT);

}


void Time::UpdateTime(){
	uint8_t rxData[7];
	uint8_t txData[1];
	txData[0] = 0x02;

	HAL_I2C_Master_Transmit(hi2c,TIME_ADDR<<1 ,txData , 1, 100);
	HAL_I2C_Master_Receive(hi2c, TIME_ADDR<<1, rxData, 7, 100);

	model->setSeconds(Tools::BCDDecoder((rxData[0])&0x7F));
	model->setMinute(Tools::BCDDecoder((rxData[1])&0x7F));
	model->setHour(Tools::BCDDecoder((rxData[2])&0x3F));
	model->setDay(Tools::BCDDecoder((rxData[3])&0x3F));
	model->setDayOfWeek(Tools::BCDDecoder((rxData[4])&0x03));
	model->setMonth(Tools::BCDDecoder((rxData[5])&0x1F));
	model->setYear(Tools::BCDDecoder((rxData[6])&0xFF));
}
