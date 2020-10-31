/*
 * PWSettings.h
 *
 *  Created on: 11.10.2020
 *      Author: marcel
 */

#ifndef SRC_SCREEN_PWSETTINGS_H_
#define SRC_SCREEN_PWSETTINGS_H_


#include "../Model/Model.h"
#include "../Model/Tools.h"
#include "../LCD/LCD.h"


class PWSettings {

public:
	PWSettings(Model *model, LCD *lcd);
	Model::ESCREEN Update(void);

private:
	Model *model;
	LCD *lcd;
	Model::ESCREEN screen;

	uint8_t position;
	bool init;
	const char* line1 = "Parafinwachs";

	char* prizeToCharArray(uint32_t prize);
};

#endif /* SRC_SCREEN_PWSETTINGS_H_ */
