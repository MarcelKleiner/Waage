/*
 * LoadCell.cpp
 *
 *  Created on: 11.10.2020
 *      Author: marcel
 */

#include "LoadCell.h"


LoadCell::LoadCell( ) {
	this->model = model;
}

void LoadCell::InitLoadCell(Model *model, LoadCellSettings loadCellSettings){
	this->model = model;
	this->lcSettings = loadCellSettings;
}


void LoadCell::Update(){
	uint32_t data = 0;
	HAL_GPIO_WritePin(lcSettings.clkPort, lcSettings.clkPin, GPIO_PIN_RESET);
	if(HAL_GPIO_ReadPin(lcSettings.dataPort, lcSettings.dataPin) == GPIO_PIN_RESET){
		for(int i = 0; i<25; i++){
			HAL_GPIO_WritePin(lcSettings.clkPort, lcSettings.clkPin, GPIO_PIN_SET);
			Tools::DWT_Delay_us(10);
			HAL_GPIO_WritePin(lcSettings.clkPort, lcSettings.clkPin, GPIO_PIN_RESET);
			data = data + HAL_GPIO_ReadPin(lcSettings.dataPort, lcSettings.dataPin);
			data = data << 1;
			Tools::DWT_Delay_us(10);
		}
		data = data>>8;

		switch(this->lcSettings.loadCellNr){
		case 1:
			model->setLoadCell1(data);
			break;
		case 2:
			model->setLoadCell2(data);
			break;
		default:
			//Error not suportet nr
			break;
		}
	}

}

