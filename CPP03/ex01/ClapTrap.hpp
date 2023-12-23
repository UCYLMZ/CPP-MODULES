#include <iostream>

class ClapTrap
{
private:
	std::string name;
	unsigned int hitPoints;
	unsigned int energyPoints;
	unsigned int attackDamage;

public:
	ClapTrap(std::string name);
	~ClapTrap();

	std::string getName(void);
	unsigned int getHitPoints(void);
	unsigned int getEnergyPoint(void);

	void attack(std::string const& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};
