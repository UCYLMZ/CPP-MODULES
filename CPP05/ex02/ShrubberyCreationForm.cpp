#include "ShrubberyCreationForm.hpp"


// Constructors, Destructor and Assignment Operator Overload functions
ShrubberyCreationForm::ShrubberyCreationForm(void) : target(""), AForm("shrubbery", 145, 137)
{ std::cout << "ShrubberyCreationForm Default Constructor called!" << std::endl; }

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : target(target)
, AForm("shrubbery", 145, 137)
{ std::cout << "ShrubberyCreationForm Target Constructor called!" << std::endl;}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & elem) : target(elem.target)
, AForm("shrubbery", 145, 137)
{ std::cout << "ShrubberyCreationForm Copy Constructor called!" << std::endl;}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{ std::cout << "ShrubberyCreationForm Destructor called!" << std::endl; }

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & elem)
{
	this->target = elem.target;
	return (*this);
}