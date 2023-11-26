#include "Weapon.hpp"

class HumanB
{
	private:
			std::string name;
			Weapon 		*weapon;
	public:
			HumanB(std::string name);

			void attack();
			void setWeapon(Weapon &Weapon);

			void setName(std::string name);
			std::string getName(void);
};