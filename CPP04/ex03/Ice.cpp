#include "Ice.hpp"


// Constructors, Destructor and Assignment Operator Overload
Ice::Ice(void) : AMateria("ice") { std::cout << "Ice Default Constructor called!" << std::endl; };

Ice::Ice(Ice const& elem) : AMateria("ice")
{
	std::cout << "Ice Copy Constructor called!" << std::endl;
}

Ice::~Ice(void) { std::cout << "Ice Destructor called!" << std::endl; }

Ice& Ice::operator=(Ice const& elem)
{
	this->AMateria::operator=(elem);

    return (*this);
}


// Member function
Ice* Ice::clone(void) const
{
	Ice* clone = new Ice;
	return (clone);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}