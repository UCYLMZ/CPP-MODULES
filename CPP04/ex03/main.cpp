#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main(void)
{
	AMateria* ice1 = new Ice;
	AMateria* cure1 = new Cure;

	ICharacter* char1 = new Character("char1");
	ICharacter* char2 = new Character("Char2");
	
	IMateriaSource* source1 = new MateriaSource;
	source1->learnMateria(ice1);
	char1->equip(source1->createMateria("ice"));
	source1->learnMateria(cure1);
	char1->equip(source1->createMateria("cure"));

	char1->use(0, *char2);
	char1->use(1, *char2);

	*(Character*)char2 = *(Character*)char1;

	char2->use(0, *char1);
	char2->use(1, *char1);

	ICharacter* char3 = new Character(*(Character *)char1);

	char3->use(0, *char1);
	char3->use(1, *char2);

	delete ice1;
	delete cure1;
	delete char1;
	delete char2;
	delete char3;
	delete source1;
}
