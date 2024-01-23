#pragma once

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:
		std::string name;

	public:
		WrongCat(void);
		WrongCat(std::string name);
		WrongCat(const WrongCat& cpy);
		~WrongCat(void);
		WrongCat& operator=(const WrongCat& elem);

		std::string getName(void);
		void setName(std::string name);

		void makeSound(void) const;
};