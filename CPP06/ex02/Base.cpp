#include "Base.hpp"

Base::Base(void) { std::cout << "Base Constructor!" << std::endl; }

Base::~Base(void) { std::cout << "Base Destructor!" << std::endl; }


// Member Funcitons
Base * Base::generate(void)
{
	srand(time(NULL));
	int random = rand() % 3;

	switch (random)
	{
		case 0:
			return ((Base *)new A);
		case 1:
			return ((Base *)new B);
		case 2:
			return ((Base *)new C);
		
		default:
			return NULL;
	}
}