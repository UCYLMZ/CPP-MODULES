#include "ScavTrap.hpp"

void printValues(ClapTrap& clapTrap)
{
    std::cout << "\nName: " + clapTrap.getName() << "\nenergyPoints: " << clapTrap.getEnergyPoint()
            << "\nhitPoints: " << clapTrap.getHitPoints() << std::endl << std::endl;
}

int main()
{
    ScavTrap clapTrap("utku");

    ScavTrap clapTrap2("can");

    printValues(clapTrap);
    printValues(clapTrap2);

    clapTrap.attack("can");
    clapTrap2.takeDamage(3);

    printValues(clapTrap);
    printValues(clapTrap2);

    clapTrap2.beRepaired(2);
    
    printValues(clapTrap2);

    clapTrap.guardGate();
    return (0);
}