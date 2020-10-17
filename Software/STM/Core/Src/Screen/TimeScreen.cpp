/*
 * TimeScreen.cpp
 *
 *  Created on: Oct 18, 2020
 *      Author: marce
 */

#include "TimeScreen.h"

TimeScreen::TimeScreen(Model *model, LCD *lcd) {
	this->model= model;
	this->lcd = lcd;

}

Model::ESCREEN TimeScreen::Update(){

	screen = Model::E_TIME;

	lcd->Write("Zeit",0,TimeToCharArray(model->getHour(), model->getMinute(), model->getSeconds()),8,4);

	//------------------SW_BW------------------
	if(model->isT1Short()){
		model->setT1Short(false);
	}
	if(model->isT1Long()){
		model->setT1Long(false);
	}

	//------------------SW_PW------------------
	if(model->isT2Short()){
		model->setT2Short(false);
	}
	if(model->isT2Long()){
		model->setT2Long(false);
	}

	//------------------SW_Summe------------------
	if(model->isT3Short()){
		//-

		model->setT3Short(false);
	}
	if(model->isT3Long()){
		model->setT3Long(false);
	}


	//------------------SW_Total------------------
	if(model->isT4Long()){
		model->setT4Long(false);
	}
	if(model->isT4Short()){
		model->setT4Short(false);
	}


	//------------------SW_Tar------------------
	if(model->isT5Long()){
		screen = Model::E_MAIN_SCRREN;
		model->setT5Long(false);
	}
	if(model->isT5Short()){
		model->setT5Short(false);
	}

	return screen;
}

char* TimeScreen::TimeToCharArray(uint8_t hour, uint8_t minute, uint8_t seconds){
	static char result[8];

	result[0] = hour/10 + 0x30;
	result[1] = hour - (hour/10)*10 + 0x30;
	result[2] = ':';
	result[3] = minute/10 + 0x30;
	result[4] = minute - (minute/10)*10 + 0x30;
	result[5] = ':';
	result[6] = seconds/10 + 0x30;
	result[7] = seconds - (seconds/10)*10 + 0x30;
	return result;
}
