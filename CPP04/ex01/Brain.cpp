#include "Brain.hpp"


// constructors, destructor and assingment operator overload
Brain::Brain(void) { std::cout << "Brain Default contructor called!" << std::endl; }

Brain::Brain(Brain& elem)
{
	std::cout << "Brain Copy contructor called!" << std::endl;
	*this = elem;
}

Brain::~Brain(void) { std::cout << "Brain destructor called!" << std::endl; }

Brain& Brain::operator=(const Brain& elem)
{
	std::cout << "Brain '=' operator called!" << std::endl;
	int i = -1;
	while (++i < 100)
		this->ideas[i] = elem.ideas[i];
	return (*this);
}

// Setter and Getter
std::string* Brain::getIdeas(void) { return (this->ideas); }

void	Brain::setIdeas(std::string idea)
{
	for(int i = 0; i < 100; i++)
		this->ideas[i] = idea;
}