/*
 * MainScreen.h
 *
 *  Created on: Oct 10, 2020
 *      Author: marcel
 */

#ifndef SRC_SCREEN_MAINSCREEN_H_
#define SRC_SCREEN_MAINSCREEN_H_

#include "BaseScreen.h"
#include "../Model/Model.h"
#include "../Model/Tools.h"
#include "../LCD/LCD.h"
#include <string>


class MainScreen : public BaseScreen {


public:
	MainScreen(Model *model, LCD *lcd);

	Model::ESCREEN Update(void);
	void Init(void);



private:
	Model *model;
	LCD *lcd;
	Model::ESCREEN screen;

	uint8_t summeCounter;
	bool summeActive;
};



#endif /* SRC_SCREEN_MAINSCREEN_H_ */
