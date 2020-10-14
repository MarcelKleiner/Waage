/*
 * AppMain.cpp
 *
 *  Created on: Oct 12, 2020
 *      Author: marcel
 */

#include "AppMain.h"





AppMain::AppMain() {
	// TODO Auto-generated constructor stub
	comSettings2.CS_Pin = LC2_CS_Pin;
	comSettings2.CS_Port = LC2_CS_GPIO_Port;
	comSettings2.timeOut = 100;
	comSettings2.hspi = hspi1;

	comSettings1.CS_Pin = LC1_CS_Pin;
	comSettings1.CS_Port = LC1_CS_GPIO_Port;
	comSettings1.timeOut = 100;
	comSettings1.hspi = hspi1;



}



uint32_t testCounter = 0;

void AppMain::mainF(){

	loadCell1.InitLoadCell(comSettings1);
	loadCell2.InitLoadCell(comSettings2);
	HAL_GPIO_WritePin(LED_PW_GPIO_Port, LED_PW_Pin, GPIO_PIN_SET);
	HAL_Delay(1000);
	screenControl.InitScreen();



	while(true){

		if(testCounter < 9950030){
			testCounter = 0;
			loadCell2.Update();
		}else{
			testCounter++;
		}

		  if(HAL_GPIO_ReadPin(SW_TAR_GPIO_Port, SW_TAR_Pin) == GPIO_PIN_SET){
			  HAL_GPIO_WritePin(LED_BW_GPIO_Port, LED_BW_Pin, GPIO_PIN_RESET);
		  }else{
			  HAL_GPIO_WritePin(LED_BW_GPIO_Port, LED_BW_Pin, GPIO_PIN_SET);
		  }

		  if(HAL_GPIO_ReadPin(SW_TOTAL_GPIO_Port, SW_TOTAL_Pin) == GPIO_PIN_SET){

		  }else{

		  }

		  if(HAL_GPIO_ReadPin(SW_SUM_GPIO_Port, SW_SUM_Pin) == GPIO_PIN_SET){
			  HAL_GPIO_WritePin(LED_SUM_GPIO_Port, LED_SUM_Pin, GPIO_PIN_RESET);
		  }else{
			  HAL_GPIO_WritePin(LED_SUM_GPIO_Port, LED_SUM_Pin, GPIO_PIN_SET);
		  }


	}




}
