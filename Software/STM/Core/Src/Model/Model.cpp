/*
 * Model.cpp
 *
 *  Created on: 11.10.2020
 *      Author: marcel
 */

#include "Model.h"

Model::Model() {
	//---------------LoadCell Settings---------------
	 loadCell1 = 0;
	 loadCell2 = 0;

	 loadCellOffset_1 = 970;
	 loadCellOffset_2 = 970;

	 loadCellGradient_1 = 3.35;
	 loadCellGradient_2 = 3.35;

	 weight = 0;

	//---------------Wachs settings---------------

	 Bienenwachs_Preis = 400; //Preis in Rr/100g
	 Parafinwachs_Preis = 350;	//Preis in Rr/100g


	 wachstyp = E_UNDEF;

	//---------------Screen activation---------------


	//---------------Zeit speicherung---------------
	 year = 00;
	 month = 01;
	 day = 01;
	 dayOfWeek = 0;
	 hour = 0;
	 minute = 0;
	 seconds = 0;

	//---------------Taster Status---------------
	 T1Short = false;
	 T1Long = false;

	 T2Short = false;
	 T2Long = false;

	 T3Short = false;
	 T3Long = false;

	 T4Short = false;
	 T4Long = false;

	 T5Short = false;
	 T5Long = false;

}

uint8_t Model::getDay() const {
	return day;
}

void Model::setDay(uint8_t day) {
	this->day = day;
}

uint8_t Model::getDayOfWeek() const {
	return dayOfWeek;
}

void Model::setDayOfWeek(uint8_t dayOfWeek) {
	this->dayOfWeek = dayOfWeek;
}

uint8_t Model::getHour() const {
	return hour;
}

void Model::setHour(uint8_t hour) {
	this->hour = hour;
}

int32_t Model::getLoadCell1() const {
	return loadCell1;
}

void Model::setLoadCell1(int32_t loadCell1) {
	this->loadCell1 = loadCell1;
}

int32_t Model::getLoadCell2() const {
	return loadCell2;
}

void Model::setLoadCell2(int32_t loadCell2) {
	this->loadCell2 = loadCell2;
}

uint8_t Model::getMinute() const {
	return minute;
}

void Model::setMinute(uint8_t minute) {
	this->minute = minute;
}

uint8_t Model::getMonth() const {
	return month;
}

void Model::setMonth(uint8_t month) {
	this->month = month;
}

uint8_t Model::getSeconds() const {
	return seconds;
}

void Model::setSeconds(uint8_t seconds) {
	this->seconds = seconds;
}

int16_t Model::getWeight() const {
	return weight;
}

void Model::setWeight(int16_t weight) {
	this->weight = weight;
}

uint8_t Model::getYear() const {
	return year;
}

void Model::setYear(uint8_t year) {
	this->year = year;
}

bool Model::isT1Long() const {
	return T1Long;
}

void Model::setT1Long(bool t1Long) {
	T1Long = t1Long;
}

bool Model::isT1Short() const {
	return T1Short;
}

void Model::setT1Short(bool t1Short) {
	T1Short = t1Short;
}

bool Model::isT2Long() const {
	return T2Long;
}

void Model::setT2Long(bool t2Long) {
	T2Long = t2Long;
}

bool Model::isT2Short() const {
	return T2Short;
}

void Model::setT2Short(bool t2Short) {
	T2Short = t2Short;
}

bool Model::isT3Long() const {
	return T3Long;
}

void Model::setT3Long(bool t3Long) {
	T3Long = t3Long;
}

bool Model::isT3Short() const {
	return T3Short;
}

void Model::setT3Short(bool t3Short) {
	T3Short = t3Short;
}

bool Model::isT4Long() const {
	return T4Long;
}

void Model::setT4Long(bool t4Long) {
	T4Long = t4Long;
}

bool Model::isT4Short() const {
	return T4Short;
}

void Model::setT4Short(bool t4Short) {
	T4Short = t4Short;
}

bool Model::isT5Long() const {
	return T5Long;
}

void Model::setT5Long(bool t5Long) {
	T5Long = t5Long;
}

bool Model::isT5Short() const {
	return T5Short;
}

void Model::setT5Short(bool t5Short) {
	T5Short = t5Short;
}

float Model::getLoadCellGradient1() const {
	if(loadCellGradient_1 <= 0){
		return 1;
	}
	return loadCellGradient_1;
}

void Model::setLoadCellGradient1(float loadCellGradient1) {
	loadCellGradient_1 = loadCellGradient1;
}

float Model::getLoadCellGradient2() const {
	if(loadCellGradient_2 <= 0){
		return 1;
	}
	return loadCellGradient_2;
}

void Model::setLoadCellGradient2(float loadCellGradient2) {
	loadCellGradient_2 = loadCellGradient2;
}

int32_t Model::getLoadCellOffset1() const {
	return loadCellOffset_1;
}

void Model::setLoadCellOffset1(int32_t loadCellOffset1) {
	loadCellOffset_1 = loadCellOffset1;
}

int32_t Model::getLoadCellOffset2() const {
	return loadCellOffset_2;
}

float Model::getBienenwachsPreis() const {
	return Bienenwachs_Preis;
}

void Model::setBienenwachsPreis(float bienenwachsPreis) {
	Bienenwachs_Preis = bienenwachsPreis;
}

float Model::getParafinwachsPreis() const {
	return Parafinwachs_Preis;
}

void Model::setParafinwachsPreis(float parafinwachsPreis) {
	Parafinwachs_Preis = parafinwachsPreis;
}

Model::EWACHS Model::getWachstyp() const {
	return wachstyp;
}

void Model::setWachstyp(EWACHS wachstyp) {
	this->wachstyp = wachstyp;
	switch(this->wachstyp){
	case E_UNDEF:
		HAL_GPIO_WritePin(LED_BW_GPIO_Port, LED_BW_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_PW_GPIO_Port, LED_PW_Pin, GPIO_PIN_SET);
		break;
	case E_BIENENWACHS:
		HAL_GPIO_WritePin(LED_BW_GPIO_Port, LED_BW_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_PW_GPIO_Port, LED_PW_Pin, GPIO_PIN_SET);
		break;
	case E_PARAFINWACHS:
		HAL_GPIO_WritePin(LED_BW_GPIO_Port, LED_BW_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_PW_GPIO_Port, LED_PW_Pin, GPIO_PIN_RESET);
		break;
	}

}

void Model::setLoadCellOffset2(int32_t loadCellOffset2) {
	loadCellOffset_2 = loadCellOffset2;
}
