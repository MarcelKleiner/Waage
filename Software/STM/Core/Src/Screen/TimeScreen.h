/*
 * TimeScreen.h
 *
 *  Created on: Oct 18, 2020
 *      Author: marce
 */

#ifndef SRC_SCREEN_TIMESCREEN_H_
#define SRC_SCREEN_TIMESCREEN_H_

#include "BaseScreen.h"
#include "../Model/Model.h"
#include "../Model/Tools.h"
#include "../LCD/LCD.h"
#include <string>

class TimeScreen {

public:
	TimeScreen(Model *model, LCD *lcd);
	Model::ESCREEN Update(void);

private:
	Model *model;
	LCD *lcd;
	Model::ESCREEN screen;

	char* TimeToCharArray(uint8_t hour, uint8_t minute, uint8_t seconds);
};

#endif /* SRC_SCREEN_TIMESCREEN_H_ */
