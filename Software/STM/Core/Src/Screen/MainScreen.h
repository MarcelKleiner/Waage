/*
 * MainScreen.h
 *
 *  Created on: Oct 10, 2020
 *      Author: marcel
 */

#ifndef SRC_SCREEN_MAINSCREEN_H_
#define SRC_SCREEN_MAINSCREEN_H_

#include "IScreen.h"




class MainScreen : IScreen {


public:
	MainScreen();


private:
	bool active;

	void SetActive() override;
	bool IsActive() override;
	void Update() override;

};



#endif /* SRC_SCREEN_MAINSCREEN_H_ */
