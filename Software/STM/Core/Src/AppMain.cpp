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



uint32_t testCounter = 0;

void AppMain::mainF(){

	loadCell1.InitLoadCell(&model, lcSettings1);
	loadCell2.InitLoadCell(&model, lcSettings2);
	HAL_GPIO_WritePin(LED_PW_GPIO_Port, LED_PW_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_BW_GPIO_Port, LED_BW_Pin, GPIO_PIN_SET);
	screenControl.InitScreen();


	while(true){

		if(testCounter > 99999){
			testCounter = 0;

			loadCell2.Update();

			int32_t weight1 = (model.getLoadCell1()-model.getLoadCellOffset1()) /model.getLoadCellGradient1();
			int32_t weight2 = (model.getLoadCell2()-model.getLoadCellOffset2()) /model.getLoadCellGradient2();

			model.setWeight(weight2);

			buttonControl.UpdateButton();
			screenControl.Update();

		}else{
			testCounter++;
		}


		if(testCounter%5000 == 0){
			buttonControl.UpdateButton();
		}


	}




}
