/*
 * Log.h
 *
 *  Created on: Oct 31, 2020
 *      Author: marcel
 */

#ifndef SRC_LOG_LOG_H_
#define SRC_LOG_LOG_H_

#include "main.h"
#include "i2c.h"
#include "../Model/Model.h"
#include "../Model/Tools.h"



class Log {


public:
	Log(Model *model);

	void init();

	uint8_t* getLogBookEntry(uint32_t addr);
	void addEntriy();
	void resetAddrPointer();

private:
	uint32_t nrOfEntries;
	uint32_t addrPointer;

	Model *model;

	static const uint8_t EEPROM_ADDR = 0x54;
};

#endif /* SRC_LOG_LOG_H_ */
