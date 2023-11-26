#include "Zombie.hpp"

int main(void)
{
	Zombie *elem2 = newZombie("Neighbour");
	elem2->announce();
	delete elem2;
	elem2->announce();

	Zombie elem1;
	elem1.announce();

	elem1.setName("Woman");
	elem1.announce();

	randomChump("Random");
}