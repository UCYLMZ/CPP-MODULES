#include "Fixed.hpp"

Fixed::Fixed( void )
{
	std::cout << "Default constructor called." << std::endl;
	this->fixedValue = 0;
}

Fixed::Fixed( const Fixed& elem )
{
	std::cout << "Copy constructor called." << std::endl;
	this->operator=(elem); 
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called." << std::endl;
}

void Fixed::operator=( const Fixed& elem )
{
	std::cout << "Copy assignment operator called." << std::endl;
	this->fixedValue = elem.getRawBits();
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called." << std::endl;
	return (this->fixedValue);
}

void Fixed::setRawBits( int const raw )
{
	this->fixedValue = raw;
}