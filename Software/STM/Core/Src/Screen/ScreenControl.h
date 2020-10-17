/*
 * ScreenControl.h
 *
 *  Created on: 11.10.2020
 *      Author: marcel
 */

#ifndef SRC_SCREEN_SCREENCONTROL_H_
#define SRC_SCREEN_SCREENCONTROL_H_

#include "BaseScreen.h"
#include "MainScreen.h"
#include "PWSettings.h"
#include "BWSettings.h"
#include "Settings/TimeSettings.h"
#include "Settings/DateSettings.h"
#include "TimeScreen.h"
#include "stm32l4xx_hal.h"
#include "../Model/Model.h"
#include "../LCD/LCD.h"


class ScreenControl {
public:
	ScreenControl(Model *model);
	void InitScreen();
	void Update();
	Model::ESCREEN getCurrentScreen();

private:
	const static uint8_t ARRAY_SIZE = 4;

	Model::ESCREEN currentScreen;
	Model::ESCREEN nextScreen;

	Model *model;

	LCD *lcd;
	MainScreen *mainScreen;
	PWSettings *pwSettings;
	BWSettings *bwSettings;
	TimeSettings *timeSettings;
	DateSettings *dateSettings;
	TimeScreen *timeScreen;



};

#endif /* SRC_SCREEN_SCREENCONTROL_H_ */
