/*
 * Model.cpp
 *
 *  Created on: 11.10.2020
 *      Author: marcel
 */

#include "Model.h"

Model::Model() {
	// TODO Auto-generated constructor stub

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
