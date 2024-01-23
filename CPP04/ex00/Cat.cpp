#include "Cat.hpp"


// Orthodox canonical requirements
Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat Default constructor called!" << std::endl;
	this->name = "Garfield";
}

Cat::Cat(std::string name) : Animal("Cat")
{
	std::cout << "Cat constructor called!" << std::endl;
	this->name = name;
}

Cat::Cat(const Cat& cpy) : Animal(cpy)
{
	std::cout << "Cat copy constructor called!" << std::endl;
	*this = cpy;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called!" << std::endl;
}

Cat& Cat::operator=(const Cat& elem)
{
	this->name = elem.name;
	this->type = elem.type;

	return (*this);
}


// Member function
void Cat::makeSound(void) const { std::cout << "Meoww!" << std::endl; }


// Getter and Setter
std::string Cat::getName(void) { return (this->name); }

void Cat::setName(std::string name) { this->name = name; }