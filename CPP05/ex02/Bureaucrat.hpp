#pragma once

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		std::string const name;
		int grade;

	public:
		Bureaucrat(void);
		Bureaucrat(std::string name);
		Bureaucrat(int grade);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat& elem);
		~Bureaucrat(void);

		Bureaucrat& operator=(Bureaucrat const & elem);

		std::string getName(void) const;
		int getGrade(void) const;

		void gradeIncrement(int amount);
		void gradeDecrement(int amount);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		void signForm(AForm& elem);
		void executeForm(AForm const & form);
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat& elem);