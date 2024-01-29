#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"


// Constructor, Destructor and Operator Overload functions
MateriaSource::MateriaSource(void)
{
	std::cout << "MateriaSource Default Constructor called!" << std::endl;
	for (int i = 0; i < 4; i++)
		this->knownMaterias[i] = NULL;
	this->materiaSize = 0;
}

MateriaSource::MateriaSource(MateriaSource const & elem)
{
	std::cout << "MaterialSource Copy Constructor called!" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (elem.knownMaterias[i] != NULL)
			this->knownMaterias[i] = elem.knownMaterias[i]->clone();
		else
			this->knownMaterias[i] = NULL;
	}
	this->materiaSize = elem.materiaSize;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource Destructor called!" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->knownMaterias[i] != NULL)
			delete this->knownMaterias[i];
	}
}

MateriaSource& MateriaSource::operator=(MateriaSource const & elem)
{
	std::cout << "MateriaSource '=' Operator called!" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (elem.knownMaterias[i] != NULL)
			this->knownMaterias[i] = elem.knownMaterias[i]->clone();
	}
	this->materiaSize = elem.materiaSize;

	return (*this);
}


// Member functions
void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->knownMaterias[i] == NULL)
		{
			this->knownMaterias[i] = m->clone();
			this->materiaSize++;
			break ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->knownMaterias[i] != NULL)
		{
			if (this->knownMaterias[i]->getType() == type)
				return (this->knownMaterias[i]->clone());
		}
	}
	return NULL;
}