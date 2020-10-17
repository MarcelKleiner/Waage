/*
 * IScreen.h
 *
 *  Created on: Oct 10, 2020
 *      Author: marcel
 */

#ifndef SRC_LCD_ISCREEN_H_
#define SRC_LCD_ISCREEN_H_



class BaseScreen {

private:
	bool alive;
	
public:
	BaseScreen(void);

	bool isActive() const;
	void setActive(bool alive);
};


#endif /* SRC_LCD_ISCREEN_H_ */
