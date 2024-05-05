#include "caddress.h"
#include <iostream>
#include <string>

// Default Constructor
Caddress::Caddress(){
	Caddress::add1;
	Caddress::add2;
	Caddress::city;
	Caddress::state;
	Caddress::zip;
}// end constructor

Caddress::~Caddress(){
}// end destructor


// Setters
void Caddress::setAdd1(std::string add1){
	Caddress::add1 = add1;
}

void Caddress::setAdd2(std::string add2){
	Caddress::add2 = add2;
}

void Caddress::setCity(std::string city){
	Caddress::city = city;
}

void Caddress::setState(std::string state){
	Caddress::state = state;
}

void Caddress::setZip(std::string zip){
	Caddress::zip = zip;
}


// Getters
std::string Caddress::getAdd1(){
	return Caddress::add1;
}
std::string Caddress::getAdd2(){
	return Caddress::add2;
}
std::string Caddress::getCity(){
	return Caddress::city;
}
std::string Caddress::getState(){
	return Caddress::state;
}
std::string Caddress::getZip(){
	return Caddress::zip;
}

std::string Caddress::getWholeAddress(){
	return add1 + "," + add2 + "," + city + "," + state + "," + zip;
}
