#pragma once

# include <iostream>

struct Data
{
	int value;
};

class Serializer
{
	private:
		Serializer(void);
		Serializer(Serializer const & elem);
		~Serializer(void);

	public:
		Serializer & operator=(Serializer const & elem);

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};