#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria* equipment[4];
		int equipmentSize;
	
	public:
		Character(void);
		Character(const std::string & name);
		Character(Character const & elem);
		~Character(void);

		Character& operator=(Character const & elem);

		std::string const & getName(void) const;

		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};
