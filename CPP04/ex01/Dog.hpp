#pragma once

# include "Animal.hpp"

class Dog : public Animal
{
	private:
		std::string name;

	public:
		Dog(void);
		Dog(std::string name);
		~Dog(void);
		Dog& operator=(const Dog& elem);

		std::string getName(void);
		void setName(std::string name);

		void makeSound(void) const;
};
