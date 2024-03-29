#include "RobotomyRequestForm.hpp"


// Constructors, Destructor and Assignment Operator Overload functions
RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy", 72, 45), target("")
{ std::cout << "RobotomyRequestForm Default Constructor called!" << std::endl; }

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45)
, target(target)
{ std::cout << "RobotomyRequestForm Target Constructor called!" << std::endl;}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & elem) : AForm("Robotomy", 72, 45)
, target(elem.target)
{ std::cout << "RobotomyRequestForm Copy Constructor called!" << std::endl;}

RobotomyRequestForm::~RobotomyRequestForm(void)
{ std::cout << "RobotomyRequestForm Destructor called!" << std::endl; }

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & elem)
{
	this->target = elem.target;
	return (*this);
}


// Getter function
std::string RobotomyRequestForm::getTarget(void){ return (this->target); }


// Member function
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw AuthenticateException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	srand(time(NULL));
	std::cout << "drill drill!!!" << std::endl;
	if (rand() % 2 == 1)
		std::cout << this->target << " has beed robotomized succesfully!" << std::endl;
	else
		std::cout << this->target << " robotomize process failed!" << std::endl;
}


// Exceptions Definitions
const char* RobotomyRequestForm::AuthenticateException::what() const throw()
{ return ("This Form Is Not Signed!"); }



// << Operator Overload
std::ostream& operator<<(std::ostream &os, const RobotomyRequestForm& elem)
{
	os << " Robotomy Request Form: " + elem.getName() << std::endl
	<< "sign status: " << elem.getIsSigned() << std::endl
	<< "AForm grade to sign: " << elem.getGradeToSign() << std::endl
	<< "AForm grade to execute: " << elem.getGradeToExecute() << std::endl;
	return os;
}