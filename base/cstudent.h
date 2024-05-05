#ifndef CSTUDENT_H_EXISTS
#define CSTUDENT_H_EXISTS
#include <string>
#include "caddress.h"
#include "cdate.h"

class Cstudent{
	private:
		std::string fname;
		std::string lname;
		Caddress* address; // address is an instance of Caddress class, and is stored on heap thus need to be deallocated at the end
		Cdate* bdate; // bdate is an instance of Cdate class, and is stored on heap thus need to be deallocated at the end
		Cdate* gdate; // gdate is an instance of Cdate class, and is stored on heap thus need to be deallocated at the end
		std::string gpa;
		std::string credit;
		std::string line;
	public:
		Cstudent();
		~Cstudent(); // Destructor to deallocate address, bdate, and gdate
		

		// Setters
		void setFname(std::string fname);
		void setLname(std::string lname);
		void setAddress(Caddress*);
		void setBdate(Cdate*);
		void setGdate(Cdate*);
		void setGpa(std::string gpa);
		void setCredit(std::string credit);
		void setInput(std::string); // an entire line setter which will take each line from students.dat
		
		// Getters
		std::string getReport(); // an entrie line getter which will return a string
		std::string getFname();
		std::string getLname();
		Caddress getAddress();
		Cdate getBdate();
		Cdate getGdate();
		std::string getGpa();
		std::string getCredit();
		
};
#endif
