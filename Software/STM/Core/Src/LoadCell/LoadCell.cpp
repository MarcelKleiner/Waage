/*
 * LoadCell.cpp
 *
 *  Created on: 11.10.2020
 *      Author: marcel
 */

#include "LoadCell.h"

LoadCell::LoadCell(ComSettings comSettings , Model *model, uint8_t LC_Nr) {
	this->model = model;
	this->comSettings = comSettings;
	HAL_GPIO_WritePin(comSettings.CS_Port, comSettings.CS_Pin, GPIO_PIN_SET);
	loadCellNr = LC_Nr;
}




void LoadCell::Update(void){
	ReadValue();
}


void LoadCell::InitLoadCell(){
	uint8_t txData[2] = {0};

	txData[0] = Convert_30sps;
	Write(txData,1);

	txData[0] = REG_ACCES_CTRL3 | REG_ACCES_WRITE;
	txData[1] = DIGITAL_GAIN_4;
	Write(txData, 2);
}


/*	Read Data form MAX11210 (24bit ADC)
 *
 * @param: none
 * @return: none
 */
void LoadCell::ReadValue(){
	uint8_t txData[1] = {REG_ACCES_DATA | REG_ACCES_READ};
	uint8_t rxData[3] = {0};
	int32_t value = 0;

	WriteRead(txData, rxData);

	value = ((uint32_t)rxData[2]) << 16 |  ((uint32_t)rxData[1]) << 8 | ((uint32_t)rxData[1]);
	if(loadCellNr == 1){
		model->setLoadCell1(value);
	}else{
		model->setLoadCell2(value);
	}


}

/*	Checks if measurement data are available
 *
 * @param: none
 * @return <bool>: true if data available otherwise false
 */
bool LoadCell::IsDataAvailable(){
	uint8_t txData[1] = {REG_ACCES_STAT1 | REG_ACCES_READ};
	uint8_t rxData[1] = {0};

	WriteRead(txData, rxData);

	return rxData[0] & 0x01;

}





void LoadCell::Write(uint8_t* txData, uint8_t size){
	HAL_GPIO_WritePin(comSettings.CS_Port, comSettings.CS_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(comSettings.hspi, txData, size, comSettings.timeOut);
	HAL_GPIO_WritePin(comSettings.CS_Port, comSettings.CS_Pin, GPIO_PIN_SET);
}

void LoadCell::WriteRead(uint8_t* txData, uint8_t* rxData){

	uint8_t size = sizeof(txData)/sizeof(txData[0]) +sizeof(rxData)/sizeof(rxData[0]);

	HAL_GPIO_WritePin(comSettings.CS_Port, comSettings.CS_Pin, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(comSettings.hspi, txData,rxData, size, comSettings.timeOut);
	HAL_GPIO_WritePin(comSettings.CS_Port, comSettings.CS_Pin, GPIO_PIN_SET);
}


