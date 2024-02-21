#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentalPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern i1;
	Bureaucrat b1("b1", 1);
	ShrubberyCreationForm s2("hello");

	AForm * s1 = i1.makeForm("shrubbery creation", "shrubbery from intern");
	AForm * r1 = i1.makeForm("robotomy request", "robotomy from intern");
	AForm * p1 = i1.makeForm("presidental pardon", "presidental from intern");

	b1.signForm(*s1);
	b1.signForm(*r1);
	b1.signForm(*p1);

	std::cout << *s1 << std::endl;
	std::cout << *r1 << std::endl;
	std::cout << *p1 << std::endl;

	b1.executeForm(*s1);
	b1.executeForm(*r1);
	b1.executeForm(*p1);

	delete s1;
	delete r1;
	delete p1;
}