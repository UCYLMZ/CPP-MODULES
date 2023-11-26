#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Constructor called." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Destructor called." << std::endl;
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