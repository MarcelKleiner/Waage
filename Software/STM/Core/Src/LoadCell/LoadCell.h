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


	LoadCell(Model *model, uint8_t LC_Nr) ;
	void InitLoadCell(ComSettings comSettings);
	void Update(void);


private:
	ComSettings comSettings;
	Model *model;

	uint8_t loadCellNr;

	void ReadValue(void);

	bool IsDataAvailable(void);


	void Write(uint8_t* txData, uint8_t size);
	void WriteRead(uint8_t* txData, uint8_t* rxData, uint8_t txSize, uint8_t rxSize);



};

#endif /* SRC_LOADCELL_LOADCELL_H_ */
