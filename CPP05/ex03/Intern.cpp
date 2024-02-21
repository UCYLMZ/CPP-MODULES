#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentalPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


// Constructors, Destructor and Assignment Operator Overload functions
Intern::Intern(void) { std::cout << "Intern Default Constructor called!" << std::endl; }

Intern::Intern(Intern const & elem) { (void)elem; std::cout << "Intern Copy Constructor called!" << std::endl; }

Intern::~Intern(void) { std::cout << "Intern Destructor called!" << std::endl; }

Intern & Intern::operator=(Intern const & elem) { (void)elem; return (*this); }


// Member function
AForm * Intern::makeForm(std::string formName, std::string target)
{
	std::string types[3] = {"shrubbery creation", "robotomy request", "presidental pardon"};
	int formIdx = -1;
	for (int i = 0; i < 3; i++)
	{
		if (types[i] == formName)
			formIdx = i;
	}
	switch (formIdx)
	{
		case 0:
			return new ShrubberyCreationForm(target);
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new PresidentalPardonForm(target);
		default:
			return NULL;
	}

}