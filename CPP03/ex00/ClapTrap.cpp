#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Constructor Called." << std::endl;
	this->name = name;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor Function Called." << std::endl;
}

std::string ClapTrap::getName(void)
{
	return (this->name);
}

unsigned int ClapTrap::getHitPoints(void)
{
	return (this->hitPoints);
}

void ClapTrap::attack(std::string const& target)
{
	std::cout << "Attack!" << std::endl;
	if (this->energyPoints)
		this->energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "Taking Damage!" << std::endl;
	this->hitPoints--;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "Repairing!" << std::endl;
	if (this->energyPoints)
	{
		this->hitPoints++;
		this->energyPoints--;
	}
}