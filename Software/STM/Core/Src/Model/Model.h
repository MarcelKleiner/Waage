/*
 * Model.h
 *
 *  Created on: 11.10.2020
 *      Author: marcel
 */

#ifndef SRC_MODEL_MODEL_H_
#define SRC_MODEL_MODEL_H_

#include "../LCD/LCD.h"
#include "stm32l412xx.h"

class Model {

private:

	int32_t loadCell1;
	int32_t loadCell2;
	int16_t weight;

	uint8_t year;
	uint8_t month;
	uint8_t day;
	uint8_t dayOfWeek;
	uint8_t hour;
	uint8_t minute;
	uint8_t seconds;

public:
	Model();
	uint8_t getDay() const;
	void setDay(uint8_t day);

	uint8_t getDayOfWeek() const;
	void setDayOfWeek(uint8_t dayOfWeek);

	uint8_t getHour() const;
	void setHour(uint8_t hour);

	int32_t getLoadCell1() const;
	void setLoadCell1(int32_t loadCell1);

	int32_t getLoadCell2() const;
	void setLoadCell2(int32_t loadCell2);

	uint8_t getMinute() const;
	void setMinute(uint8_t minute);

	uint8_t getMonth() const;
	void setMonth(uint8_t month);

	uint8_t getSeconds() const;
	void setSeconds(uint8_t seconds);

	int16_t getWeight() const;
	void setWeight(int16_t weight);

	uint8_t getYear() const;
	void setYear(uint8_t year);
};

#endif /* SRC_MODEL_MODEL_H_ */
