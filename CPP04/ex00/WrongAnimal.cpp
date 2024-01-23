#include "WrongAnimal.hpp"


// Orthodox canonical requirements
WrongAnimal::WrongAnimal(void)
{
	std::cout << "Default WrongAnimal constructor called!" << std::endl;
	this->type = "lovely creature";
}

WrongAnimal::WrongAnimal(std::string type)
{
	std::cout << "WrongAnimal contructor called!" << std::endl;
	this->type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal& cpy)
{
	std::cout << "WrongAnimal Copy constructor called!" << std::endl;
	*this = cpy;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called!" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& elem)
{
	this->type = elem.type;

	return (*this);
}


// Member function
void WrongAnimal::makeSound(void) const
{
	std::cout << "Pet mee Wrong!" << std::endl;
}


// Getter
std::string WrongAnimal::getType(void) const { return (this->type); }