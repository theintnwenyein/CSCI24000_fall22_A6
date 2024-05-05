#ifndef CDATE_H_EXISTS
#define DATE_H_EXISTS
#include <string>

class Cdate{
	private:
		int date;
		int month;
		int year;
	public:
		Cdate();
		~Cdate();

		// Setters
		void setDate(int date);
		void setMonth(int month);
		void setYear(int year);

		// Getters
		int getDate();
		int getMonth();
		int getYear();
};
#endif
