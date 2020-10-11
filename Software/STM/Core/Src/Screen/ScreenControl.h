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


class ScreenControl {
public:
	ScreenControl();


private:

	BaseScreen mainScreen = MainScreen();
	BaseScreen pwSettings = PWSettings();
	BaseScreen bwSettings = BWSettings();
	BaseScreen timeSettings = TimeSettings();

};

#endif /* SRC_SCREEN_SCREENCONTROL_H_ */
