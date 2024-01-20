#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		~FragTrap(void);

		FragTrap& operator=(const FragTrap& elem);

		void highFiveGuys(void);
};
