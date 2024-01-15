#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
			int					fixedValue;
			static const int	fraction = 8;
	public:
			Fixed(void);
			Fixed(const Fixed& elem);
			Fixed(const int fixedPoint);
			Fixed(const float floatPoint);
			~Fixed(void);

			Fixed& operator=(const Fixed& elem);

			bool operator<(const Fixed& elem) const;
			bool operator>(const Fixed& elem) const;
			bool operator<=(const Fixed& elem) const;
			bool operator>=(const Fixed& elem) const;
			bool operator==(const Fixed& elem) const;
			bool operator!=(const Fixed& elem) const;

			Fixed	operator+(const Fixed& elem);
			Fixed	operator-(const Fixed& elem);
			Fixed	operator*(const Fixed& elem);
			Fixed	operator/(const Fixed& elem);

			Fixed	&operator++(void);
			Fixed	&operator--(void);
			Fixed	operator++(int);
			Fixed	operator--(int);

			static const Fixed& min(const Fixed &fixed1, const Fixed &fixed2);
			static const Fixed& max(const Fixed &fixed1, const Fixed &fixed2);

			static const Fixed& min(Fixed &fixed1, Fixed &fixed2);
			static const Fixed& max(Fixed &fixed1, Fixed &fixed2);

			int getRawBits(void) const;
			void setRawBits(int const raw);
			float toFloat(void) const;
			int toInt(void) const;
};
			std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif