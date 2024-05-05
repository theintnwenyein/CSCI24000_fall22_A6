#ifndef CDATE_H_EXISTS
#define CDATE_H_EXISTS
#include <string>

class Cdate{
	private:
		std::string date;
		std::string month;
		std::string year;
	public:
		Cdate(); // Default constructor
		~Cdate(); // Destructor
		

		// Setters
		void setDate(std::string date);
		void setMonth(std::string month);
		void setYear(std::string year);

		// Getters
		std::string getDate();
		std::string getMonth();
		std::string getYear();
		std::string getWholeDate();
};
#endif
