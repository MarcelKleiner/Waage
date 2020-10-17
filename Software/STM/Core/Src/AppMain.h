/*
 * AppMain.h
 *
 *  Created on: Oct 12, 2020
 *      Author: marcel
 */

#ifndef SRC_APPMAIN_H_
#define SRC_APPMAIN_H_

#include "LCD/LCD.h"
#include "Screen/ScreenControl.h"
#include "LoadCell/LoadCell.h"
#include "LoadCell/LoadCellConfig.h"
#include "main.h"
#include "ButtonControl/ButtonControl.h"

class AppMain {
public:
	AppMain();

	void mainF(void);


private:

	LoadCellSettings lcSettings1;
	LoadCellSettings lcSettings2;
	Model model;

	LoadCell loadCell1; // = LoadCell(&model, 1);
	LoadCell loadCell2; // = LoadCell(&model, 2);
	ScreenControl screenControl = ScreenControl(&model);
	ButtonControl buttonControl = ButtonControl(&model);

};

#endif /* SRC_APPMAIN_H_ */
