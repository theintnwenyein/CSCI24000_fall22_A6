NOTE: After inputting the current date and month, go and check age.txt to see the result

Goal: To calculate the age of each student from students.dat and print them out with their names

Input: Students' information from students.dat

Output: The calculated age in the form of "-- years, -- months, and -- days old."

Steps: Create a date class first just like in the base assignment, but just take the attributes in integers type, in addition to the setters and getters

- In the main.cpp
	- Ask the current date, and the current month from the user
	- Make an array for the number of days in a month
	- Restrict the current date so that it is not zero and it is not bigger than 31
	- Restrict the current month so that it is not zero and it is not bigger than 12
	- After that, read students.dat and get each student's birthday information using the date class
	- Convert them into integer types
	- To calculate the student's age: subtract the birth year from 2022
	- To calculate the student's age in months: 
		- If the birth month is bigger than the current month, subtract one from the result (age in years), 
			before calculating the age
		- If not, calculate the month by subtracting the birthmonth from the current month
	- To calculate the student's age in days:
		- If the birth date is bigger than the current date, subtract one from the age in months
			before calculating the days
		- If not, calculate the age in days by subtracting the birth date from current date
	- Write the output to another file named age.txt
