/*
 * LoadCell.cpp
 *
 *  Created on: 11.10.2020
 *      Author: marcel
 */

#include "LoadCell.h"


LoadCell::LoadCell( Model *model, uint8_t LC_Nr) {
	this->model = model;

	HAL_GPIO_WritePin(comSettings.CS_Port, comSettings.CS_Pin, GPIO_PIN_SET);
	loadCellNr = LC_Nr;
}




void LoadCell::Update(void){
	ReadValue();
}


void LoadCell::InitLoadCell(ComSettings comSettings){
	this->comSettings = comSettings;
	uint8_t txData[2] = {0};


	txData[0] = REG_ACCES_CTRL1 | REG_ACCES_WRITE  | 0xC0;
	//txData[1] = 0x80;
	txData[1] = 0x58;
	Write(txData, 2);

	txData[0] = REG_ACCES_CTRL3 | REG_ACCES_WRITE  | 0xC0;
	txData[1] =  DIGITAL_GAIN_1 |  0x1E;
	Write(txData, 2);


	txData[0] = Convert_5sps;
	Write(txData,1);


	txData[0] = 0b00010000;
	Write(txData,1);
	HAL_Delay(240);


	txData[0] = 0b00010000;
	Write(txData,1);
	HAL_Delay(150);

	txData[0] = 0b00010000 | 0b00100000;
	Write(txData,1);
	HAL_Delay(150);



}

uint32_t valu[100];
uint16_t counter = 0;
int32_t wert = 0;
/*	Read Data form MAX11210 (24bit ADC)
 *
 * @param: none
 * @return: none
 */
void LoadCell::ReadValue(){
	uint8_t txData[1] = {REG_ACCES_DATA | REG_ACCES_READ | 0xC0};
	uint8_t rxData[3] = {0};
	int32_t value = 0;

	if(IsDataAvailable()){
		WriteRead(txData, rxData,1,3);

		value = ((uint32_t)rxData[0]) << 16 |  ((uint32_t)rxData[1]) << 8 | ((uint32_t)rxData[2]);

		if(loadCellNr == 1){
			model->setLoadCell1(value);
		}else{
			if(counter >100){
				for(int8_t i = 0; i<100; i++){
					wert = wert+ valu[i];
				}
				wert = wert/100;
				counter = 0;
				wert = 0;
			}else{
				valu[counter] = value;
				counter++;
			}


			model->setLoadCell2(value);
		}
	}
}

/*	Checks if measurement data are available
 *
 * @param: none
 * @return <bool>: true if data available otherwise false
 */
bool LoadCell::IsDataAvailable(){
	uint8_t txData[1] = {REG_ACCES_STAT1 | REG_ACCES_READ | 0xC0};
	uint8_t rxData[1] = {0};
	WriteRead(txData, rxData, 1, 1);

return rxData[0] & 0x01;
}





void LoadCell::Write(uint8_t* txData, uint8_t size){
	HAL_GPIO_WritePin(comSettings.CS_Port, comSettings.CS_Pin, GPIO_PIN_RESET);
	while(HAL_SPI_Transmit(&hspi1, (uint8_t*)txData, size, 5000) != HAL_OK){};
	HAL_GPIO_WritePin(comSettings.CS_Port, comSettings.CS_Pin, GPIO_PIN_SET);
}

void LoadCell::WriteRead(uint8_t* txData, uint8_t* rxData, uint8_t txSize, uint8_t rxSize){

	HAL_GPIO_WritePin(comSettings.CS_Port, comSettings.CS_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi1, (uint8_t*)txData, txSize, 500);
	HAL_SPI_Receive(&hspi1, (uint8_t*)rxData, rxSize, 500);
	HAL_GPIO_WritePin(comSettings.CS_Port, comSettings.CS_Pin, GPIO_PIN_SET);
}


