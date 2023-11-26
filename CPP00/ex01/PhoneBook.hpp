#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

class PhoneBook
{
	private:
			Contact contacts[8];
	public:
			PhoneBook(void);

			void add(int &index);
			void search(int index);
};
#endif