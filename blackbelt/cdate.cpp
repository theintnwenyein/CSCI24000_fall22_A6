#include <iostream>
#include <string>
#include "cdate.h"

Cdate::Cdate(){
	Cdate::date;
	Cdate::month;
	Cdate::year;
}

Cdate::~Cdate(){
}

// Setters

void Cdate::setDate(int date){
	Cdate::date = date;
}

void Cdate::setMonth(int month){
	Cdate::month = month;
}

void Cdate::setYear(int year){
	Cdate::year = year;
}

// Getters

int Cdate::getDate(){
	return Cdate::date;
}

int Cdate::getMonth(){
	return Cdate::month;
}

int Cdate::getYear(){
	return Cdate::year;
}
