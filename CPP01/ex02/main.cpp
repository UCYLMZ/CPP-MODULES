#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";

	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << std::endl << "Address of str        : " << &str << std::endl;
	std::cout << "Address in stringPTR  : " << stringPTR << std::endl;
	std::cout << "Address in stringREF  : " << &stringREF << std::endl;

	std::cout << std::endl << "Value of str               : " << str << std::endl;
	std::cout << "Value pointed by stringPTR : " << *stringPTR << std::endl;
	std::cout << "Value pointed by stringREF : " << stringREF << std::endl << std::endl;
}