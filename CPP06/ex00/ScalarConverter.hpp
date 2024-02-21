#pragma once

# include <iostream>

class ScalarConverter
{
	public:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const & elem);
		~ScalarConverter(void);
		
		ScalarConverter& operator=(ScalarConverter const & elem);
		
		static void convert(std::string str);
		static char getType(std::string str);
		static void convertChar(char c);
		static void convertInt(std::string str);
		static void convertFloat(std::string str);
		static void convertDouble(std::string str);
		static void convertNan(void);
		static void convertInf(std::string str);
};
