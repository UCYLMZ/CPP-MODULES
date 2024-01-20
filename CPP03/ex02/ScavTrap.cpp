#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap Default Constructor Called!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Constructor Called!" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor Called!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& elem)
{
	this->attackDamage = elem.attackDamage;
	this->name = elem.name;
	this->energyPoints = elem.energyPoints;
	this->hitPoints = elem.hitPoints;

	return (*this);
}

std::string ScavTrap::getName(void)
{
	return (this->name);
}

unsigned int ScavTrap::getHitPoints(void)
{
	return (this->hitPoints);
}

unsigned int ScavTrap::getEnergyPoint(void)
{
	return (this->energyPoints);
}

void ScavTrap::guardGate(void)
{
	if (!this->hitPoints)
		std::cout << "ScavTrap " << this->name << " is dead!" << std::endl;
	else
		std::cout << "ScavTrap " + this->name + " is in Guard Gate mode!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (!this->hitPoints)
		std::cout << "ScavTrap " << this->name << " is dead!" << std::endl;
    else if (energyPoints > 0)
    {
        this->energyPoints--;
        std::cout << "ScavTrap " + this->name + " attacks " + target
			+ " causing " << this->attackDamage << " points of damage" << std::endl;
    }
    else
        std::cout << "ScavTrap " + this->name + " has no energy to attack!" << std::endl;
}