# pragma once

#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <list>

class BitcoinExchange
{
	private:
		std::map<std::string, float> bitcoinMap;
		std::list<std::string> dates;

	public:
		// Constructors, Destructor and Assignment Operator Overload
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange & src);
		~BitcoinExchange(void);

		// Member Functions
		void readDataBase(std::string fileName);
		static bool checkDate(std::string date, std::string filename);
		static bool checkRate(std::string rate, std::string filename);
		static bool checkDay(int year, int month, int day);
		static std::string removeSpaces(std::string str);

		// Getters
		std::map<std::string, float> getMap(void);
		std::list<std::string> getDates(void);

		// Operator Overloads
		BitcoinExchange & operator=(BitcoinExchange const & src);

		// Exception Classes
		class FileOpenException : public std::exception {
			public:
				virtual const char* what () const throw();
		};
};