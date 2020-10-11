/*
 * IScreen.h
 *
 *  Created on: Oct 10, 2020
 *      Author: marcel
 */

#ifndef SRC_LCD_ISCREEN_H_
#define SRC_LCD_ISCREEN_H_



class IScreen {

	virtual bool IsActive() = 0;
	virtual void SetActive(void) = 0;
	virtual void Update(void) = 0;

};


#endif /* SRC_LCD_ISCREEN_H_ */
