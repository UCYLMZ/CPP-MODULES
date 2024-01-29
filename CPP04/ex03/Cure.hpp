#pragma once

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(Cure const& elem);
		~Cure(void);
		Cure& operator=(Cure const& elem);

		Cure* clone(void) const;
		void use(ICharacter& target);
};