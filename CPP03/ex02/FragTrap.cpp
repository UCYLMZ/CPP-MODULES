#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap default constructor called!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called!" << std::endl;
	this->energyPoints = 100;
	this->hitPoints = 100;
	this->attackDamage = 30;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& elem)
{
	this->name = elem.name;
	this->energyPoints = elem.energyPoints;
	this->attackDamage = elem.attackDamage;
	this->hitPoints = elem.hitPoints;

	return (*this);
}

void FragTrap::highFiveGuys(void)
{
	std::cout << "Give me a high five!" << std::endl;
}