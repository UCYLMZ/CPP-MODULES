#include "AAnimal.hpp"


// Orthodox canonical requirements
AAnimal::AAnimal(void)
{
	std::cout << "Default AAnimal constructor called!" << std::endl;
	this->type = "lovely creature";
}

AAnimal::AAnimal(std::string type)
{
	std::cout << "AAnimal contructor called!" << std::endl;
	this->type = type;
}

AAnimal::AAnimal(const AAnimal& cpy)
{
	std::cout << "AAnimal Copy constructor called!" << std::endl;
	*this = cpy;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called!" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& elem)
{
	std::cout << "AAnimal '=' operator called!" << std::endl;
	this->type = elem.type;

	return (*this);
}


// Getter
std::string AAnimal::getType(void) const { return (this->type); }