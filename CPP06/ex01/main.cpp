#include "Serializer.hpp"

int main(void)
{
	Data *ptr = new Data;
	ptr->value = 42;

	std::cout << "ptr adress: " << ptr << std::endl;
	std::cout << "ptr->value: " << ptr->value << std::endl << std::endl;

	ptr = Serializer::deserialize(Serializer::serialize(ptr));

	std::cout << "ptr adress: " << ptr << std::endl;
	std::cout << "ptr->value: " << ptr->value << std::endl;
}