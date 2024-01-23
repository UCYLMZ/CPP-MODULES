#pragma once

# include <iostream>

class Animal
{
	protected:
		std::string type;

	public:
		Animal(void);
		Animal(std::string type);
		~Animal(void);
		Animal& operator=(const Animal& elem);

		std::string getType(void) const;

		virtual void makeSound(void) const;
};