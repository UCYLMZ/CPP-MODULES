#include "Dog.hpp"


// Orthodox canonical requirements
Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog Default constructor called!" << std::endl;
	this->name = "Max";
}

Dog::Dog(std::string name) : Animal("Dog")
{
	std::cout << "Dog constructor called!" << std::endl;
	this->name = name;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called!" << std::endl;
}

Dog& Dog::operator=(const Dog& elem)
{
	this->name = elem.name;
	this->type = elem.type;

	return (*this);
}


// Member function
void Dog::makeSound(void) const { std::cout << "Barkk!" << std::endl; }


// Getter and Setter
std::string Dog::getName(void) { return (this->name); }

void Dog::setName(std::string name) { this->name = name; }