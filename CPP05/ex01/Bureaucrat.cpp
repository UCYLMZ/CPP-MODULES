#include "Bureaucrat.hpp"


// Contructors, Destructor and Assignment Operator Overload functions
Bureaucrat::Bureaucrat(void) : name("Default Bureaucrat"), grade(150)
{ std::cout << "Bureaucrat Default Constructor called!" << std::endl; }

Bureaucrat::Bureaucrat(std::string name) : name(name), grade(150)
{ std::cout << "Bureaucrat String Constructor called!" << std::endl; }

Bureaucrat::Bureaucrat(int grade) : name("Default Bureaucrat")
{
	std::cout << "Bureaucrat Grade Constructor called!" << std::endl;
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	std::cout << "Bureaucrat Full Parametered Constructor called!" << std::endl;
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat& elem) : name(elem.getName()), grade(elem.getGrade())
{ std::cout << "Bureaucrat Copy Constructor called!" << std::endl; }

Bureaucrat::~Bureaucrat(void) { std::cout << "Bureaucrat Destructor called!" << std::endl; }

Bureaucrat& Bureaucrat::operator=(Bureaucrat& elem)
{
	std::cout << "Bureaucrat '=' Operator called!" << std::endl;
	this->grade = elem.getGrade();
	return (*this);
}


// Getter and Setter functions
std::string Bureaucrat::getName(void) const { return (this->name); }

int Bureaucrat::getGrade(void) const { return (this->grade); }


// Member functions
void Bureaucrat::gradeIncrement(void) 
{
	if (this->getGrade() == 1)
		throw(Bureaucrat::GradeTooHighException());
	else
		this->grade -= 1;
}

void Bureaucrat::gradeDecrement(void)
{
	if (this->grade > 149)
		throw(Bureaucrat::GradeTooLowException());
	else
		this->grade += 1;
}

void Bureaucrat::signForm(Form& elem)
{
	try
	{
		elem.beSigned(*this);
		std::cout << this->getName() << " signed the " << elem.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() + " " << "couldn't sign " << elem.getName()
		<< " because " << e.what() << std::endl;
	}
}


// Exception Classes
const char* Bureaucrat::GradeTooHighException::what() const throw()
{ return "Grade is too high!"; }

const char* Bureaucrat::GradeTooLowException::what() const throw()
{ return "Grade is too low!"; }


// << Operator Overload 
std::ostream& operator<<(std::ostream &os, const Bureaucrat& elem)
{
	os << elem.getName() << ", bureaucrat grade " << elem.getGrade() << std::endl;
	return os;
}