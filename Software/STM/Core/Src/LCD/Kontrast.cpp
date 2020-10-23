/*
 * Kontrast.cpp
 *
 *  Created on: Oct 20, 2020
 *      Author: marcel
 */

#include "Kontrast.h"
#include "i2c.h"



Kontrast::Kontrast() {
	// TODO Auto-generated constructor stub

}

void Kontrast::setContrast(uint8_t data) {
	uint8_t txData[2];
	txData[0] = 0x00;
	txData[1] = data;

 HAL_I2C_Master_Transmit(&hi2c1,0x2E<<1, (uint8_t*)txData,2,1000);

}
