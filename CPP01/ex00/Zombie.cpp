#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Default constructor called." << std::endl;
}

Zombie::Zombie(std::string name)
{
	std::cout << name + " Copy constructor called." << std::endl;
	this->name = name;
}

Zombie::~Zombie(void)
{
	std::cout << name << ": Destructor called" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

std::string Zombie::getName(void)
{
	return (this->name);
}