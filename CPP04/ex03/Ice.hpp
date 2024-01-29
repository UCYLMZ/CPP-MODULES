#pragma once

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(Ice const& elem);
		~Ice(void);
		Ice& operator=(Ice const& elem);

		Ice* clone(void) const;
		void use(ICharacter& target);
};