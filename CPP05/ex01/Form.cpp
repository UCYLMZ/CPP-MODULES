#include "Form.hpp"


// Constructors, Destructor and Assignment Operator Overload
Form::Form(void) : name("Default Form"), gradeToSign(150), gradeToExecute(150)
{ 
	std::cout << "Form Default Constructor called!" << std::endl;
	this->isSigned = false;
}

Form::Form(std::string name) : name(name), gradeToSign(150), gradeToExecute(150)
{
	std::cout << "Form Named Constructor called!" << std::endl;
	this->isSigned = false;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) :
name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	std::cout << "Form Full Parametered Constructor called!" << std::endl;
	this->isSigned = false;
}

Form::Form(Form& elem) : name(elem.getName()), gradeToSign(elem.getGradeToSign()),
gradeToExecute(elem.getGradeToExecute())
{
	std::cout << "Form Copy Constructor called!" << std::endl;
	this->isSigned = elem.getIsSigned();
}

Form::~Form(void) { std::cout << "Form Destructor called!" << std::endl; }

Form& Form::operator=(Form const& elem)
{
	std::cout << "Form '=' Operator called!" << std::endl;
	this->isSigned = elem.getIsSigned();
	return (*this);
}


// Getter and Setter functions
std::string Form::getName(void) const { return (this->name); }

bool Form::getIsSigned(void) const { return (this->isSigned); }

int Form::getGradeToSign(void) const { return (this->gradeToSign); }

int Form::getGradeToExecute(void) const { return (this->gradeToExecute); }


// Member function
void Form::beSigned(const Bureaucrat& elem)
{
	if (elem.getGrade() > this->getGradeToSign())
		throw GradeTooLowException();
	else
		this->isSigned = true;
}


// Exception Classes
const char* Form::GradeTooHighException::what() const throw()
{ return "Grade is too high!"; }

const char* Form::GradeTooLowException::what() const throw()
{ return "Grade is too low!"; }


// << Operator Overload 
std::ostream& operator<<(std::ostream &os, const Form& elem)
{
	os << elem.getName() + " Form:" << std::endl
	<< "sign status: " << elem.getIsSigned() << std::endl
	<< "form grade to sign: " << elem.getGradeToSign() << std::endl
	<< "form grade to execute: " << elem.getGradeToExecute() << std::endl;
	return os;
}