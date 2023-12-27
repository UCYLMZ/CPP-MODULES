#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:
		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;

	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		~ClapTrap();

		std::string getName(void);
		unsigned int getHitPoints(void);
		unsigned int getEnergyPoint(void);

		void attack(std::string const& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif