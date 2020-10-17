/*
 * LoadCellConfig.h
 *
 *  Created on: Oct 16, 2020
 *      Author: marcel
 */

#ifndef SRC_LOADCELL_LOADCELLCONFIG_H_
#define SRC_LOADCELL_LOADCELLCONFIG_H_


	struct LoadCellSettings{
		GPIO_TypeDef *clkPort;
		uint16_t clkPin;
		GPIO_TypeDef *dataPort;
		uint16_t dataPin;
		uint8_t loadCellNr;
	};


#endif /* SRC_LOADCELL_LOADCELLCONFIG_H_ */
