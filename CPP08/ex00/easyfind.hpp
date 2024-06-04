#pragma once

#include <iostream>

class NotFound : public std::exception{
	public:
		const char* what() const throw(){
			return "***Error: 'needle' not found";
		}
};

template <typename T>
typename T::iterator easyfind(T &highstack, int needle)
{
	typename T::iterator iter = std::find(highstack.begin(), highstack.end(), needle);
	if (iter == highstack.end())
		throw NotFound();
	else
		return iter;
}