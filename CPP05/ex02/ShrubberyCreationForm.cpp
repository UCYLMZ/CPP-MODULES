#include "ShrubberyCreationForm.hpp"


// Constructors, Destructor and Assignment Operator Overload functions
ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("shrubbery", 145, 137), target("")
{ std::cout << "ShrubberyCreationForm Default Constructor called!" << std::endl; }

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("shrubbery", 145, 137)
, target(target)
{ std::cout << "ShrubberyCreationForm Target Constructor called!" << std::endl;}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & elem) : AForm("shrubbery", 145, 137)
, target(elem.target)
{ std::cout << "ShrubberyCreationForm Copy Constructor called!" << std::endl;}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{ std::cout << "ShrubberyCreationForm Destructor called!" << std::endl; }

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & elem)
{
	this->target = elem.target;
	return (*this);
}


// Getter function
std::string ShrubberyCreationForm::getTarget(void){ return (this->target); }


// Exceptions Definitions
const char* ShrubberyCreationForm::AuthenticateException::what() const throw()
{ return ("This Form Is Not Signed!"); }

const char* ShrubberyCreationForm::FileOpenException::what() const throw()
{ return ("File Could Not Be Opened!"); }


// Member function
void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == false)
		throw ShrubberyCreationForm::AuthenticateException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else
	{
        std::ofstream file(this->target + "_ShrubberyCreationForm");
        if (file.is_open())
        {
            file <<
			"               * \n"
			"              *** \n"
			"             ***** \n"
			"            ******* \n"
			"           ********* \n"
			"          *********** \n"
			"         ************* \n"
			"        *************** \n"
			"       ***************** \n"
			"      ******************* \n"
			"     ********************* \n"
			"    *********************** \n"
			"   ************************* \n"
			"            |     |            \n"
			"            |     |            \n" << std::endl;
            file.close();
        }
        else
            throw ShrubberyCreationForm::FileOpenException();

    }	
}


// << Operator Overload
std::ostream& operator<<(std::ostream &os, const ShrubberyCreationForm& elem)
{
	os << " Shrubbery Creation Form: " + elem.getName() << std::endl
	<< "sign status: " << elem.getIsSigned() << std::endl
	<< "AForm grade to sign: " << elem.getGradeToSign() << std::endl
	<< "AForm grade to execute: " << elem.getGradeToExecute() << std::endl;
	return os;
}