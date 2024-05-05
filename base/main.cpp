#include <iostream>
#include <string>
#include "cstudent.h"
#include <fstream>
#include <sstream>
#include <algorithm>

std::string sortedName[50]; // making an array of full names to be sorted
int main(){
	std::ifstream fFile; // fFile to read the data from students.dat for fullReport.txt
	std::ifstream iFile; // iFile to read the data from students.dat for shortReport.txt
	std::ofstream oFile; // oFile to write the data to fullReport.txt
	std::ofstream sFile; // sFile to write the data to shortReport.txt
	std::ofstream alphaFile; // alphaFile to write the data to alphaReport.txt
	std::stringstream ss;
	std::string line;
	Cstudent *array = new Cstudent[50]; // Creating an array of cstudent instances on the heap
	std::string firstName, lastName, fullName;

	//openin the files
	fFile.open("students.dat");
	oFile.open("fullReport.txt");
	sFile.open("shortReport.txt");
	alphaFile.open("alphaReport.txt");

	// fullReport.txt
	for(int i = 0; i < 50; i++){
		getline(fFile,line);
		ss.clear();
		ss.str(line);
		array[i].setInput(line); // Feeding the line to the entire line setter of Cstudent class
		oFile<<array[i].getReport();
		oFile<<"\n";
	}

	// shortReport.txt
	iFile.open("students.dat");
	for(int i = 0; i < 50; i++){
		std::string names;
		getline(iFile, names);
		ss.clear();
		ss.str(names);
		getline(ss, lastName, ',');
		getline(ss, firstName, ',');
		
		array[i].setLname(lastName);
		array[i].setFname(firstName);

		sFile<<array[i].getLname()<<" "<<array[i].getFname();
		sFile<<"\n";

		
		sortedName[i] = lastName + " " + firstName; // Appending the full name of each student to the sortedName array
	}

	// using std::sort from algorithm library to sort the full names alphabetically in ascending order (A - Z)
	std::sort(sortedName , sortedName + 50);	

	for(int i = 0; i < 50; i++){
		alphaFile<<sortedName[i];
		alphaFile<<"\n";
	}
	
	delete[] array;
	fFile.close();
	oFile.close();
	sFile.close();
	iFile.close();
	alphaFile.close();
	return 0;
}// end main

