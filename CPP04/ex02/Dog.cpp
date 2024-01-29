#include "Dog.hpp"


// Orthodox canonical requirements
Dog::Dog(void) : AAnimal("Dog")
{
	std::cout << "Dog Default constructor called!" << std::endl;
	this->name = "Max";
	this->brain = new Brain;
}

Dog::Dog(std::string name) : AAnimal("Dog")
{
	std::cout << "Dog constructor called!" << std::endl;
	this->name = name;
	this->brain = new Brain;
}

Dog::Dog(const Dog& cpy) : AAnimal(cpy)
{
	std::cout << "Dog copy constructor called!" << std::endl;
	this->brain = new Brain;
	*this = cpy;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called!" << std::endl;
	delete this->brain;
}

Dog& Dog::operator=(const Dog& elem)
{
	std::cout << "Dog '=' operator called!" << std::endl; 
	this->name = elem.name;
	this->type = elem.type;
	this->brain = new Brain(*(elem.brain));

	return (*this);
}


// Member function
void Dog::makeSound(void) const { std::cout << "Barkk!" << std::endl; }


// Getter and Setter
std::string Dog::getName(void) { return (this->name); }

Brain* Dog::getBrain(void) const { return (this->brain); }

void Dog::setName(std::string name) { this->name = name; }