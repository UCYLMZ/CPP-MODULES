#include "Zombie.hpp"

int main(void)
{
	randomChump("Random");
	
	Zombie *zomb1 = newZombie("zomb1");
	zomb1->announce();
	delete zomb1;

	Zombie zomb2;
	zomb2.announce();
	zomb2.setName("zomb2");
	zomb2.announce();

	Zombie zomb3("zomb3");
	zomb3.announce();
}