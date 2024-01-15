#include "Fixed.hpp"

// constructors and destructor
Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->fixedValue = 0;
}

Fixed::Fixed(const Fixed &cpy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->fixedValue = cpy.fixedValue;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedValue = value << this->fraction;
}

Fixed::Fixed(const float float_value)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedValue = int(roundf(float_value * (1 << this->fraction)));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


// operator overload functions
Fixed& Fixed::operator=(const Fixed &cpy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->setRawBits(cpy.fixedValue);
    return (*this);
}

std::ostream &operator<<(std::ostream& os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}

bool	Fixed::operator==(const Fixed &fixed) const
{
	std::cout << "== operator called" << std::endl;
	return (this->fixedValue == fixed.fraction);
}

bool	Fixed::operator!=(const Fixed &fixed) const
{
	std::cout << "!= operator called" << std::endl;
	return (this->fixedValue != fixed.fixedValue);
}

bool	Fixed::operator<(const Fixed &fixed) const
{
	return (this->getRawBits() < fixed.fixedValue);
}

bool	Fixed::operator>(const Fixed &fixed) const
{
	return (this->getRawBits() > fixed.fixedValue);
}

bool	Fixed::operator<=(const Fixed &fixed) const
{
	return (this->getRawBits() <= fixed.fixedValue);
}

bool	Fixed::operator>=(const Fixed &fixed) const
{
	return (this->getRawBits() >= fixed.fixedValue);
}

Fixed	Fixed::operator+(const Fixed &fixed)
{
	std::cout << "+ operator called" << std::endl;
	this->setRawBits(this->fixedValue + fixed.fraction);
	return (*this);
}

Fixed Fixed::operator-(const Fixed &fixed)
{
	std::cout << "- operator called" << std::endl;
	this->setRawBits(this->fixedValue - fixed.fixedValue);
	return (*this);
}

Fixed	Fixed::operator*(const Fixed &fixed)
{
	std::cout << "* operator called" << std::endl;
	this->fixedValue = (this->fixedValue * fixed.fixedValue >> fixed.fraction);
	return (*this);
}

Fixed	Fixed::operator/(const Fixed &fixed)
{
	std::cout << "/ operator called" << std::endl;
	this->setRawBits(this->fixedValue / fixed.fixedValue >> fixed.fraction);
	return (*this);
}

Fixed& Fixed::operator++()
{
	this->fixedValue += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	tmp(*this);
	this->fixedValue += 1;
	return (tmp);
}

Fixed& Fixed::operator--()
{
	this->fixedValue -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->fixedValue -= 1;
	return (tmp);
}


// member functions
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedValue);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedValue = raw;
}

int		Fixed::toInt(void) const
{
	return (this->fixedValue >> this->fraction);
}

float	Fixed::toFloat(void) const
{
	float value = float(this->fixedValue) / (1 << this->fraction);
	return (value);
}

const Fixed &Fixed::max(const Fixed &var1, const Fixed &var2)
{
	std::cout << "constant max called" << std::endl;
	if (var1.fixedValue > var2.fixedValue)
		return(var1);
	return (var2);
}

const Fixed &Fixed::min(const Fixed &var1, const Fixed &var2)
{
	std::cout << "constant min called" << std::endl;
	if (var1.fixedValue > var2.fixedValue)
		return(var2);
	return (var1);
}

const Fixed &Fixed::max(Fixed &var1, Fixed &var2)
{
	std::cout << "non-constant max called" << std::endl;
	if (var1.fixedValue > var2.fixedValue)
		return(var1);
	return (var2);
}

const Fixed &Fixed::min(Fixed &var1, Fixed &var2)
{
	std::cout << "non-constant min called" << std::endl;
	if (var1.fixedValue > var2.fixedValue)
		return(var2);
	return (var1);
}
