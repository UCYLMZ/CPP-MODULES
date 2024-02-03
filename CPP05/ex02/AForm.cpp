#include "AForm.hpp"


// Constructors, Destructor and Assignment Operator Overload
AForm::AForm(void) : name("Default AForm"), gradeToSign(150), gradeToExecute(150)
{ 
	std::cout << "AForm Default Constructor called!" << std::endl;
	this->isSigned = false;
}

AForm::AForm(std::string name) : name(name), gradeToSign(150), gradeToExecute(150)
{
	std::cout << "AForm Named Constructor called!" << std::endl;
	this->isSigned = false;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) :
name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	std::cout << "AForm Full Parametered Constructor called!" << std::endl;
	this->isSigned = false;
}

AForm::AForm(AForm& elem) : name(elem.getName()), gradeToSign(elem.getGradeToSign()),
gradeToExecute(elem.getGradeToExecute())
{
	std::cout << "AForm Copy Constructor called!" << std::endl;
	this->isSigned = elem.getIsSigned();
}

AForm::~AForm(void) { std::cout << "AForm Destructor called!" << std::endl; }

AForm& AForm::operator=(AForm const& elem)
{
	std::cout << "AForm '=' Operator called!" << std::endl;
	this->isSigned = elem.getIsSigned();
	return (*this);
}


// Getter and Setter functions
std::string AForm::getName(void) const { return (this->name); }

bool AForm::getIsSigned(void) const { return (this->isSigned); }

int AForm::getGradeToSign(void) const { return (this->gradeToSign); }

int AForm::getGradeToExecute(void) const { return (this->gradeToExecute); }


// Member function
void AForm::beSigned(const Bureaucrat& elem)
{
	if (elem.getGrade() > this->getGradeToSign())
		throw GradeTooLowException();
	else
		this->isSigned = true;
}


// Exception Classes
const char* AForm::GradeTooHighException::what() const throw()
{ return "Grade is too high!"; }

const char* AForm::GradeTooLowException::what() const throw()
{ return "Grade is too low!"; }


// << Operator Overload 
std::ostream& operator<<(std::ostream &os, const AForm& elem)
{
	os << elem.getName() + " AForm:" << std::endl
	<< "sign status: " << elem.getIsSigned() << std::endl
	<< "AForm grade to sign: " << elem.getGradeToSign() << std::endl
	<< "AForm grade to execute: " << elem.getGradeToExecute() << std::endl;
	return os;
}