#pragma once

#include <iostream>

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

};

std::ostream& operator<<(std::ostream &os, const Bureaucrat& elem);