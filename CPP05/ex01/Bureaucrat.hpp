#pragma once

#include <iostream>
#include "Form.hpp"

class Form;

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

		Bureaucrat& operator=(Bureaucrat& elem);

		std::string getName(void) const;
		int getGrade(void) const;

		void gradeIncrement(void);
		void gradeDecrement(void);

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

		void signForm(Form& elem);
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat& elem);