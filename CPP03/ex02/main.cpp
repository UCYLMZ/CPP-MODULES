#include "FragTrap.hpp"

void printValues(ClapTrap clapTrap)
{
    std::cout << "\nName: " + clapTrap.getName() << "\nenergyPoints: " << clapTrap.getEnergyPoint()
            << "\nhitPoints: " << clapTrap.getHitPoints() << std::endl << std::endl;
}

int main()
{
    FragTrap fragTrap("utku");

    FragTrap fragTrap2("can");

    printValues(fragTrap);
    printValues(fragTrap2);

    fragTrap.attack("can");
    fragTrap2.takeDamage(30);

    printValues(fragTrap);
    printValues(fragTrap2);

    fragTrap2.beRepaired(2);

    fragTrap2 = fragTrap;
    
    printValues(fragTrap2);

    fragTrap.highFiveGuys();
    return (0);
}