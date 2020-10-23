/*
 * Model.h
 *
 *  Created on: 11.10.2020
 *      Author: marcel
 */

#ifndef SRC_MODEL_MODEL_H_
#define SRC_MODEL_MODEL_H_

#include "../LCD/LCD.h"
#include "stm32l412xx.h"
#include "main.h"

class Model {

public:
	enum ESCREEN{
		E_BW_SETTINGS,
		E_PW_SETTINGS,
		E_LOG_BOOK,
		E_MAIN_SCRREN,
		E_TIME,
		E_TIME_SETTINGS,
		E_DATE_SETTINGS,
		E_KONTRAST_SETTINGS,
	};

	enum EWACHS{
		E_UNDEF,
		E_BIENENWACHS,
		E_PARAFINWACHS,
	};


private:


	//---------------LoadCell Settings---------------
	int32_t loadCell1;
	int32_t loadCell2;

	int32_t loadCellOffset_1;
	int32_t loadCellOffset_2;

	float loadCellGradient_1;
	float loadCellGradient_2;

	int16_t weight;

	//---------------Wachs settings---------------

	int Bienenwachs_Preis; //Preis in Fr/10g
	int Parafinwachs_Preis;	//Preis in Fr/10g

	EWACHS wachstyp;

	//---------------Screen activation---------------

	//---------------Kontrast ---------------
	uint8_t kontrast;

	//---------------Zeit speicherung---------------
	uint8_t year;
	uint8_t month;
	uint8_t day;
	uint8_t dayOfWeek;
	uint8_t hour;
	uint8_t minute;
	uint8_t seconds;


	//---------------Taster Status---------------
	bool T1Short;
	bool T1Long;

	bool T2Short;
	bool T2Long;

	bool T3Short;
	bool T3Long;
	
	bool T4Short;
	bool T4Long;
	
	bool T5Short;
	bool T5Long;

public:
	Model();
	uint8_t getDay() const;
	void setDay(uint8_t day);

	uint8_t getDayOfWeek() const;
	void setDayOfWeek(uint8_t dayOfWeek);

	uint8_t getHour() const;
	void setHour(uint8_t hour);

	uint8_t getMinute() const;
	void setMinute(uint8_t minute);

	uint8_t getMonth() const;
	void setMonth(uint8_t month);

	uint8_t getSeconds() const;
	void setSeconds(uint8_t seconds);

	int16_t getWeight() const;
	void setWeight(int16_t weight);

	uint8_t getYear() const;
	void setYear(uint8_t year);


	int32_t getLoadCell1() const;
	void setLoadCell1(int32_t loadCell1);

	int32_t getLoadCell2() const;
	void setLoadCell2(int32_t loadCell2);


	bool isT1Long() const;
	void setT1Long(bool t1Long);
	bool isT1Short() const;
	void setT1Short(bool t1Short);
	bool isT2Long() const;
	void setT2Long(bool t2Long);
	bool isT2Short() const;
	void setT2Short(bool t2Short);
	bool isT3Long() const;
	void setT3Long(bool t3Long);
	bool isT3Short() const;
	void setT3Short(bool t3Short);
	bool isT4Long() const;
	void setT4Long(bool t4Long);
	bool isT4Short() const;
	void setT4Short(bool t4Short);
	bool isT5Long() const;
	void setT5Long(bool t5Long);
	bool isT5Short() const;
	void setT5Short(bool t5Short);

	float getLoadCellGradient1() const;
	void setLoadCellGradient1(float loadCellGradient1);
	float getLoadCellGradient2() const;
	void setLoadCellGradient2(float loadCellGradient2);
	int32_t getLoadCellOffset1() const;
	void setLoadCellOffset1(int32_t loadCellOffset1);
	int32_t getLoadCellOffset2() const;
	void setLoadCellOffset2(int32_t loadCellOffset2);
	float getBienenwachsPreis() const;
	void setBienenwachsPreis(float bienenwachsPreis);
	float getParafinwachsPreis() const;
	void setParafinwachsPreis(float parafinwachsPreis);
	EWACHS getWachstyp() const;
	void setWachstyp(EWACHS wachstyp);
	uint8_t getKontrast() const;
	void setKontrast(uint8_t kontrast);
};

#endif /* SRC_MODEL_MODEL_H_ */
