#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentalPardonForm.hpp"

int main(void)
{
	ShrubberyCreationForm s1;
	RobotomyRequestForm r1;
	PresidentalPardonForm p1;

	Bureaucrat b1("b1", 1);

	b1.signForm(s1);
	b1.signForm(r1);
	b1.signForm(p1);

	std::cout << s1 << std::endl;
	std::cout << r1 << std::endl;
	std::cout << p1 << std::endl;

	b1.executeForm(s1);
	b1.executeForm(r1);
	b1.executeForm(p1);
}
