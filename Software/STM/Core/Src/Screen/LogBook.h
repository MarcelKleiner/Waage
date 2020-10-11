/*
 * LogBook.h
 *
 *  Created on: 11.10.2020
 *      Author: marcel
 */

#ifndef SRC_SCREEN_LOGBOOK_H_
#define SRC_SCREEN_LOGBOOK_H_

#include "BaseScreen.h"
#include "../Model/Model.h"

class LogBook : BaseScreen {


public:
	LogBook(Model *model);

private:
	Model *model;

};

#endif /* SRC_SCREEN_LOGBOOK_H_ */
