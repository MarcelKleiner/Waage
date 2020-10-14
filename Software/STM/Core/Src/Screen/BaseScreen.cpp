/*
 * IScreen.cpp
 *
 *  Created on: Oct 10, 2020
 *      Author: marcel
 */
#include "BaseScreen.h"
#include "main.h"

BaseScreen::BaseScreen(){
	HAL_GPIO_WritePin(LED_BW_GPIO_Port, LED_BW_Pin, GPIO_PIN_RESET);
}


void BaseScreen::Update() {

}

bool BaseScreen::isActive() const {
	return alive;
}

void BaseScreen::setActive(bool alive) {
	this->alive = alive;
}
