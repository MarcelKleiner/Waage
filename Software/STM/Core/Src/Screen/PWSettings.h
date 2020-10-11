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

class PWSettings : public BaseScreen{

public:
	PWSettings(Model *model);


private:
	Model *model;
};

#endif /* SRC_SCREEN_PWSETTINGS_H_ */
