#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "\n-----------------------\n" << std::endl;

	Bureaucrat b1("Utku", 1);
	std::cout << b1;
	Form f1("form1", 1, 1);
	std::cout << f1 << std::endl;

	b1.signForm(f1);
	std::cout << f1 << std::endl;

	std::cout << "\n-----------------------\n" << std::endl;

	Bureaucrat b2("Can", 49);
	std::cout << b2;
	Form f2("form2", 48, 48);
	std::cout << f2 << std::endl;

	b2.signForm(f2);
	std::cout << f2 << std::endl;

	std::cout << "\n-----------------------\n" << std::endl;
}