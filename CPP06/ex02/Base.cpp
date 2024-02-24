#include "Base.hpp"

Base::~Base(void) { std::cout << "Base Destructor!" << std::endl; }


// Functions
Base * generate(void)
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

void identify(Base * p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "The type is 'A'." << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "The type is 'B'." << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "The type is 'C'." << std::endl;
	else
		std::cout << "The type could not found!" << std::endl;
}

void identify(Base & p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "The type is 'A'." << std::endl;
		return ;
	}
	catch (const std::exception &e) {}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "The type is 'B'." << std::endl;
		return ;
	}
	catch (const std::exception &e) {}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "The type is 'C'." << std::endl;
		return ;
	}
	catch (const std::exception &e) 
	{
		std::cout << "The type could not found!" << std::endl;
	}
}
