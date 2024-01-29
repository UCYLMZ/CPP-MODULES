#include "Cure.hpp"
#include "ICharacter.hpp"


// Constructors, Destructor and Assignment Operator Overload
Cure::Cure(void) : AMateria("cure") { std::cout << "Cure Default Constructor called!" << std::endl; };

Cure::Cure(Cure const& elem) : AMateria("cure")
{
	std::cout << "Cure Copy Constructor called!" << std::endl;
}

Cure::~Cure(void) { std::cout << "Cure Destructor called!" << std::endl; }

Cure& Cure::operator=(Cure const& elem)
{
	this->AMateria::operator=(elem);

    return (*this);
}


// Member function
Cure* Cure::clone(void) const
{
	Cure* clone = new Cure;
	return (clone);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}