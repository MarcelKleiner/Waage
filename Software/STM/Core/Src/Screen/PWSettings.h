/*
 * PWSettings.h
 *
 *  Created on: 11.10.2020
 *      Author: marcel
 */

#ifndef SRC_SCREEN_PWSETTINGS_H_
#define SRC_SCREEN_PWSETTINGS_H_

#include "BaseScreen.h"
#include "../Model/Model.h"
#include "../Model/Tools.h"
#include "../LCD/LCD.h"
#include <string>

class PWSettings : public BaseScreen{

public:
	PWSettings(Model *model, LCD *lcd);
	Model::ESCREEN Update(void);

private:
	Model *model;
	LCD *lcd;
	Model::ESCREEN screen;

	uint8_t position;
	bool init;
	string line1 = "Parafinwachs";

	char* prizeToCharArray(uint32_t prize);
};

#endif /* SRC_SCREEN_PWSETTINGS_H_ */
