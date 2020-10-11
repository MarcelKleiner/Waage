/*
 * IScreen.cpp
 *
 *  Created on: Oct 10, 2020
 *      Author: marcel
 */
#include "BaseScreen.h"


BaseScreen::BaseScreen(){

}


void BaseScreen::Update() {

}

bool BaseScreen::isActive() const {
	return alive;
}

void BaseScreen::setActive(bool alive) {
	this->alive = alive;
}
