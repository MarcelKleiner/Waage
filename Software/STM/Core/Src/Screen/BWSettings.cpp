/*
 * BWSettings.cpp
 *
 *  Created on: 11.10.2020
 *      Author: marcel
 */

#include "BWSettings.h"

BWSettings::BWSettings(Model *model, LCD *lcd) {
	this->model = model;
	position = 0;
	init = false;
}



Model::ESCREEN BWSettings::Update(){

	screen = Model::E_BW_SETTINGS;

	int preis = model->getBienenwachsPreis()*100;
	char *p = Tools::intToAsciiChar(preis, 2);
	char result[12];
	string line1 = "Bienenwachs";

	for(uint8_t i = 0; i<5;i++){
		result[i] = p[i+1];
	}

	result[5] = ' ';
	result[6] = 'F';
	result[7] = 'r';
	result[8] = '/';
	result[9] = '1';
	result[10] = '0';
	result[11] = '0';
	result[12] = 'g';

	if(!init){
		lcd->Write(line1,0,result,12,0);
		lcd->SetCursorPosition(position, 2,true);
		init = true;
	}


	//------------------SW_BW------------------
	if(model->isT1Short()){
		//Change position
		if(position >= 4){
			position = 0;
		}else{
			position++;
			if(position == 2){
				position++;
			}
		}

		lcd->Write(line1,0,result,12,0);
		lcd->SetCursorPosition(position, 2,true);
		model->setT1Short(false);
	}
	if(model->isT1Long()){
		model->setT1Long(false);
	}

	//------------------SW_PW------------------
	if(model->isT2Short()){

		if(position == 0){
			if((preis/1000 - (preis/10000)*10) == 9){
				preis -= 9000;
			}else{
				preis += 1000;
			}
		}

		if(position == 1){
			if((preis/100 - (preis/1000)*10) % 100 == 9){
				preis -= 900;
			}else{
				preis += 100;
			}
		}

		if(position == 2){
			if((preis/10 - (preis/100)*10) == 9){
				preis -= 90;
			}else{
				preis += 10;
			}
		}


		if(position == 3){
			if((preis - (preis/10)*10 ) == 9){
				preis -= 9;
			}else{
				preis += 1;
			}
		}
		model->setBienenwachsPreis(preis/100);
		lcd->Write(line1,0,result,12,0);
		lcd->SetCursorPosition(position, 2,true);
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
		//Neuer Wert speichern
		init = false;
		screen = Model::E_MAIN_SCRREN;
		model->setT5Long(false);
	}
	if(model->isT5Short()){
		model->setT5Short(false);
	}

	return screen;
}
