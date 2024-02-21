#include "Serializer.hpp"


// Constructors, Destructor and Operator Overload
Serializer::Serializer(void) { std::cout << "Serializer Default Constructor!" << std::endl; }

Serializer::Serializer(Serializer const & elem)
{
	std::cout << "Serializer Copy Constructor!" << std::endl;
	*this = elem;
}

Serializer::~Serializer(void) { std::cout << "Serializer Destructor Called!" << std::endl; }

Serializer & Serializer::operator=(Serializer const & elem) 
{
	std::cout << "Serializer '=' Operator!" << std::endl;
	(void)elem;
	return (*this);
}

// Member Functions
uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t result = reinterpret_cast<uintptr_t>(ptr);
	return (result);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* result = reinterpret_cast<Data *>(raw);
	return (result);
}
