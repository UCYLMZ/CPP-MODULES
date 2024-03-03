#pragma once

#include <iostream>

template <typename T>
void iter(T * address, unsigned int size, void (*func)(T & elem))
{
	for (unsigned int i = 0; i < size; i++)
		func(*(address + i));
}