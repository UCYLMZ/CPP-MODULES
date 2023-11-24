#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	for (int i = 0; i < 8; i++)
		this->contacts[i] = Contact();
}

int checkPhone(std::string buffer)
{
	if (buffer[0] != '+' && !isdigit(buffer[0]))
		return (0);
	for (int i = 1; buffer[i]; i++)
	{
		if (!isdigit(buffer[i]))
			return (0);
	}
	return (1);
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
				{
					while (!checkPhone(buffer))
					{
						std::cout << "*** The Phone Number must be number or started with '+' operator!\n";
						std::cout << "\nEnter a valid Phone number for your contact :\n";
						getline(std::cin, buffer);
					}
					this->contacts[absIndex].setPhoneNumber(buffer);
				}
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
	int	length = str.length();

	if (length > 10)
	{
		for (i = 0; i < 9; i++)
			std::cout << str[i];
		std::cout << ".";
	}
	else
	{
		while (length++ < 10)
			std::cout << " ";
		std::cout << str;
	}
}

void	printAllContacts(Contact contacts[])
{
	for (int i = 0; i < 8; i++)
	{
		if (contacts[i].getFirstName() == "")
			break ;
		std::cout << std::setw(9);
		std::cout << i + 1 << "|";
		printColumn(contacts[i].getFirstName());
		std::cout << "|";
		printColumn(contacts[i].getLastName());
		std::cout << "|";
		printColumn(contacts[i].getNickName());
		std::cout << std::endl;
	}
}

std::string getId(int index)
{
	std::string buffer = "";

	std::cout << "\nPlease enter a valid ID for more information:\n";
	getline(std::cin, buffer);
	if (buffer == "")
		return (getId(index));
	for (int i = 0; buffer[i]; i++)
	{
		if (!isdigit(buffer[i]) || buffer == "")
		{
			std::cout << "*** The value must be number!\n";
			return (getId(index));
		}
	}
	if (stoi(buffer, 0, 10) > index || stoi(buffer, 0, 10) > 8)
	{
		std::cout << "*** The value must be in range!\n";
		return (getId(index));
	}
	return (buffer);
}

void PhoneBook::search(int index)
{
	std::string	buffer;
	int			id;

	std::cout << "\nRecords on Your PhoneBook:\n";
	std::cout << "    ID    " << " FIRST N. " << "  LAST N.  ";
	std::cout << "  NICK N.  " << std::endl;
	printAllContacts(this->contacts);
	id = stoi(getId(index), 0, 10) - 1;
	std::cout << std::endl << "First Name    : " << contacts[id].getFirstName() << std::endl;
	std::cout << "Last Name     : " << contacts[id].getLastName() << std::endl;
	std::cout << "Nick Name     : " << contacts[id].getNickName() << std::endl;
	std::cout << "Phone Number  : " << contacts[id].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[id].getDarkestSecret() << std::endl;
}
