#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); 
	j->makeSound();

	// Abstract Class
	// const Animal* meta = new AAnimal();
    // meta->makeSound();
	// delete meta;

	delete j;
	delete i;
	std::cout << std::endl;
	return 0;
}