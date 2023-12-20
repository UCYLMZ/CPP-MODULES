#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
			int					fixedValue;
			static const int	fraction = 20;
	public:
			Fixed(void);
			Fixed(const Fixed& elem);
			Fixed(const int fixedPoint);
			Fixed(const float floatPoint);
			~Fixed(void);

			void operator=(const Fixed& elem);

			int getRawBits(void) const;
			void setRawBits(int const raw);
			float toFloat(void) const;
			int toInt(void) const;
};
			std::ostream &operator<<(std::ostream &os, const Fixed &fixed);


#endif