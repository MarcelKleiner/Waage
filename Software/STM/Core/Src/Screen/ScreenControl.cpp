/*
 * ScreenControl.cpp
 *
 *  Created on: 11.10.2020
 *      Author: marcel
 */

#include "ScreenControl.h"
using namespace std;



static LCD lcd;
static MainScreen *mainScreen;
static PWSettings *pwSettings;
static BWSettings *bwSettings;
static TimeSettings *timeSettings;
static DateSettings *dateSettings;
static TimeScreen *timeScreen;
static Contrast *kontrastSettings;



ScreenControl::ScreenControl(Model *model, Kontrast *contrast) {
	model = model;
	contrast = contrast;
	lcd  = LCD();
	mainScreen = new MainScreen(model, &lcd);
	pwSettings = new PWSettings(model, &lcd);
	bwSettings = new BWSettings(model, &lcd);
	timeSettings = new TimeSettings(model, &lcd);
	dateSettings = new DateSettings(model, &lcd);
	timeScreen = new TimeScreen(model, &lcd);
	kontrastSettings = new Contrast(model, &lcd, contrast);
}

void ScreenControl::InitScreen(){
	lcd.InitLCD();

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
