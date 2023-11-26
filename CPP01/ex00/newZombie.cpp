#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *element = new Zombie(name);

	return (element);
}