#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
			int					fixedValue;
			static const int	fraction = 8;
	public:
			Fixed( void );
			Fixed( const Fixed& elem );
			~Fixed( void );

			void operator=( const Fixed& elem );

			int getRawBits( void ) const;
			void setRawBits( int const raw );
};

#endif