#pragma once

#include "AMateria.hpp"
#include "IMateriaSource.hpp"


class AMateria;

class MateriaSource : public IMateriaSource
{
	protected:
		AMateria* knownMaterias[4];
		int materiaSize;

	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const& elem);
		~MateriaSource(void);
		MateriaSource& operator=(MateriaSource const& elem);

		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};