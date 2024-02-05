#pragma once
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const name;
		bool isSigned;
		int const gradeToSign;
		int const gradeToExecute;

	public:
		AForm(void);
		AForm(std::string name);
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(AForm& elem);
		virtual ~AForm(void);

		AForm& operator=(AForm const& elem);

		std::string getName(void) const;
		bool getIsSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;

		void beSigned(const Bureaucrat& elem);

		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream &os, const AForm& elem);