#include <iostream>
#include "cdate.h"
#include <sstream>
#include <fstream>
#include <string>

// Declearing necessary variables
int currentDate, currentMonth, currentYear;
int adate, amonth, ayear;
std::string line, lastName, firstName, addressLine1, addressLine2, city, state, zip, birthDate, birthMonth, birthYear;
int bdate, bmonth, byear;


// Functions to get the current date and month from the user
void date(){
	std::cout<<"Enter today's date: ";
	std::cin>>currentDate;
	std::cin.ignore();
}

void month(){
	std::cout<<"Enter the current month: ";
	std::cin>>currentMonth;
	std::cin.ignore();
}


// Main function
int main(){
	currentYear = 2022;
	std::ifstream readFile;
	std::ofstream writeFile;
	std::stringstream ss;
	Cdate* c = new Cdate(); // Creating an object of Cdate class on the heap
	

	// Checking the validity of the user input of date and month
	date();	
	while(currentDate <= 0 or currentDate > 31){
		date();
	}
	
	month();
	while(currentMonth <= 0 or currentMonth > 12){
		month();
	}
	
	// Creating an array to store the number of days in each month
	int daysOfMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	

	readFile.open("students.dat");
	writeFile.open("age.txt");
	while(getline(readFile,line)){
		ss.clear();
		ss.str(line);
		getline(ss, lastName, ',');
		getline(ss, firstName, ',');
		getline(ss, addressLine1, ',');
		getline(ss, addressLine2, ',');
		getline(ss, city, ',');
		getline(ss, state, ',');
		getline(ss, zip, ',');
		getline(ss, birthMonth, '/');
		getline(ss, birthDate, '/');
		getline(ss, birthYear, ',');

		// Converting from strings to integers
		bmonth = atoi(birthMonth.c_str());
		bdate = atoi(birthDate.c_str());
		byear = atoi(birthYear.c_str());


		c->setMonth(bmonth);
		c->setDate(bdate);
		c->setYear(byear);

		bmonth = c->getMonth();
		bdate = c->getDate();
		byear = c->getYear();
		
		// Changing the number of days in February if it is a leap year
		if(byear % 4 == 0){
			daysOfMonth[1] = 29;
		}

		// Calculating the age(year)
		ayear = currentYear - byear;
		

		// Calculating the age(month)
		if(bmonth > currentMonth){
			ayear--;
			amonth = 12 - (bmonth - currentMonth);
		}
		else{
			amonth = currentMonth - bmonth;
		}
		
		
		// Calculating the age(days)
		if(bdate > currentDate){
	// Preventing of printing negative numbers for month when the current month and birth month are the same, and the birth date is bigger than the current date
			if(amonth == 0){
				amonth = currentMonth - 1;
			}

			adate = daysOfMonth[currentMonth-1] - (bdate - currentDate);
		}// end if

		else{
			adate = currentDate - bdate;
		}

		writeFile<<lastName<<" "<<firstName<<" is "<<ayear<< " years, "<<amonth<<" months and "<<adate<<" days old.";
		writeFile<<"\n";
		
	}// end while
	
	readFile.close();
	writeFile.close();
	delete (c);
	return 0;
} // end main
