/*
 * LoadCell.h
 *
 *  Created on: 11.10.2020
 *      Author: marcel
 */

#ifndef SRC_LOADCELL_LOADCELL_H_
#define SRC_LOADCELL_LOADCELL_H_


#include "../Model/Model.h"
#include "main.h"
#include "LoadCellConfig.h"


class LoadCell {


public:
	LoadCell() ;
	void Update(void);
	void InitLoadCell(Model *model,LoadCellSettings loadCellSettings);


private:
	Model *model;
	LoadCellSettings lcSettings;

	void DWT_Init(void);
	void DWT_Delay_us(volatile uint32_t microseconds);
};

#endif /* SRC_LOADCELL_LOADCELL_H_ */
