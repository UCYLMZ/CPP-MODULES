#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error\n";
		return 1;
	}
	RPN elem1(av[1]);
	elem1.calculate();
}