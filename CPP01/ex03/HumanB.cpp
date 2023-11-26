#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

void HumanB::attack(void)
{
	if (this->weapon == NULL)
		std::cout << this->name << " attacks with their hand" << std::endl;
	else
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void HumanB::setName(std::string name)
{
	this->name = name;
}

std::string HumanB::getName(void)
{
	return (this->name);
}