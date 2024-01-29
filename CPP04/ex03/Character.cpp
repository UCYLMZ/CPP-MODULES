#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"


// Constructor, Destructor and Operator Overload functions
Character::Character(void) : name("default")
{
	std::cout << "Character Default Constructor called!" << std::endl;
	for (int i = 0; i < 4; i++)
		this->equipment[i] = NULL;
	this->equipmentSize = 0;
}

Character::Character(const std::string & name) : name(name)
{
	std::cout << "Character Name Constructor called!" << std::endl;
	for (int i = 0; i < 4; i++)
		this->equipment[i] = NULL;
	this->equipmentSize = 0;
}

Character::Character(Character const & elem) : name(elem.getName())
{
	std::cout << "Character Copy Constructor called!" << std::endl;
	for(int i = 0; i < 4; i++)
	{
		if (elem.equipment[i] == NULL)
			this->equipment[i] = NULL;
		else
			this->equipment[i] = elem.equipment[i]->clone();
	}
	this->equipmentSize = elem.equipmentSize;
}

Character::~Character(void)
{
	std::cout << "Character Destructor called!" << std::endl;
	for(int i = 0; i < 4; i++)
	{
		if (this->equipment[i] != NULL)
			delete this->equipment[i];
	}
}

Character& Character::operator=(Character const & elem)
{
	std::cout << "Character '=' Operator called!" << std::endl;
	for(int i = 0; i < 4; i++)
	{
		if (this->equipment[i] != NULL)
		{
			delete this->equipment[i];
			if (elem.equipment[i] != NULL)
				this->equipment[i] = NULL;
			else
				this->equipment[i] = elem.equipment[i]->clone();
		}
		else
		{
			if (elem.equipment[i] == NULL)
				this->equipment[i] = NULL;
			else
				this->equipment[i] = elem.equipment[i]->clone();
		}
	}
	this->equipmentSize = elem.equipmentSize;
	return (*this);
}


// Getter Function
std::string const & Character::getName(void) const { return (this->name); }


// Member Functions
void Character::equip(AMateria* m)
{
	if (this->equipmentSize == 4)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->equipment[i] == NULL)
		{
			this->equipment[i] = m;
			break ;
		}
	}
	(this->equipmentSize)++;
}

void Character::unequip(int idx)
{
	if (idx > 3 || !this->equipment[idx])
		return ;
	this->equipment[idx] = NULL;
	(this->equipmentSize)--;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx > 3 || this->equipment[idx] == NULL)
		return ;
	(this->equipment[idx])->use(target);
}