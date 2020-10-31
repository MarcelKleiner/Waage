/*
 * DateSettings.cpp
 *
 *  Created on: 17.10.2020
 *      Author: marce
 */

#include "DateSettings.h"

DateSettings::DateSettings(Model *model, LCD *lcd) {
	this->model = model;
	this->lcd = lcd;
	this->init = false;
}


Model::ESCREEN DateSettings::Update(){

	screen = Model::E_DATE_SETTINGS;

	if(!init){
		position = 0;
		lcd->Write(line1,5,0,DateToCharArray(model->getYear(), model->getMonth(), model->getDay()),12,2);
		lcd->SetCursorPosition(position+2, 2,true);
		init = true;
	}

	//lcd->Write(w,10,2,p,9,3);

	//------------------SW_BW------------------
	if(model->isT1Short()){
		//Change position
		if(position >= 9){
			position = 0;
		}else{
			position++;
			if(position == 2){
				position++;
			}
			if(position == 5){
				position += 3;
			}
		}
		lcd->SetCursorPosition(position+2, 2, true);
		model->setT1Short(false);
	}
	if(model->isT1Long()){
		model->setT1Long(false);
	}

	//------------------SW_PW------------------
	if(model->isT2Short()){
		uint8_t year = model->getYear();
		uint8_t month = model->getMonth();
		uint8_t day = model->getDay();
		//Tag
		if(position == 0){
			switch(month){
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if(day > 21 ){
					day = (day - (day/10)*10);
				}else{
					day+=10;
				}
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				if(day > 20 ){
					day = (day - (day/10)*10);
				}else{
					day+=10;
				}
				break;
			case 2:
				if(day > 18 ){
					day = (day - (day/10)*10);
				}else{
					day+=10;
				}
				break;
			default:
				day = 0;
				break;
			}
		}

		if(position == 1){
			switch(month){
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if(day > 30 ){
					day -= 1;
				}else if((day - (day/10)*10) < 9){
					day+=1;
				}else{
						day -=9;
				}
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				if(day > 20 && (day - (day/10)*10) > 7 ){
					day -= 8;
				}else if((day - (day/10)*10) < 9){
					day+=1;
				}else{
						day -=9;
				}
				break;
			case 2:
				if((day - (day/10)*10) < 9){
					day+=1;
				}else{
						day -=9;
				}
				break;
			default:
				day = 0;
				break;
			}
		}

		//Monat
		if(position == 3){
			if(month < 3){
				month +=10;
			}else if(month > 9){
				month -= 10;
			}
		}

		if(position == 4){
			if((month - (month/10)*10) < 9 && month < 12){
				month +=1;
			}else if(month > 11){
				month = month - 2;
			}else{
				month -= 9;
			}
		}

		switch(month){
					case 4:
					case 6:
					case 9:
					case 11:
						if(day > 30){
							day = 30;
						}
						break;
					case 2:
						if(day > 28){
							day = 28;
						}
						break;
					}

		//Jahr
		if(position == 8){
			if((year/10) < 9){
				year +=10;
			}else{
				year -= 90;
			}
		}

		if(position == 9){
			if((year - (year/10)*10) < 9){
				year +=1;
			}else{
				year -= 9;
			}
		}



		model->setYear(year);
		model->setMonth(month);
		model->setDay(day);
		lcd->Write(line1,5,0,DateToCharArray(model->getYear(), model->getMonth(), model->getDay()),12,2);
		lcd->SetCursorPosition(position+2, 2,true);
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
		screen = Model::E_KONTRAST_SETTINGS;
		model->setOverrideClock(true);
		init = false;
		model->setT5Short(false);
	}
	if(model->isT5Long()){
		//Speichern ToDo
		screen = Model::E_MAIN_SCRREN;
		model->setOverrideClock(true);
		init = false;
		model->setT5Long(false);
	}


	return screen;
}


char* DateSettings::DateToCharArray(uint8_t year, uint8_t month, uint8_t day){
	static char result[10];
	result[0] = day/10 + 0x30;
	result[1] = day - (day/10)*10 + 0x30;
	result[2] = '.';
	result[3] = month/10 + 0x30;
	result[4] = month - (month/10)*10 + 0x30;
	result[5] = '.';
	result[6] = '2';
	result[7] = '0';
	result[8] = year/10 + 0x30;
	result[9] = year - (year/10)*10 + 0x30;
	return result;
}
