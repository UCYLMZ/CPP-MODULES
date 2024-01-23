#pragma once

# include "Animal.hpp"

class Cat : public Animal
{
	private:
		std::string name;

	public:
		Cat(void);
		Cat(std::string name);
		~Cat(void);
		Cat& operator=(const Cat& elem);

		std::string getName(void);
		void setName(std::string name);

		void makeSound(void) const;
};
