#include "WrongCat.hpp"


// Orthodox canonical requirements
WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Default constructor called!" << std::endl;
	this->name = "Garfield";
}

WrongCat::WrongCat(std::string name) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat constructor called!" << std::endl;
	this->name = name;
}

WrongCat::WrongCat(const WrongCat& cpy) : WrongAnimal(cpy)
{
	std::cout << "WrongCat copy constructor called!" << std::endl;
	*this = cpy;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called!" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& elem)
{
	this->name = elem.name;
	this->type = elem.type;

	return (*this);
}


// Member function
void WrongCat::makeSound(void) const { std::cout << "Meoww!" << std::endl; }


// Getter and Setter
std::string WrongCat::getName(void) { return (this->name); }

void WrongCat::setName(std::string name) { this->name = name; }