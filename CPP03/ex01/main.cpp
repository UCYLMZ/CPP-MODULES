#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap elem("Yunus");

	elem.attack("olcay");
	// std::cout << elem.getHitPoints() << std::endl;
	elem.takeDamage(5);
	// std::cout << elem.getHitPoints() << std::endl;
	elem.beRepaired(2);
	elem.takeDamage(5);
	// std::cout << elem.getHitPoints() << std::endl;
	elem.takeDamage(1);
	elem.takeDamage(1);
	elem.attack("olcay");
}