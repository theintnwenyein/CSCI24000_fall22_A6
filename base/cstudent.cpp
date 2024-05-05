#include <iostream>
#include <string>
#include "cstudent.h"
#include <fstream>
#include <sstream>

std::ifstream fFile;
std::stringstream ss;
std::string line;
std::string firstName, lastName, addressLine1, addressLine2, city, state, zip, birthdate, bmonth, byear, graduationdate, gmonth, gyear, gpa, credit;

// Default Constructor
Cstudent::Cstudent(){
	Cstudent::fname;
	Cstudent::lname;
	Cstudent::address = new Caddress(); // created on the heap
	Cstudent::bdate = new Cdate(); // created on the heap
	Cstudent::gdate = new Cdate(); // created on the heap
	Cstudent::gpa;
	Cstudent::credit;
}

// Destructor to deallocate 
Cstudent::~Cstudent(){
	delete address;
	delete bdate;
	delete gdate;
}


// Setters
void Cstudent::setFname(std::string fname){
	Cstudent::fname = fname;
}

void Cstudent::setLname(std::string lname){
	Cstudent::lname = lname;
}

void Cstudent::setAddress(Caddress* address){
	Cstudent::address = address;
}

void Cstudent::setBdate(Cdate* bdate){
	Cstudent::bdate = bdate;
}

void Cstudent::setGdate(Cdate* gdate){
	Cstudent::gdate = gdate;
}

void Cstudent::setGpa(std::string gpa){
	Cstudent::gpa = gpa;
}

void Cstudent::setCredit(std::string credit){
	Cstudent::credit = credit;
}


// Getters
std::string Cstudent::getFname(){
	return Cstudent::fname;
}

std::string Cstudent::getLname(){
	return Cstudent::lname;
}

Caddress Cstudent::getAddress(){
	return *Cstudent::address;
}

Cdate Cstudent::getBdate(){
	return *Cstudent::bdate;
}

Cdate Cstudent::getGdate(){
	return *Cstudent::gdate;
}

std::string Cstudent::getGpa(){
	return Cstudent::gpa;
}

std::string Cstudent::getCredit(){
	return Cstudent::credit;
}


// An entire line setter
void Cstudent::setInput(std::string line){
	Cstudent::line = line;
	fFile.open("students.dat");
	getline(fFile, line);
	ss.clear();
	ss.str(line);

	getline(ss, lastName, ',');
	getline(ss, firstName, ',');
	getline(ss, addressLine1, ',');
	getline(ss, addressLine2, ',');
	getline(ss, city, ',');
	getline(ss, state, ',');
	getline(ss, zip, ',');
	getline(ss, bmonth, '/');
	getline(ss, birthdate, '/');
	getline(ss, byear, ',');
	getline(ss, gmonth, '/');
	getline(ss, graduationdate, '/');
	getline(ss, gyear, ',');
	getline(ss, gpa, ',');
	getline(ss, credit, ',');
	
	Cstudent::setLname(lastName);
	Cstudent::setFname(firstName);
	Cstudent::address->setAdd1(addressLine1);
	Cstudent::address->setAdd2(addressLine2);
	Cstudent::address->setCity(city);
	Cstudent::address->setState(state);
	Cstudent::address->setZip(zip);
	Cstudent::bdate->setDate(birthdate);
	Cstudent::bdate->setMonth(bmonth);
	Cstudent::bdate->setYear(byear);
	Cstudent::gdate->setDate(graduationdate);
	Cstudent::gdate->setMonth(gmonth);
	Cstudent::gdate->setYear(gyear);
	Cstudent::setGpa(gpa);
	Cstudent::setCredit(credit);

}

// An entire line getter
std::string Cstudent::getReport(){

	return getLname() + "," + getFname() + "," + address->getWholeAddress() + "," + bdate->getWholeDate() + "," + gdate->getWholeDate() + getGpa()+ "," + getCredit();
	
}


