#include "PhoneBook.hpp"

int main(void)
{
	int			index = 0;
	std::string command = "";
	PhoneBook	book;

	while (true)
	{
		std::cout << "\nCommands: ADD, SEARCH, EXIT" << std::endl;
		std::cout << "Enter a command to run :" << std::endl;
		getline(std::cin, command);
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
			book.add(index);
		else if (command == "SEARCH")
		{
			if (index == 0)
			{
				std::cout << "The PhoneBook is empty!" << std::endl;
				continue ;
			}
			book.search(index);
		}
		std::cout << index << std::endl;
	}
	return (0);
}