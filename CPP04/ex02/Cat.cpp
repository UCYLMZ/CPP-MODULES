#include "Cat.hpp"


// Orthodox canonical requirements
Cat::Cat(void) : AAnimal("Cat")
{
	std::cout << "Cat Default constructor called!" << std::endl;
	this->name = "Garfield";
	this->brain = new Brain;
}

Cat::Cat(std::string name) : AAnimal("Cat")
{
	std::cout << "Cat constructor called!" << std::endl;
	this->name = name;
	this->brain = new Brain;
}

Cat::Cat(const Cat& cpy) : AAnimal(cpy)
{
	std::cout << "Cat copy constructor called!" << std::endl;
	this->brain = new Brain;
	*this = cpy;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called!" << std::endl;
	delete this->brain;
}

Cat& Cat::operator=(const Cat& elem)
{
	this->name = elem.name;
	this->type = elem.type;
	(this->brain) = new Brain(*(elem.brain));

	return (*this);
}


// Member function
void Cat::makeSound(void) const { std::cout << "Meoww!" << std::endl; }


// Getter and Setter
std::string Cat::getName(void) { return (this->name); }

Brain* Cat::getBrain(void) const { return (this->brain); }

void Cat::setName(std::string name) { this->name = name; }