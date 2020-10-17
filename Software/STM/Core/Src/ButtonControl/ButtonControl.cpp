/*
 * ButtonControl.cpp
 *
 *  Created on: Oct 16, 2020
 *      Author: marcel
 */

#include "ButtonControl.h"
#include "main.h"

ButtonControl::ButtonControl(Model *model) {
	// TODO Auto-generated constructor stub
	T1last = false;
	T2last = false;
	T3last = false;
	T4last = false;
	T5last = false;
	this->model = model;
}

/*
 * Udate Butteon control
 * call every 10ms
 *
 *
 */
void ButtonControl::UpdateButton() {

//---------------------SW1---------------------
	if (READ_SW_BW) {
		T1Counter++;
	}

	if (T1Counter > SHORT_BUTTON_TIME && T1Counter < LONG_BUTTON_TIME
			&& !READ_SW_BW) {
		model->setT1Short(true);
		T1Counter = 0;
	}

	if (T1Counter > LONG_BUTTON_TIME && !T1last) {
		model->setT1Long(true);
		T1last = true;
	}

	if (!READ_SW_BW) {
		T1last = false;
		T1Counter = 0;
	}

	//---------------------SW2---------------------
	if (READ_SW_PW) {
		T2Counter++;
	}

	if (T2Counter > SHORT_BUTTON_TIME && T2Counter < LONG_BUTTON_TIME
			&& !READ_SW_PW) {
		model->setT2Short(true);
		T2Counter = 0;
	}

	if (T2Counter > LONG_BUTTON_TIME && !T2last) {
		model->setT2Long(true);
		T2last = true;
	}

	if (!READ_SW_PW) {
		T2last = false;
		T2Counter = 0;
	}

	//---------------------SW3---------------------
	if (READ_SW_SUM) {
		T3Counter++;
	}

	if (T3Counter > SHORT_BUTTON_TIME && T3Counter < LONG_BUTTON_TIME
			&& !READ_SW_SUM) {
		model->setT3Short(true);
		T3Counter = 0;
	}

	if (T3Counter > LONG_BUTTON_TIME && !T3last) {
		model->setT3Long(true);
		T3last = true;
	}

	if (!READ_SW_SUM) {
		T3last = false;
		T3Counter = 0;
	}

	//---------------------SW4---------------------
	if (READ_SW_TOTAL) {
		T4Counter++;
	}

	if (T4Counter > SHORT_BUTTON_TIME && T4Counter < LONG_BUTTON_TIME
			&& !READ_SW_TOTAL) {
		model->setT4Short(true);
		T4Counter = 0;
	}

	if (T4Counter > LONG_BUTTON_TIME && !T4last) {
		model->setT4Long(true);
		T4last = true;
	}

	if (!READ_SW_TOTAL) {
		T4last = false;
		T4Counter = 0;
	}

	//---------------------SW5---------------------
	if (READ_SW_TAR) {
		T5Counter++;
	}

	if (T5Counter > SHORT_BUTTON_TIME && T5Counter < LONG_BUTTON_TIME
			&& !READ_SW_TAR) {
		model->setT5Short(true);
		T5Counter = 0;
	}

	if (T5Counter > LONG_BUTTON_TIME && !T5last) {
		model->setT5Long(true);
		T5last = true;
	}

	if (!READ_SW_TAR) {
		T5last = false;
		T5Counter = 0;
	}



}
