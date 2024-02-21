#pragma once

# include "AForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(Intern const & intern);
		~Intern(void);

		Intern& operator=(Intern const & elem);
		AForm * makeForm(std::string formName, std::string target);
};