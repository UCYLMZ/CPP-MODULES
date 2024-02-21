#pragma once

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const & elem);
		~RobotomyRequestForm(void);

		RobotomyRequestForm& operator=(RobotomyRequestForm const & elem);

		std::string getTarget(void);

		class AuthenticateException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream &os, const RobotomyRequestForm& elem);
