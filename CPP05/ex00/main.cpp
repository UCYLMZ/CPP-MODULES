#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "\n-----------------------\n" << std::endl;

	Bureaucrat b1("utku", 1);
	std::cout << b1;
	try {
		b1.gradeIncrement();
	}
	catch(std::exception & exception)
	{
		std::cout << exception.what() << std::endl;
	}

	std::cout << "\n-----------------------\n" << std::endl;

	Bureaucrat b2("can");
	std::cout << b2;
	try {
		b2.gradeDecrement();
	}
	catch(std::exception & exception)
	{
		std::cout << exception.what() << std::endl;
	}

	std::cout << "\n-----------------------\n" << std::endl;

	try {
		Bureaucrat b3(151);
	}
	catch(std::exception & exception)
	{
		std::cout << exception.what() << std::endl;
	}

	std::cout << "\n-----------------------\n" << std::endl;

	try {
		Bureaucrat b3(0);
	}
	catch(std::exception & exception)
	{
		std::cout << exception.what() << std::endl;
	}
	
	std::cout << "\n-----------------------\n" << std::endl;
}