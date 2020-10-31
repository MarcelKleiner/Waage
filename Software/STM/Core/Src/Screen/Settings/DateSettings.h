/*
 * DateSettings.h
 *
 *  Created on: 17.10.2020
 *      Author: marce
 */

#ifndef SRC_SCREEN_SETTINGS_DATESETTINGS_H_
#define SRC_SCREEN_SETTINGS_DATESETTINGS_H_

#include "../../Model/Model.h"
#include "../../Model/Tools.h"
#include "../../LCD/LCD.h"


class DateSettings {
public:
	DateSettings(Model *model, LCD *lcd);
	Model::ESCREEN Update(void);

private:
	Model *model;
	LCD *lcd;
	Model::ESCREEN screen;

	const char* line1 = "Datum";
	uint8_t position;
	bool init;
	char* DateToCharArray(uint8_t year, uint8_t month, uint8_t day);
};

#endif /* SRC_SCREEN_SETTINGS_DATESETTINGS_H_ */
