#include "Animal.hpp"


// Orthodox canonical requirements
Animal::Animal(void)
{
	std::cout << "Default Animal constructor called!" << std::endl;
	this->type = "lovely creature";
}

Animal::Animal(std::string type)
{
	std::cout << "Animal contructor called!" << std::endl;
	this->type = type;
}

Animal::Animal(const Animal& cpy)
{
	std::cout << "Animal Copy constructor called!" << std::endl;
	*this = cpy;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called!" << std::endl;
}

Animal& Animal::operator=(const Animal& elem)
{
	std::cout << "Animal '=' operator called!" << std::endl;
	this->type = elem.type;

	return (*this);
}


// Member function
void Animal::makeSound(void) const
{
	std::cout << "Pet mee!" << std::endl;
}


// Getter
std::string Animal::getType(void) const { return (this->type); }