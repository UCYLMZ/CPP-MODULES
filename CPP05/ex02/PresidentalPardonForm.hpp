#pragma once

# include "AForm.hpp"

class PresidentalPardonForm : public AForm
{
	private:
		std::string target;

	public:
		PresidentalPardonForm(void);
		PresidentalPardonForm(std::string target);
		PresidentalPardonForm(PresidentalPardonForm const & elem);
		~PresidentalPardonForm(void);

		PresidentalPardonForm& operator=(PresidentalPardonForm const & elem);

		std::string getTarget(void);

		class AuthenticateException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &os, const PresidentalPardonForm& elem);
