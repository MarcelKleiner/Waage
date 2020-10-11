/*
 * TimerConfig.h
 *
 *  Created on: 11.10.2020
 *      Author: marcel
 */

#ifndef SRC_TIME_TIMERCONFIG_H_
#define SRC_TIME_TIMERCONFIG_H_


//-----------Address settings-----------
#define CONTROL_STATUS_1		0x00
#define CONTROL_STATUS_2		0x01
#define SECONDS					0x02
#define MINUTES					0x03
#define HOURS					0x04
#define DAYS					0x05
#define WEEK_DAYS				0x06
#define MONTHS					0x07
#define YEARS					0x08
#define MINUTE_ALARM			0x09
#define HOUR_ALARM				0x0A
#define DAY_ALARM				0x0B
#define WEEKDAY_ALARM			0x0C
#define CLOCKOUT_CONTROL		0x0D
#define TIMER_CONTROL			0x0E
#define TIMER					0x0F

#define WRITE_ADDR				0xA2
#define READ_ADDR				0xA3

#define I2C_TIMEOUT				100

#endif /* SRC_TIME_TIMERCONFIG_H_ */
