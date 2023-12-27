#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap elem("Yunus");

	elem.attack("olcay");
	// std::cout << elem.getHitPoints() << std::endl;
	elem.takeDamage(10);
	// std::cout << elem.getHitPoints() << std::endl;
	elem.beRepaired(2);
	std::cout << elem.getHitPoints() << std::endl;
	// elem.guardGate();
	elem.takeDamage(100);
	elem.attack("olcay");
}