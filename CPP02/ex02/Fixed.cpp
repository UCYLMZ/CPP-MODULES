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
	this->fixedValue = roundf( floatPoint * pow( 2, this->fraction) );
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

bool	Fixed::operator<(const Fixed& elem) const
{
	std::cout << "'<' Operator Called." << std::endl;
	return (this->fixedValue < elem.fixedValue);
}

bool	Fixed::operator>(const Fixed& elem) const
{
	std::cout << "'>' Operator Called." << std::endl;
	return (this->fixedValue > elem.fixedValue);
}

bool	Fixed::operator<=(const Fixed& elem) const
{
	std::cout << "'<=' Operator Called." << std::endl;
	return (this->fixedValue <= elem.fixedValue);
}

bool	Fixed::operator>=(const Fixed& elem) const
{
	std::cout << "'>=' Operator Called." << std::endl;
	return (this->fixedValue >= elem.fixedValue);
}

bool	Fixed::operator==(const Fixed& elem) const
{
	std::cout << "'==' Operator Called." << std::endl;
	return (this->fixedValue == elem.fixedValue);
}

bool	Fixed::operator!=(const Fixed& elem) const
{
	std::cout << "'!=' Operator Called." << std::endl;
	return (this->fixedValue != elem.fixedValue);
}

Fixed	Fixed::operator+(const Fixed& elem) const
{
	std::cout << "'+' Operator Called." << std::endl;
	int result = this->fixedValue + elem.fixedValue;
	return (Fixed(result));
}

Fixed	Fixed::operator-(const Fixed& elem) const
{
	std::cout << "'-' Operator Called." << std::endl;
	int result = this->fixedValue - elem.fixedValue;
	return (Fixed(result));
}

Fixed	Fixed::operator*(const Fixed& elem) const
{
	std::cout << "'*' Operator Called." << std::endl;
	int result = this->fixedValue * elem.fixedValue;
	return (Fixed(result));
}

Fixed	Fixed::operator/(const Fixed& elem) const
{
	std::cout << "'/' Operator Called." << std::endl;
	int result = this->fixedValue / elem.fixedValue;
	return (Fixed(result));
}

Fixed& Fixed::operator++(void)
{
	std::cout << "Pre-increment Operator Called." << std::endl;
	++fixedValue;
	return (*this);
}

Fixed& Fixed::operator--(void)
{
	std::cout << "Pre-decrement Operator Called." << std::endl;
	++fixedValue;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	std::cout << "Post-increment Operator Called." << std::endl;
	Fixed temp = *this;
	++fixedValue;
	return (temp);
}

Fixed Fixed::operator--(int)
{
	std::cout << "Post-decrement Operator Called." << std::endl;
	Fixed temp = *this;
	--fixedValue;
	return (temp);
}

const Fixed& Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1.fixedValue < fixed2.fixedValue) ? fixed1 : fixed2;
}

const Fixed& Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1.fixedValue > fixed2.fixedValue) ? fixed1 : fixed2;
}

float Fixed::toFloat(void) const
{
	return ( float(this->fixedValue / pow(2, this->fraction)) );
}

int Fixed::toInt(void) const
{
	return ( int(this->fixedValue >> this->fraction) );
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