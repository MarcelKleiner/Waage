/*
 * Contrast.cpp
 *
 *  Created on: 21.10.2020
 *      Author: marcel
 */

#include "Contrast.h"
#include "../../Model/Tools.h"

Contrast::Contrast(Model *model, LCD *lcd, Kontrast *contrast) {
	this->model = model;
	this->lcd = lcd;
	this->init = false;
	this->contrast = contrast;
	kontrast = model->getKontrast();
}

Model::ESCREEN Contrast::Update(void) {
		screen = Model::E_KONTRAST_SETTINGS;


		if(!init){

			lcd->Write(line1,8,0,Tools::byteToAscii(model->getKontrast()),3,9);
			lcd->SetCursorPosition(11, 2,true);
			init = true;
		}



		if(HAL_GPIO_ReadPin(SW_PW_GPIO_Port, SW_PW_Pin) == GPIO_PIN_RESET){
			model->setT2Long(false);
		}
		if(HAL_GPIO_ReadPin(SW_SUM_GPIO_Port, SW_SUM_Pin) == GPIO_PIN_RESET){
			model->setT3Long(false);
		}

		//------------------SW_BW------------------
		if(model->isT1Short()){
			model->setT1Short(false);
		}
		if(model->isT1Long()){
			model->setT1Long(false);
		}

		//------------------SW_PW------------------
		if(model->isT2Short()){
			if(kontrast < 100){
				model->setKontrast(kontrast++);
				lcd->Write(line1,8,0,Tools::byteToAscii(model->getKontrast()),3,9);
				lcd->SetCursorPosition(11, 2,true);
				this->contrast->setContrast(100-kontrast);
			}

			model->setT2Short(false);
		}
		if(model->isT2Long()){
			if(kontrast < 100){
				model->setKontrast(kontrast++);
				lcd->Write(line1,8,0,Tools::byteToAscii(model->getKontrast()),3,9);
				lcd->SetCursorPosition(11, 2,true);
				this->contrast->setContrast(100-kontrast);
			}
		}

		//------------------SW_Summe------------------
		if(model->isT3Short()){
			if(kontrast > 0){
			model->setKontrast(kontrast--);
			lcd->Write(line1,8,0,Tools::byteToAscii(model->getKontrast()),3,9);
			lcd->SetCursorPosition(11, 2,true);
			this->contrast->setContrast(100-kontrast);
			}
			model->setT3Short(false);
		}
		if(model->isT3Long()){
			if(kontrast > 0){
			model->setKontrast(kontrast--);
			lcd->Write(line1,8,0,Tools::byteToAscii(model->getKontrast()),3,9);
			lcd->SetCursorPosition(11, 2,true);
			this->contrast->setContrast(100-kontrast);
			}
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
			screen = Model::E_TIME_SETTINGS;
			init = false;
			model->setT5Short(false);
		}
		if(model->isT5Long()){
			//Speichern ToDo
			screen = Model::E_MAIN_SCRREN;
			init = false;
			model->setT5Long(false);
		}


		return screen;

}
