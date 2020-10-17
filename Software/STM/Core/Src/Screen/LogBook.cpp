/*
 * LogBook.cpp
 *
 *  Created on: 11.10.2020
 *      Author: marcel
 */

#include "LogBook.h"

LogBook::LogBook(Model *model, LCD *lcd) {
	this->model = model;

}


Model::ESCREEN LogBook::Update(){

	screen = Model::E_MAIN_SCRREN;


	//lcd->Write(w,10,2,p,9,3);

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
	if(model->isT3Long()){
		model->setT3Long(false);
	}

	if(model->isT3Short()){
		model->setT3Short(false);
	}

	//------------------SW_Total------------------
	if(model->isT4Long()){
		model->setT4Long(false);
		screen = Model::E_TIME_SETTINGS;
	}
	if(model->isT4Short()){
		model->setT4Short(false);
	}


	//------------------SW_Tar------------------
	if(model->isT5Long()){
		model->setT5Long(false);
	}
	if(model->isT5Short()){
		model->setT5Short(false);
	}

	return screen;
}
