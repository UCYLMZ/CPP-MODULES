#include "iter.hpp"

void addOne(int & elem)
{ elem += 1; }

void dropFirst( std::string & str )
{ str.erase(0, 1); }


int main(void)
{
	int arrInt[] = {1, 2, 3, 4, 5};
	iter(arrInt, 5, &addOne);
	for (int i = 0; i < 5; i++)
		std::cout << arrInt[i] << ", ";
	
	std::cout << std::endl << std::endl;

	std::string arrString[3] = {"hhello", "ffrom", "mmars"};
	iter(arrString, 3, &dropFirst);
	for (int i = 0; i < 3; i++)
		std::cout << arrString[i] << ", ";

	std::cout << std::endl << std::endl;
}