/*
 * TimeSettings.h
 *
 *  Created on: 11.10.2020
 *      Author: marcel
 */

#ifndef SRC_SCREEN_TIMESETTINGS_H_
#define SRC_SCREEN_TIMESETTINGS_H_


#include "../../Model/Model.h"
#include "../../Model/Tools.h"
#include "../../LCD/LCD.h"

class TimeSettings{


public:
	TimeSettings(Model *model, LCD *lcd);
	Model::ESCREEN Update(void);
private:
	Model *model;
	LCD *lcd;
	Model::ESCREEN screen;

	uint8_t position;
	bool init;
	const char* line1 = "Zeit";

	char* TimeToCharArray(uint8_t hour, uint8_t minute, uint8_t seconds);
};

#endif /* SRC_SCREEN_TIMESETTINGS_H_ */
