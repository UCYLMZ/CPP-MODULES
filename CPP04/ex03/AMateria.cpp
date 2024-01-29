#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Cure.hpp"
#include "Ice.hpp"


// Constructors, Destructor and Assignment Operator Overload
AMateria::AMateria(void)
{
	this->type = "0";
	std::cout << "AMateria Default Constructor called!" << std::endl;
}

AMateria::AMateria(std::string const& type)
{
	this->type = type;
	std::cout << "AMateria Type Constructor called!" << std::endl;
}

AMateria::AMateria(AMateria const& elem)
{
	this->type = elem.getType();
	std::cout << "AMateria Copy Constructor called!" << std::endl;
}

AMateria::~AMateria(void) { std::cout << "AMateria Destructor called!" << std::endl; }

AMateria& AMateria::operator=(AMateria const& elem)
{ std::cout << "AMateria '=' Operator called!" << std::endl; return (*this); }


// Getter and Setter Functions
std::string const& AMateria::getType(void) const { return (this->type); }

void AMateria::setType(std::string const & type) { this->type = type; }


// Memeber Function
void AMateria::use(ICharacter& target)
{
	if (this->getType() == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else if (this->getType() == "cure")
		std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

AMateria* AMateria::clone(void) const
{
	if (this->getType() == "cure")
		return new Cure;
	else if (this->getType() == "ice")
		return new Ice;
	return NULL;
}