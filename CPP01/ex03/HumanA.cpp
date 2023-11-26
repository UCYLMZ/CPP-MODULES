#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon)
{
	this->name = name;
	this->weapon = weapon;
}

void HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}

void HumanA::setName(std::string name)
{
	this->name = name;
}

std::string HumanA::getName(void)
{
	return (this->name);
}