/*
 * MainScreen.cpp
 *
 *  Created on: Oct 10, 2020
 *      Author: marcel
 */

#include "MainScreen.h"
#include "stdio.h"
#include <stdio.h>
#include <string.h>

using namespace std;

uint8_t weightStableCounter = 0;
bool entryAdded = false;
int32_t weight_1 = 0;;


MainScreen::MainScreen(Model *model, LCD *lcd) {
	this->model = model;
	this->lcd = lcd;
	this->screen = Model::E_MAIN_SCRREN;
	summeActive = SUMDEACTIVATED;
	weightSum = 0;
	prizeSum = 0;
}

void MainScreen::Init(){
	model->setLoadCellOffset1(model->getLoadCell1());
	model->setLoadCellOffset2(model->getLoadCell2());

}

Model::ESCREEN MainScreen::Update(){

	screen = Model::E_MAIN_SCRREN;

	//------------------Screen Update------------------
	if(model->getWachstyp() == Model::E_BIENENWACHS){
		prize = Tools::Round5Rp((model->getWeight())*model->getBienenwachsPreis()/100);
	}else if(model->getWachstyp() == Model::E_PARAFINWACHS){
		prize = Tools::Round5Rp((model->getWeight())*model->getParafinwachsPreis()/100);
	}else{
		prize = 0;
	}
	model->setPrize(prize);


	char asciiWeight[6];
	char asciiPrize[6];


	switch(summeActive){
	case SUMACTIVATED:
		strncpy(asciiWeight,Tools::intToAsciiChar(model->getWeight(),3),6);
		strncpy(asciiPrize,Tools::intToAsciiChar(0,2),6);
		entryAdded = false;
		HAL_GPIO_WritePin(LED_SUM_GPIO_Port, LED_SUM_Pin, GPIO_PIN_RESET);
		break;
	case SUMDEACTIVATED:
		strncpy(asciiWeight,Tools::intToAsciiChar(model->getWeight(),3),6);
		strncpy(asciiPrize,Tools::intToAsciiChar(prize,2),6);
		HAL_GPIO_WritePin(LED_SUM_GPIO_Port, LED_SUM_Pin, GPIO_PIN_SET);
		if(weightStableCounter < 150){
			weightStableCounter++;
		}else{
			int16_t actualWeight = model->getWeight();
			if(actualWeight < weight_1+5 && actualWeight > weight_1-5 && !entryAdded && actualWeight > 10){
				//im zielfenster
				model->setAddEntry(true);
				entryAdded = true;
			}else{
				weight_1 = actualWeight;
			}

			//zurücksetzen für nächster eintrag falls gewicht 0+/-10g
			if(actualWeight < 5 && actualWeight > -5){
				entryAdded = false;
			}
			weightStableCounter = 0;
		}



		break;
	case TOTAL:
		strncpy(asciiWeight,Tools::intToAsciiChar(weightSum,3),6);
		strncpy(asciiPrize,Tools::intToAsciiChar(prizeSum,2),6);
		model->setWeight(weightSum);
		model->setPrize(prizeSum);
		model->setWachstyp(Model::E_SUMME);
		if(!entryAdded){
			model->setAddEntry(true);
			entryAdded = true;
		}

		break;
	case TOTALEND:
		summeActive = SUMDEACTIVATED;
		summeCounter = 0;
		prizeSum = 0;
		weightSum = 0;
		model->setWachstyp(Model::E_PARAFINWACHS);
		break;
	}





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
			summeCounter++;
			weightSum = weightSum + model->getWeight();
			prizeSum = prizeSum + model->getPrize();
			lcd->Clear();
			HAL_Delay(100);

			summeActive = SUMACTIVATED;
	}

	//------------------Total------------------
	if(model->isT4Long()){
		model->setT4Long(false);
		screen = Model::E_TIME;

		summeActive = SUMDEACTIVATED;
		summeCounter = 0;
		weightSum = 0;
		prizeSum = 0;
	}
	if(model->isT4Short()){
		model->setT4Short(false);
		if(summeActive == SUMACTIVATED){
			summeActive = TOTAL;
		}else{
			summeActive = TOTALEND;
		}
	}


	//------------------Tar------------------
	if(model->isT5Long()){
		screen = Model::E_TIME_SETTINGS;
		model->setT5Long(false);
	}
	if(model->isT5Short()){
		model->setLoadCellOffset1(model->getLoadCell1());
		model->setLoadCellOffset2(model->getLoadCell2());
		model->setT5Short(false);
	}

	return screen;
}
