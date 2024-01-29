#pragma once

# include <iostream>

class AAnimal
{
	protected:
		std::string type;

	public:
		AAnimal(void);
		AAnimal(std::string type);
		AAnimal(const AAnimal& cpy);
		virtual ~AAnimal(void);
		AAnimal& operator=(const AAnimal& elem);

		std::string getType(void) const;

		virtual void makeSound(void) const = 0;
};