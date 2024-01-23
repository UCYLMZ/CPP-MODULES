#pragma once

# include <iostream>

class WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& cpy);
		~WrongAnimal(void);
		WrongAnimal& operator=(const WrongAnimal& elem);

		std::string getType(void) const;

		void makeSound(void) const;
};
