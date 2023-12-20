#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called." << std::endl;
	this->fixedValue = 0;
}

Fixed::Fixed(const Fixed& elem)
{
	std::cout << "Copy constructor called." << std::endl;
	this->operator=(elem); 
}

Fixed::Fixed(const int fixedPoint)
{
	std::cout << "Int constructor called." << std::endl;
	this->fixedValue = fixedPoint << this->fraction;
}

Fixed::Fixed(const float floatPoint)
{
	std::cout << "Float constructor called." << std::endl;
	this->fixedValue = ( floatPoint * pow( 2, this->fraction) );
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called." << std::endl;
}

std::ostream &operator<<(std::ostream &output, const Fixed &fixed)
{
	output << fixed.toFloat();
	return (output);
}

void Fixed::operator=(const Fixed& elem)
{
	std::cout << "Copy assignment operator called." << std::endl;
	this->fixedValue = elem.getRawBits();
}

float Fixed::toFloat(void) const
{
	return ( float(this->fixedValue / pow(2, this->fraction)) );
}

int Fixed::toInt(void) const
{
	return ( this->fixedValue >> this->fraction );
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called." << std::endl;
	return ( this->fixedValue );
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called." << std::endl;
	this->fixedValue = raw;
}