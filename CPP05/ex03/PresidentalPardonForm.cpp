#include "PresidentalPardonForm.hpp"


// Constructors, Destructor and Assignment Operator Overload functions
PresidentalPardonForm::PresidentalPardonForm(void) : AForm("presidental", 25, 5), target("")
{ std::cout << "PresidentalPardonForm Default Constructor called!" << std::endl; }

PresidentalPardonForm::PresidentalPardonForm(std::string target) : AForm("presidental", 25, 5)
, target(target)
{ std::cout << "PresidentalPardonForm Target Constructor called!" << std::endl;}

PresidentalPardonForm::PresidentalPardonForm(PresidentalPardonForm const & elem) : AForm("presidental", 25, 5)
, target(elem.target)
{ std::cout << "PresidentalPardonForm Copy Constructor called!" << std::endl;}

PresidentalPardonForm::~PresidentalPardonForm(void)
{ std::cout << "PresidentalPardonForm Destructor called!" << std::endl; }

PresidentalPardonForm & PresidentalPardonForm::operator=(PresidentalPardonForm const & elem)
{
	this->target = elem.target;
	return (*this);
}


// Getter function
std::string PresidentalPardonForm::getTarget(void){ return (this->target); }


// Exceptions Definitions
const char* PresidentalPardonForm::AuthenticateException::what() const throw()
{ return ("This Form Is Not Signed!"); }


// Member function
void PresidentalPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw PresidentalPardonForm::AuthenticateException();
	else if(this->getGradeToExecute() < executor.getGrade())
		throw AForm::GradeTooLowException();
	else
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}


// << Operator Overload
std::ostream& operator<<(std::ostream &os, const PresidentalPardonForm& elem)
{
	os << " Presidental Pardon Form: " + elem.getName() << std::endl
	<< "sign status: " << elem.getIsSigned() << std::endl
	<< "AForm grade to sign: " << elem.getGradeToSign() << std::endl
	<< "AForm grade to execute: " << elem.getGradeToExecute() << std::endl;
	return os;
}