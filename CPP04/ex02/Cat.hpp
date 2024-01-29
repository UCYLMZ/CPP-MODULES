#pragma once

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		std::string name;
		Brain *brain;

	public:
		Cat(void);
		Cat(std::string name);
		Cat(const Cat& cpy);
		~Cat(void);
		Cat& operator=(const Cat& elem);

		std::string getName(void);
		Brain* getBrain(void) const;
		void setName(std::string name);

		void makeSound(void) const;
};
