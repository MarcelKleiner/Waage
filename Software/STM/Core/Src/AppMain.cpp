/*
 * AppMain.cpp
 *
 *  Created on: Oct 12, 2020
 *      Author: marcel
 */

#include "AppMain.h"





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



void AppMain::Init(){
	loadCell1.InitLoadCell(&model, lcSettings1);
	loadCell2.InitLoadCell(&model, lcSettings2);
	HAL_GPIO_WritePin(LED_PW_GPIO_Port, LED_PW_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_BW_GPIO_Port, LED_BW_Pin, GPIO_PIN_SET);
	screenControl.InitScreen();
	timeSynchroCounter = 0;
}


void AppMain::mainF(){
while(true){
	if(updateEnable)
	updateEnable = false;
	loadCell2.Update();
	//loadCell.Update(); //ToDo
	int32_t weight1 = (model.getLoadCell1()-model.getLoadCellOffset1()) /model.getLoadCellGradient1();
	int32_t weight2 = (model.getLoadCell2()-model.getLoadCellOffset2()) /model.getLoadCellGradient2();
	model.setWeight(weight2);
	model.setWeight(weight1 + weight2);
	screenControl.Update();
}


}

void AppMain::ButtonUpdate(){
	buttonControl.UpdateButton();
}


void AppMain::Clk(){



		if(timeSynchroCounter == 1800){
			timeSynchroCounter++;
		}else{
			//ToDo Time Synchro
			timeSynchroCounter = 0;
		}


		uint8_t seconds = model.getSeconds();
			uint8_t minute = model.getMinute();
			uint8_t hours = model.getHour();
			uint8_t day = model.getDay();
			uint8_t month = model.getMonth();
			uint8_t year = model.getYear();
			if(model.getSeconds() < 59){
				seconds++;
			}else{
				seconds = 0;
				if(minute == 59){
					minute = 0;
					if(hours == 23){
						hours = 0;
						switch(month){
								case 1:
								case 3:
								case 5:
								case 7:
								case 8:
								case 10:
									if(day == 31 ){
										day = 1;
										month++;
									}else{
										day++;
									}
									break;
								case 12:
									if(day == 31 ){
										day = 1;
										month = 1;
										year++;
									}else{
										day++;
									}
									break;
								case 4:
								case 6:
								case 9:
								case 11:
									if(day == 30 ){
										day = 1;
										month++;
									}else{
										day++;
									}
									break;
								case 2:
									if(day == 28 ){
										day= 1;
										month++;
									}else{
										day++;
									}
									break;
								}
					}else{
						hours++;
					}
				}else{
					minute++;
				}
			}

		if(screenControl.getCurrentScreen() != Model::E_TIME_SETTINGS && screenControl.getCurrentScreen() != Model::E_DATE_SETTINGS){
			model.setSeconds(seconds);
			model.setMinute(minute);
			model.setHour(hours);
			model.setDay(day);
			model.setMonth(month);
			model.setYear(year);
		}
}








