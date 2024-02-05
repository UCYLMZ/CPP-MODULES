#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	ShrubberyCreationForm s1;
	Bureaucrat b1("b1", 144);

	b1.signForm(s1);
	std::cout << s1 << std::endl;

	b1.executeForm(s1);
}