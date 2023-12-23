#include <iostream>

class ClapTrap
{
private:
	std::string name;
	unsigned int hitPoints = 10;
	unsigned int energyPoints = 10;
	unsigned int attackDamage = 0;

public:
	ClapTrap(std::string name);
	~ClapTrap();

	unsigned int setHitPoints(void);
	unsigned int setEnergyPoint(void);

	std::string getName(void);
	unsigned int getHitPoints(void);
	unsigned int getEnergyPoint(void);

	void attack(std::string const& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};
