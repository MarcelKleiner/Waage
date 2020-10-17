/*
 * MainScreen.cpp
 *
 *  Created on: Oct 10, 2020
 *      Author: marcel
 */

#include "MainScreen.h"

using namespace std;


MainScreen::MainScreen(Model *model, LCD *lcd) {
	this->model = model;
	this->lcd = lcd;
	this->screen = Model::E_MAIN_SCRREN;
}

void MainScreen::Init(){
	model->setLoadCellOffset1(model->getLoadCell1());
	model->setLoadCellOffset2(model->getLoadCell2());
}

Model::ESCREEN MainScreen::Update(){

	screen = Model::E_MAIN_SCRREN;

	//------------------Screen Update------------------
	int prize = 0;
	if(model->getWachstyp() == Model::E_BIENENWACHS){
		prize = Tools::Round5Rp((model->getWeight())*model->getBienenwachsPreis());
	}else if(model->getWachstyp() == Model::E_PARAFINWACHS){
		prize = Tools::Round5Rp((model->getWeight())*model->getParafinwachsPreis());
	}


	char *asciiWeight = {Tools::intToAsciiChar(model->getWeight(),3)};

	char w[9];
	char p[9];
	if(model->getWeight() < 0){
		w[0] = '-';
	}else{
		w[0] = ' ';
	}

	w[1] = asciiWeight[0];
	w[2] = asciiWeight[1];
	w[3] = asciiWeight[2];
	w[4] = asciiWeight[3];
	w[5] = asciiWeight[4];
	w[6] = asciiWeight[5];
	w[7] = ' ';
	w[8] = 'k';
	w[9] = 'g';


	char* asciiPrize = {Tools::intToAsciiChar(prize, 2)};
	p[0] = asciiPrize[0];
	p[1] = asciiPrize[1];
	p[2] = asciiPrize[2];
	p[3] = asciiPrize[3];
	p[4] = asciiPrize[4];
	p[5] = asciiPrize[5];
	p[6] = ' ';
	p[7] = 'F';
	p[8] = 'r';



	lcd->Write(w,10,2,p,9,3);

	//------------------Bienenwachs------------------
	if(model->isT1Short()){
		//Binenwach select
		model->setWachstyp(Model::E_BIENENWACHS);
		model->setT1Short(false);
	}
	if(model->isT1Long()){
		screen = Model::E_BW_SETTINGS;
		model->setT1Long(false);
	}


	//------------------Parafinwachs------------------
	if(model->isT2Short()){
		//Parafin wachs select
		model->setWachstyp(Model::E_PARAFINWACHS);
		model->setT2Short(false);
	}
	if(model->isT2Long()){
		//Parafinwachs settings
		screen = Model::E_PW_SETTINGS;
		model->setT2Long(false);
	}

	//------------------Summe------------------
	if(model->isT3Long()){
		model->setT3Long(false);
	}

	if(model->isT3Short()){
		//Summe Aktivierten oder summieren
		model->setT3Short(false);
		if(summeActive){
			summeCounter++;
		}else{
			summeActive = true;
			summeCounter= 1;
			HAL_GPIO_WritePin(LED_SUM_GPIO_Port, LED_SUM_Pin, GPIO_PIN_RESET);
		}
	}

	//------------------Total------------------
	if(model->isT4Long()){
		model->setT4Long(false);
		screen = Model::E_TIME_SETTINGS;
	}
	if(model->isT4Short()){
		model->setT4Short(false);
		summeActive = false;
		HAL_GPIO_WritePin(LED_SUM_GPIO_Port, LED_SUM_Pin, GPIO_PIN_SET);
		summeCounter = 0;
	}


	//------------------Tar------------------
	if(model->isT5Long()){
		model->setT5Long(false);
		model->setLoadCellOffset1(model->getLoadCell1());
		model->setLoadCellOffset2(model->getLoadCell2());
	}
	if(model->isT5Short()){
		model->setT5Short(false);
	}

	return screen;
}
