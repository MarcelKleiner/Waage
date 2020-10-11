/*
 * LCDBase.h
 *
 *  Created on: Oct 10, 2020
 *      Author: marcel
 */

#ifndef SRC_LCD_LCDBASE_H_
#define SRC_LCD_LCDBASE_H_

#include "LCD.h"

namespace lcd {

class LCDBase {


protected:
	LCDBase(void);
	void Draw(char line1[], char line2[]);

private:
	LCD clcd = LCD();

};

} /* namespace lcd */

#endif /* SRC_LCD_LCDBASE_H_ */
