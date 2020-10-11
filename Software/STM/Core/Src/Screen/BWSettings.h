/*
 * BWSettings.h
 *
 *  Created on: 11.10.2020
 *      Author: marcel
 */

#ifndef SRC_SCREEN_BWSETTINGS_H_
#define SRC_SCREEN_BWSETTINGS_H_

#include "BaseScreen.h"
#include "../Model/Model.h"

class BWSettings : public BaseScreen{
public:
	BWSettings(Model *model);

private:
	Model *model;

};

#endif /* SRC_SCREEN_BWSETTINGS_H_ */
