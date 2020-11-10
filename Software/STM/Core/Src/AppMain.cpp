/*
 * AppMain.cpp
 *
 *  Created on: Oct 12, 2020
 *      Author: marcel
 */

#include "AppMain.h"

LoadCellSettings lcSettings1;
LoadCellSettings lcSettings2;
Model model;

LoadCell loadCell1; // = LoadCell(&model, 1);
LoadCell loadCell2; // = LoadCell(&model, 2);
Kontrast contrast = Kontrast();
ScreenControl screenControl = ScreenControl(&model, &contrast);
ButtonControl buttonControl = ButtonControl(&model);
Log logBook = Log(&model);

Time time = Time(&model, &hi2c1);
bool init = false;
uint8_t initCounter = 0;

AppMain::AppMain() {
	// TODO Auto-generated constructor stub
	lcSettings1.clkPort = CLK_L1_GPIO_Port;
	lcSettings1.clkPin = CLK_L1_Pin;
	lcSettings1.dataPort = DATA_L1_GPIO_Port;
	lcSettings1.dataPin = DATA_L1_Pin;
	lcSettings1.loadCellNr = 1;

	lcSettings2.clkPort = CLK_L2_GPIO_Port;
	lcSettings2.clkPin = CLK_L2_Pin;
	lcSettings2.dataPort = DATA_L2_GPIO_Port;
	lcSettings2.dataPin = DATA_L2_Pin;
	lcSettings2.loadCellNr = 2;

}

void AppMain::Init() {
	loadCell1.InitLoadCell(&model, lcSettings1);
	loadCell2.InitLoadCell(&model, lcSettings2);
	screenControl.InitScreen();
	contrast.setContrast(0x09);
	logBook.init();


	HAL_GPIO_WritePin(LED_PW_GPIO_Port, LED_PW_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_BW_GPIO_Port, LED_BW_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_SUM_GPIO_Port, LED_SUM_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCD_LIGHT_GPIO_Port, LCD_LIGHT_Pin, GPIO_PIN_RESET);

	time.UpdateTime();
	timeSynchroCounter = 0;
	model.setWachstyp(Model::E_PARAFINWACHS);

}

void AppMain::mainF() {
	while (true) {
		if (updateEnable)
			updateEnable = false;
		loadCell2.Update();
		loadCell1.Update(); //ToDo
		int32_t weight1 = (model.getLoadCell1() - model.getLoadCellOffset1())
				/ model.getLoadCellGradient1();
		int32_t weight2 = (model.getLoadCell2() - model.getLoadCellOffset2())
				/ model.getLoadCellGradient2();
		model.setWeight(weight1 + weight2);
		screenControl.Update();

		if (model.isOverrideClock()) {
			time.SetTime();
			model.setOverrideClock(false);
		}

		if(model.isAddEntry()){
			logBook.addEntriy();
			model.setAddEntry(false);
		}

		//Waage nullen
		if(!init && initCounter == 100){
			model.setLoadCellOffset1(model.getLoadCell1());
			model.setLoadCellOffset2(model.getLoadCell2());
			init = true;
		}
		initCounter++;
	}

}



bool AppMain::usbTransmit(uint8_t *data, uint8_t size){
	uint16_t counter = 0;
	while(CDC_Transmit_FS((uint8_t*) data, size) != USBD_OK){
		counter++;
		HAL_Delay(1);
		if(counter >= 200){
			return false;	//Trasmit faild
		}
	}
	return true;	//Transmit successful
}




void AppMain::ButtonUpdate() {
	buttonControl.UpdateButton();
}

void AppMain::Clk() {

	uint8_t seconds = model.getSeconds();
	uint8_t minute = model.getMinute();
	uint8_t hours = model.getHour();
	uint8_t day = model.getDay();
	uint8_t month = model.getMonth();
	uint8_t year = model.getYear();
	if (model.getSeconds() < 59) {
		seconds++;
	} else {
		seconds = 0;
		if (minute == 59) {
			minute = 0;
			if (hours == 23) {
				hours = 0;
				switch (month) {
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
					if (day == 31) {
						day = 1;
						month++;
					} else {
						day++;
					}
					break;
				case 12:
					if (day == 31) {
						day = 1;
						month = 1;
						year++;
					} else {
						day++;
					}
					break;
				case 4:
				case 6:
				case 9:
				case 11:
					if (day == 30) {
						day = 1;
						month++;
					} else {
						day++;
					}
					break;
				case 2:
					if (day == 28) {
						day = 1;
						month++;
					} else {
						day++;
					}
					break;
				}
			} else {
				hours++;
			}
		} else {
			minute++;
		}
	}

	if (screenControl.getCurrentScreen() != Model::E_TIME_SETTINGS
			&& screenControl.getCurrentScreen() != Model::E_DATE_SETTINGS) {
		model.setSeconds(seconds);
		model.setMinute(minute);
		model.setHour(hours);
		model.setDay(day);
		model.setMonth(month);
		model.setYear(year);
	}

	if (timeSynchroCounter < 60) {
		timeSynchroCounter++;
	} else {
		timeSynchroCounter = 0;
		if (screenControl.getCurrentScreen() != Model::E_TIME_SETTINGS
				&& screenControl.getCurrentScreen() != Model::E_DATE_SETTINGS) {
			time.UpdateTime();
		}
	}

}

void AppMain::ReadLogbook(uint32_t addr) {
	if(addr == 0){
		uint8_t txBuffer[3];
		txBuffer[0] = (model.getAddrPointer()>>16)&0xFF;
		txBuffer[1] = (model.getAddrPointer()>>8)&0xFF;
		txBuffer[2] = model.getAddrPointer()&0xFF;
		usbTransmit(txBuffer, 3);
	}else{
		uint8_t *txBuffer = logBook.getLogBookEntry(addr);
		usbTransmit(txBuffer, 16);
	}
}

void AppMain::ResetLogBook(){
	logBook.resetAddrPointer();
}
