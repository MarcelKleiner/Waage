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
#include "../Model/Tools.h"
#include "../LCD/LCD.h"
#include <string>

class BWSettings : public BaseScreen{
public:
	BWSettings(Model *model, LCD *lcd);
	Model::ESCREEN Update(void);
private:
	Model *model;
	LCD *lcd;
	Model::ESCREEN screen;


	uint8_t position;
	bool init;

};

#endif /* SRC_SCREEN_BWSETTINGS_H_ */
