#ifndef CADDRESS_H_EXISTS
#define CADDRESS_J_EXISTS
#include <string>

class Caddress{
	private:
		std::string add1;
		std::string add2;
		std::string city;
		std::string state;
		std::string zip;
	public:
		Caddress(); // default constructor
		~Caddress(); // destructor 

		// Setters
		void setAdd1(std::string add1);
		void setAdd2(std::string add2);
		void setCity(std::string city);
		void setState(std::string state);
		void setZip(std::string zip);

		// Getters
		std::string getAdd1();
		std::string getAdd2();
		std::string getCity();
		std::string getState();
		std::string getZip();

		std::string getWholeAddress();
};
#endif

	
