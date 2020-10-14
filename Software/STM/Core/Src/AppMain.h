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
#include "spi.h"

class AppMain {
public:
	AppMain();

	void mainF(void);


private:

	ComSettings comSettings1;
	ComSettings comSettings2;
	Model model;

	LoadCell loadCell1 = LoadCell(&model, 1);
	LoadCell loadCell2 = LoadCell(&model, 2);
	ScreenControl screenControl = ScreenControl();

};

#endif /* SRC_APPMAIN_H_ */
