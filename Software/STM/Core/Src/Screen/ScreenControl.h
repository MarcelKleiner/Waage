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
#include "TimeSettings.h"
#include "stm32l4xx_hal.h"
#include "../Model/Model.h"


class ScreenControl {
public:
	ScreenControl();


private:
	const static uint8_t ARRAY_SIZE = 4;

	Model *model;

	BaseScreen mainScreen = MainScreen(model);
	BaseScreen pwSettings = PWSettings(model);
	BaseScreen bwSettings = BWSettings(model);
	BaseScreen timeSettings = TimeSettings(model);

	BaseScreen screens[ARRAY_SIZE] = {mainScreen, pwSettings, bwSettings,timeSettings};

};

#endif /* SRC_SCREEN_SCREENCONTROL_H_ */
