#include <iostream>
#include <string>
#include "cdate.h"

// Default constructor
Cdate::Cdate(){
	Cdate::date;
	Cdate::month;
	Cdate::year;
}

Cdate::~Cdate(){
}


// Setters
void Cdate::setDate(std::string date){
	Cdate::date = date;
}

void Cdate::setMonth(std::string month){
	Cdate::month = month;
}

void Cdate::setYear(std::string year){
	Cdate::year = year;
}


// Getters
std::string Cdate::getDate(){
	return Cdate::date;
}
std:: string Cdate::getMonth(){
	return Cdate::month;
}
std::string Cdate::getYear(){
	return Cdate::year;
}

std::string Cdate::getWholeDate(){
	return month + "/" + date + "/" + year;
}
