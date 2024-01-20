#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap elem("Yunus");

	ClapTrap elem2("utku");

	elem.attack("olcay");
	// std::cout << elem.getHitPoints() << std::endl;
	elem.takeDamage(5);
	// std::cout << elem.getHitPoints() << std::endl;
	elem.beRepaired(2);
	elem2 = elem;
	std::cout << "elem2 name: " + elem2.getName() << std::endl;
	elem.takeDamage(5);
	// std::cout << elem.getHitPoints() << std::endl;
	elem.takeDamage(1);
	elem.takeDamage(1);
	elem.attack("olcay");
}