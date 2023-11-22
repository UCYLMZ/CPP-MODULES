#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	for (int i = 0; i < 8; i++)
		this->contacts[i] = Contact();
}

void PhoneBook::add(int &index)
{
	int 		absIndex = index % 8;
	std::string	buffer = "";
	std::string	areas[] = {"First Name", "Last Name", "Nick Name",
							"Phone Number", "Darkest Secret"};

	std::cout << "\nYou are registering a new contact on your phonebook.\n";

	for (int i = 0; i < 5; i++)
	{
		while (true)
		{
			std::cout << "Enter a valid " << areas[i] << " value for your contact :" << std::endl;
			getline(std::cin, buffer);
			if (buffer != "")
			{
				if (i == 0)
					this->contacts[absIndex].setFirstName(buffer);
				else if (i == 1)
					this->contacts[absIndex].setLastName(buffer);
				else if (i == 2)
					this->contacts[absIndex].setNickName(buffer);
				else if (i == 3)
					this->contacts[absIndex].setPhoneNumber(buffer);
				else if (i == 4)
					this->contacts[absIndex].setDarkestSecret(buffer);
				break ;
			}
		}
	}
	std::cout << "The contact has been registered." << std::endl;
	index++;
}

void	printColumn(std::string str)
{
	int i;

	if (str.length() > 10)
	{
		for (i = 0; i < 9; i++)
			std::cout << str[i];
		std::cout << ".";
	}
	else
	{
		std::setw(10 - str.length());
		std::cout << str;
	}
}

void	printAllContacts(Contact contacts[])
{
	for (int i = 0; i < 8; i++)
	{
		std::setw(9);
		std::cout << i + 1 << "|";
		printColumn(contacts[i].getFirstName());
		std::cout << "|";
		printColumn(contacts[i].getLastName());
		std::cout << "|";
		printColumn(contacts[i].getNickName());
		std::cout << std::endl;
	}
}

void PhoneBook::search(int index)
{
	printAllContacts(this->contacts);
	// for (int i = 0; i < 8; i++)
	// {
	// 	if (i >= index)
	// 		break ;
	// 	std::cout << this->contacts[i].getFirstName() << std::endl;
	// 	std::cout << this->contacts[i].getLastName() << std::endl;
	// 	std::cout << this->contacts[i].getNickName() << std::endl;
	// 	std::cout << this->contacts[i].getPhoneNumber() << std::endl;
	// 	std::cout << this->contacts[i].getDarkestSecret() << std::endl;
	// }
}
