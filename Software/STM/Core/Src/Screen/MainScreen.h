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



class MainScreen : public BaseScreen {


public:
	MainScreen(Model *model);



private:
	Model *model;



};



#endif /* SRC_SCREEN_MAINSCREEN_H_ */
