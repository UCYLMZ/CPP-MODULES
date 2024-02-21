#pragma once

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const & elem);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm& operator=(ShrubberyCreationForm const & elem);

		std::string getTarget(void);

		class AuthenticateException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class FileOpenException : public std::exception
		{
			public:
				virtual const char* what () const throw();
		};

		void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream &os, const ShrubberyCreationForm& elem);
