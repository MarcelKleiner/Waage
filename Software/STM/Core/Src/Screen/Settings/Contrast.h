/*
 * Contrast.h
 *
 *  Created on: 21.10.2020
 *      Author: marcel
 */

#ifndef SRC_SCREEN_SETTINGS_CONTRAST_H_
#define SRC_SCREEN_SETTINGS_CONTRAST_H_

#include "../../Model/Model.h"
#include "../../Model/Tools.h"
#include "../../LCD/LCD.h"
#include "../../LCD/Kontrast.h"


class Contrast {
public:
	Contrast(Model *model, LCD *lcd, Kontrast *contrast);
	Model::ESCREEN Update(void);

private:
	Model::ESCREEN screen;
	Model *model;
	LCD *lcd;
	Kontrast *contrast;
	const char* line1 = "Kontrast";
	bool init;
	uint8_t kontrast;
};

#endif /* SRC_SCREEN_SETTINGS_CONTRAST_H_ */
