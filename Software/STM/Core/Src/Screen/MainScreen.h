/*
 * MainScreen.h
 *
 *  Created on: Oct 10, 2020
 *      Author: marcel
 */

#ifndef SRC_SCREEN_MAINSCREEN_H_
#define SRC_SCREEN_MAINSCREEN_H_


#include "../Model/Model.h"
#include "../Model/Tools.h"
#include "../LCD/LCD.h"



class MainScreen {


public:
	MainScreen(Model *model, LCD *lcd);

	Model::ESCREEN Update(void);
	void Init(void);




private:
	Model *model;
	LCD *lcd;
	Model::ESCREEN screen;

	enum E_SUM_STATUS{
		SUMACTIVATED,
		SUMDEACTIVATED,
		TOTAL,
		TOTALEND
	};


	uint8_t summeCounter;
	E_SUM_STATUS summeActive;
	int32_t weightSum;
	int32_t prizeSum;
	int32_t prize;
};



#endif /* SRC_SCREEN_MAINSCREEN_H_ */
