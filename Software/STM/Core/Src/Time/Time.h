/*
 * Time.h
 *
 *  Created on: 11.10.2020
 *      Author: marcel
 */

#ifndef SRC_TIME_TIME_H_
#define SRC_TIME_TIME_H_

#include "stm32l412xx.h"
#include "i2c.h"
#include "../Model/Model.h"
#include "TimerConfig.h"

class Time {
public:
	Time(Model *model, I2C_HandleTypeDef *hi2c);

	void SetTime(uint8_t year,uint8_t month,uint8_t day,uint8_t hour,uint8_t minute,uint8_t seconds);
	void UpdateTime();


private:
	void InitTimer();

	Model *model;
	I2C_HandleTypeDef *hi2c;

};

#endif /* SRC_TIME_TIME_H_ */
