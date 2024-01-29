#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	Animal *animCat = new Cat();
    std::cout << "-----------------------" << std::endl;
    Animal *animaldog = new Dog();
    std::cout << "-----------------------" << std::endl;
    delete animCat;
    std::cout << "-----------------------" << std::endl;
    delete animaldog;
    std::cout << "-----------------------" << std::endl;

    std::cout << "***Deep copy control" << std::endl;
    Dog dog;
    Dog dog2 = dog;
    std::cout << dog.getBrain() << std::endl;
    std::cout << dog2.getBrain() << std::endl;
	std::cout << "-----------------------" << std::endl;
    std::cout << "***Brain copy constructor and assignment" << std::endl;
    Brain a;
    Brain b(a);
    a = b;
    a.setIdeas("aaaa");
    b.setIdeas("bbbb");
    std::cout << (a.getIdeas()[99]) << std::endl;
    std::cout << (b.getIdeas()[21]) << std::endl;

	std::cout << "----------------------" << std::endl;
	Dog *dogA = new Dog;
	Dog *dogB = new Dog(*dogA);
	std::cout << "***Another Deep Copy Control" << std::endl;
	std::cout << dogA->getBrain() << std::endl;
	std::cout << dogB->getBrain() << std::endl;

	delete dogA;
	delete dogB;
	return 0;
}