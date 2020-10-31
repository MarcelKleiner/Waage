/*
 * TimeSettings.cpp
 *
 *  Created on: 11.10.2020
 *      Author: marcel
 */

#include "TimeSettings.h"

TimeSettings::TimeSettings(Model *model, LCD *lcd) {
	this->model = model;
	this->lcd = lcd;
}




Model::ESCREEN TimeSettings::Update(){

	screen = Model::E_TIME_SETTINGS;

	if(!init){
		position = 0;
		lcd->Write(line1,4,0,TimeToCharArray(model->getHour(), model->getMinute(), model->getSeconds()),8,4);
		lcd->SetCursorPosition(position+4, 2,true);
		init = true;
	}

	//lcd->Write(w,10,2,p,9,3);

	//------------------SW_BW------------------
	if(model->isT1Short()){
		//Change position
		if(position >= 7){
			position = 0;
		}else{
			position++;
			if(position == 2 || position == 5){
				position++;
			}
		}
		lcd->SetCursorPosition(position+4, 2, true);
		model->setT1Short(false);
	}
	if(model->isT1Long()){
		model->setT1Long(false);
	}

	//------------------SW_PW------------------
	if(model->isT2Short()){
		uint8_t hour = model->getHour();
		uint8_t minute = model->getMinute();
		uint8_t seconds = model->getSeconds();

		if(position == 0){
			if(hour < 13){
				hour += 10;
			}else if(hour <= 19){
				hour -= 10;
			}else{
				hour -= 20;
			}
		}

		if(position == 1){
			if(hour < 20){
				if(hour - (hour/10)*10 < 9){
					hour+=1;
				}else{
					hour-=9;
				}
			}else{
				if(hour - (hour/10)*10 < 3){
					hour+=1;
				}else{
					hour-=3;
				}
			}
		}



		if(position == 3){
			if(minute < 50){
				minute += 10;
			}else{
				minute -= 50;
			}
		}

		if(position == 4){
				if(minute - (minute/10)*10 < 9){
					minute+=1;
				}else{
					minute-=9;
				}
		}


		if(position == 6){
			if(seconds < 50){
				seconds += 10;
			}else{
				seconds -= 50;
			}
		}

		if(position == 7){
				if(seconds - (seconds/10)*10 < 9){
					seconds+=1;
				}else{
					seconds-=9;
				}
		}


		model->setHour(hour);
		model->setMinute(minute);
		model->setSeconds(seconds);
		lcd->Write(line1,4,0,TimeToCharArray(model->getHour(), model->getMinute(), model->getSeconds()),8,4);
		lcd->SetCursorPosition(position+4, 2, true);
		model->setT2Short(false);
	}
	if(model->isT2Long()){
		model->setT2Long(false);
	}

	//------------------SW_Summe------------------
	if(model->isT3Short()){
		model->setT3Short(false);
	}
	if(model->isT3Long()){
		model->setT3Long(false);
	}

	//------------------SW_Total------------------
	if(model->isT4Short()){
		model->setT4Short(false);
	}
	if(model->isT4Long()){
		model->setT4Long(false);
	}

	//------------------SW_Tar------------------
	if(model->isT5Short()){
		screen = Model::E_DATE_SETTINGS;
		init = false;
		model->setOverrideClock(true);
		model->setT5Short(false);
	}
	if(model->isT5Long()){
		screen = Model::E_MAIN_SCRREN;
		init = false;
		model->setOverrideClock(true);
		model->setT5Long(false);
	}


	return screen;
}




char* TimeSettings::TimeToCharArray(uint8_t hour, uint8_t minute, uint8_t seconds){
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
