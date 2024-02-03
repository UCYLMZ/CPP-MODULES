#include "PresidentalPardonForm.hpp"


// Constructors, Destructor and Assignment Operator Overload functions
PresidentalPardonForm::PresidentalPardonForm(void) : AForm("presidental", 145, 137), target("")
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


// << Operator Overload
std::ostream& operator<<(std::ostream &os, const PresidentalPardonForm& elem)
{
	os << " Presidental Pardon Form: " + elem.getName() << std::endl
	<< "sign status: " << elem.getIsSigned() << std::endl
	<< "AForm grade to sign: " << elem.getGradeToSign() << std::endl
	<< "AForm grade to execute: " << elem.getGradeToExecute() << std::endl;
	return os;
}