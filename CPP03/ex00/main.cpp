#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap elem;
	ClapTrap elem2("utku");
	ClapTrap elem3(elem2);

	elem.attack("olcay");
	elem.takeDamage(5);
	elem.beRepaired(2);
	elem2 = elem;
	std::cout << "elem2 name: " + elem2.getName() << std::endl;
	elem.takeDamage(5);
	elem.takeDamage(1);
	elem.takeDamage(1);
	elem.attack("olcay");
}