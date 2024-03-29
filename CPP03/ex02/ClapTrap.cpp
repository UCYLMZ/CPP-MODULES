#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "Default Constructor Called." << std::endl;
	this->name = "Default ClapTrap";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Constructor Called." << std::endl;
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(ClapTrap& elem)
{
	std::cout << "Copy constructor called." << std::endl;
	this->operator=(elem);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor Function Called." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& elem)
{
	this->name = elem.name;
	this->hitPoints = elem.hitPoints;
	this->energyPoints = elem.energyPoints;
	this->attackDamage = elem.attackDamage;

	return (*this);
}

std::string ClapTrap::getName(void)
{
	return (this->name);
}

unsigned int ClapTrap::getHitPoints(void)
{
	return (this->hitPoints);
}

unsigned int ClapTrap::getEnergyPoint(void)
{
	return (this->energyPoints);
}

void ClapTrap::attack(std::string const& target)
{
	if (!this->hitPoints)
	{
		std::cout << "ClapTrap " << this->name << " is dead!" << std::endl;
		return ;
	}
	if (!this->energyPoints)
	{
		std::cout << "ClapTrap " << this->name << " has no Energy Point to attack!"
			<< std::endl;
	}
	std::cout << "ClapTrap " << this->name << " atacks "
		<< target << ", causing " << this->attackDamage
		<< " points of damage!" << std::endl;
	if (this->energyPoints)
		this->energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->hitPoints)
	{
		std::cout << "ClapTrap " << this->name << " is dead!" << std::endl;
		return ;
	}
	else if (!this->energyPoints)
	{
		std::cout << "ClapTrap " << this->name << " has no Energy Point to take damage!"
			<< std::endl;
	}
	else if(amount > this->hitPoints)
		amount = this->hitPoints;
	std::cout << "ClapTrap " << this->name <<" takes "
		<< amount << " points of damage!" << std::endl;
	this->hitPoints -= amount;
	if (this->hitPoints == 0)
		std::cout << "ClapTrap " << this->name << " is dead!"
			<< std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->hitPoints)
	{
		std::cout << "ClapTrap " << this->name << " is dead!" << std::endl;
		return ;
	}
	else if (!this->energyPoints)
	{
		std::cout << "ClapTrap " << this->name << " has no Energy Point to repair!"
			<< std::endl;
		return ;
	}
	this->energyPoints--;
	this->hitPoints += amount;
	std::cout << "ClapTrap " << this->name << " is repairing itself as "
		<< amount << " points!" << std::endl;
}