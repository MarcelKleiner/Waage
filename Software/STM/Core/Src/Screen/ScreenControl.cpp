/*
 * ScreenControl.cpp
 *
 *  Created on: 11.10.2020
 *      Author: marcel
 */

#include "ScreenControl.h"
using namespace std;
#include <string>




ScreenControl::ScreenControl(Model *model, Kontrast *contrast) {
	this->model = model;
	this->contrast = contrast;
	lcd  = new  LCD();
	mainScreen = new MainScreen(model, lcd);
	pwSettings = new PWSettings(model, lcd);
	bwSettings = new BWSettings(model, lcd);
	timeSettings = new TimeSettings(model, lcd);
	dateSettings = new DateSettings(model, lcd);
	timeScreen = new TimeScreen(model, lcd);
	kontrastSettings = new Contrast(model, lcd, contrast);
}

void ScreenControl::InitScreen(){
	lcd->InitLCD();

	string i = "10.000 kg";
	string a = "02.25 Fr";
	lcd->Write(i,a);
	currentScreen = Model::E_MAIN_SCRREN;
	nextScreen = Model::E_MAIN_SCRREN;

}


void ScreenControl::Update(){

	this->currentScreen = this->nextScreen;


	switch(currentScreen){

	case Model::E_MAIN_SCRREN:
		nextScreen = mainScreen->Update();
		break;
	case Model::E_BW_SETTINGS:
		nextScreen = bwSettings->Update();
		break;
	case Model::E_PW_SETTINGS:
		nextScreen = pwSettings->Update();
		break;
	case Model::E_TIME_SETTINGS:
		nextScreen = timeSettings->Update();
		break;
	case Model::E_DATE_SETTINGS:
		nextScreen = dateSettings->Update();
		break;
	case Model::E_LOG_BOOK:
		break;
	case Model::E_TIME:
		nextScreen =timeScreen->Update();
	break;
	case Model::E_KONTRAST_SETTINGS:
		nextScreen = kontrastSettings->Update();
		break;
	}
}


Model::ESCREEN ScreenControl::getCurrentScreen(){
	return this->currentScreen;
}
