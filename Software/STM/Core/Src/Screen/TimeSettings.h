/*
 * TimeSettings.h
 *
 *  Created on: 11.10.2020
 *      Author: marcel
 */

#ifndef SRC_SCREEN_TIMESETTINGS_H_
#define SRC_SCREEN_TIMESETTINGS_H_

#include "BaseScreen.h"
#include "../Model/Model.h"
#include "../Model/Tools.h"
#include "../LCD/LCD.h"
#include <string>

class TimeSettings : public BaseScreen {


public:
	TimeSettings(Model *model, LCD *lcd);
	Model::ESCREEN Update(void);
private:
	Model *model;
	LCD *lcd;
	Model::ESCREEN screen;

};

#endif /* SRC_SCREEN_TIMESETTINGS_H_ */
