#pragma once

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		std::string name;
		Brain* brain;

	public:
		Dog(void);
		Dog(std::string name);
		Dog(const Dog& cpy);
		~Dog(void);
		Dog& operator=(const Dog& elem);

		Brain* getBrain(void) const;
		std::string getName(void);
		void setName(std::string name);

		void makeSound(void) const;
};
