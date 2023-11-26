#include "Zombie.hpp"

int main(void)
{
	int size = 5;

	Zombie *horde = zombieHorde(size, "First Horde");

	for (int i = 0; i < size; i++)
		horde[i].announce();

	delete[] horde;
}