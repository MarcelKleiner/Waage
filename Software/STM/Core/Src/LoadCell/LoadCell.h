/*
 * LoadCell.h
 *
 *  Created on: 11.10.2020
 *      Author: marcel
 */

#ifndef SRC_LOADCELL_LOADCELL_H_
#define SRC_LOADCELL_LOADCELL_H_

#include "spi.h"
#include "../Model/Model.h"
#include "LoadCellConfig.h"


class LoadCell {


public:

	struct ComSettings{
		SPI_HandleTypeDef* hspi;
		GPIO_TypeDef* CS_Port;
		uint16_t CS_Pin;
		uint32_t timeOut;
	};

	LoadCell(ComSettings comSettings, Model *model, uint8_t LC_Nr);

	void Update(void);


private:
	ComSettings comSettings;
	Model *model;

	uint8_t loadCellNr;

	void ReadValue(void);
	void InitLoadCell(void);
	bool IsDataAvailable(void);


	void Write(uint8_t* txData, uint8_t size);
	void WriteRead(uint8_t* txData, uint8_t* rxData);



};

#endif /* SRC_LOADCELL_LOADCELL_H_ */
