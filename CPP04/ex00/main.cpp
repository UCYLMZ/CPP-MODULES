#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	// subject tests
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
    meta->makeSound();
	delete meta;
	delete j;
	delete i;
	std::cout << std::endl;

	// additional test on subject
	const WrongAnimal* wrong = new WrongCat();
	std::cout << "Here it comes!" << std::endl;
	wrong->makeSound();
	delete wrong;
	std::cout << std::endl;

	// copy constructor test
	Dog* dog1 = new Dog("Benjamin");
	Dog* dog2 = new Dog(*dog1);
	std::cout << "dog2 name: " << dog2->getName() << std::endl;
	delete dog1;
	delete dog2;
	std::cout << std::endl;

	// Assignment operator
	Dog dog3("Achiles");
	Dog dog4;
	std::cout << "dog4 name: " << dog4.getName() << std::endl;
	dog4 = dog3;
	std::cout << "dog4 name: " << dog4.getName() << std::endl << std::endl;

	return 0;
}