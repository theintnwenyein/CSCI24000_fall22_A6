NOTE: The optional alphaReport.txt is included in the base folder as mentioned by the TA

Goal: To retrieve the personal information of 50 university studetns from a text file using classes and objects, and printing the output in separate files

Input: Text file with the information of 50 students, students.dat

Output: Full report of student information - fullReport.txt, short report consisting only frist and last name of the student - shortReport.txt

Steps: 
- Create a class for address (header file and cpp file)
- Create a class for date (hader file and cpp file)
- Create a student class with one instance of address and two instances of date (header file and cpp file)
- Create a main.cpp file to modify and test the whole program
- Create a makefile to link all the .o files



Creating the address class - Caddress

Goal: To create setter and getter for addressLine1, addressLine2, city, state, and zipcode and return the whole address
Input: addressLine1, addressLine2, city, state, and zipcode(all will be treated as strings since no calculation will be involved) will be given from students.dat
Output: Return the whole address by combining the five attributes
Steps:
- Initialize the private attributes first
- Create the necessary methods in addition to the default constructor and destructor
	- Create setters and getters for the five private attributes (refer to the UML)
	- Create a getter for returning the whole address



Creating the date class - Cdate

Goal: To create setter and getter for date, month, and year, and return the whole date
Input: Date, month, and year for birth and for graduation will be given in students.dat, and all will be treated as strings
Output: Return the whole birthday and graduation date by combining the date, month, and year
Steps:
- Initialize the private attributes first (which are date, month, and year)
- Create the necessary methods in addition to the default constructor and destructor
	- Create setters and getters for each attribute
	- Create a getter to return the whole date



Creating the student class - Cstudent

Goal: To create setter and getter for lastName, firstName, address, birthDate, graduationDate, gpa, and credit, and return the full information of each student
Input: All the required information will be given in students.date, and will be treated as strings, the header files of caddress and cdate will be included
Output: Return the full information of each student
Steps:
- Initialize the private attributes first (address will be an instance of Caddress class, birthDate and graduationDate will be two instnaces of Cdate class)
- Create the necessary methods in addition to the default constructor and destructor
	- Create setters and getters for each attribute (refer to UML)
	- Here, the destructor will delete the address, birthDate, and graduationDate as they are on the heap
	- Create a setter to set the entire line (all the information) 
		- Import necessary libraries to read the students.dat file, and get each line
		- Uisng stringstream, create variables to store the value of each information (lastName, firstName,....,gpa,credit)
		- Feed those variables to the setters of Cstudent class (For address and dates, use the instances created to get each piece of information)
	- Create an entire line getter to return the whole line by using the getters of Cstudent class


Creating the main.pp

Goal: To modify the whole program by writing the full output to fullReport.txt and the short output of names to shortReport.txt
Input: students.dat file, and the header file of cstudent class
Output: The full output written to fullReport.txt, and the short output of names written to shortReport.txt
Steps:
- Import all the necessary libraries to read and write the files
- Create an array of cstudent instances on the heap
- For the fullReport.txt, create a for loop to continue looping for 50 times
	- Read each line of students.dat and store the line in a variable(supposed it's called line)
	- Feed that variable, line, to the entire line setter of Cstudent class (this will break down the pieces of information, and process them)
	- Use the entire line getter of Cstudent class to write the student information into fullReport.txt
- For the shortReport.txt, create a for loop to continue looping for 50 times
	- Read each line of students.dat and store the line in a variable
	- By using stringstream, get only the lastName, and firstName of students.dat
	- Feed lastName to the lastName setter of Cstudent class, and feed the firstName to the firstName setter of Cstudent class
	- By using the lastName getter and firstName getter of Cstudent class, write them into shortReport.txt
- For the alphaReport.txt, create an arry of size 50 first to hold the full names of each student
	- Use the for loop in shortReport.txt to append the full name of each student to the array created
	- Use the standard sort function by including the <algorithm> library
	- Use a for loop for to print the the sorted names
- Delete the array of cstudent instances, and close the files back


Creating the makefile

- We will have an executable file named "test" whose dependencies are main.o, caddress.o, cdate.o, and cstudent.o
- For main.o, its dependencies will be main.cpp, fullReport.txt, shortReport.txt, and cstudent.h, caddress.h, and cdate.h
- For caddress.o, its dependency will be caddress.cpp
- For cdate.o, its dependency will be cdate.cpp
- For cstudent.o, its dependencies will be cstudent.cpp, caddress.h, and cdate.h
- For clean command, remove all .o files and "test"
- For run command, use ./test
- For valgrind memory leak check, use valgrind --leak-check=full ./test (as in Andy's example)



