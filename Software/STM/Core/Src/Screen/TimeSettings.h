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

class TimeSettings : public BaseScreen {


public:
	TimeSettings(Model *model);

private:
	Model *model;

};

#endif /* SRC_SCREEN_TIMESETTINGS_H_ */
