/*
 * ButtonControl.h
 *
 *  Created on: Oct 16, 2020
 *      Author: marcel
 */

#ifndef SRC_BUTTONCONTROL_BUTTONCONTROL_H_
#define SRC_BUTTONCONTROL_BUTTONCONTROL_H_

#include "main.h"
#include "stm32l412xx.h"
#include "../Model/Model.h"


#define READ_SW_BW HAL_GPIO_ReadPin(SW_BW_GPIO_Port, SW_BW_Pin)
#define READ_SW_PW HAL_GPIO_ReadPin(SW_PW_GPIO_Port, SW_PW_Pin)
#define READ_SW_SUM HAL_GPIO_ReadPin(SW_SUM_GPIO_Port, SW_SUM_Pin)
#define READ_SW_TOTAL HAL_GPIO_ReadPin(SW_TOTAL_GPIO_Port, SW_TOTAL_Pin)
#define READ_SW_TAR HAL_GPIO_ReadPin(SW_TAR_GPIO_Port, SW_TAR_Pin)

#define LONG_BUTTON_TIME	100
#define SHORT_BUTTON_TIME	2


class ButtonControl {
public:
	ButtonControl(Model *model);
	void UpdateButton(void);

private:
	bool T1last;
	bool T2last;
	bool T3last;
	bool T4last;
	bool T5last;

	uint8_t T1Counter;
	uint8_t T2Counter;
	uint8_t T3Counter;
	uint8_t T4Counter;
	uint8_t T5Counter;

	Model *model;
};

#endif /* SRC_BUTTONCONTROL_BUTTONCONTROL_H_ */
