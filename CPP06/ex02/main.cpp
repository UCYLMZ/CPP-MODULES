#include "Base.hpp"

int main(void)
{
	Base * generated = generate();
	identify(generated);
	identify(*generated);
}