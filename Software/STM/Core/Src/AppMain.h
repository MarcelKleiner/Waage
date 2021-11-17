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
#include "tim.h"
#include "LCD/Kontrast.h"
#include "Time/Time.h"
#include "Log/Log.h"
#include "usb_device.h"
#include "usbd_cdc_if.h"
//#include "Flash/Flash.h"


class AppMain {
public:
	AppMain();

	void mainF(void);
	void Init(void);
	void Clk(void);
	void ButtonUpdate(void);
	bool usbTransmit(uint8_t *data, uint8_t size);
	bool updateEnable = false;

	void ReadLogbook(uint32_t addr);
	void ResetLogBook();
private:


	uint32_t timeSynchroCounter;

};

#endif /* SRC_APPMAIN_H_ */
