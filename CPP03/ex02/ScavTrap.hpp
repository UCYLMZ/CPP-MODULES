#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		~ScavTrap(void);

		std::string getName(void);
		unsigned int getHitPoints(void);
		unsigned int getEnergyPoint(void);
	
		void attack(const std::string& target);
		void guardGate();
};

#endif