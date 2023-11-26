#include "replace.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Missing argument!" << std::endl;
		return (1);
	}

	std::string fileName = av[1];
	std::string target = av[2];
	std::string replace = av[3];

	std::ifstream fileToRead(fileName);
	if (!fileToRead.is_open())
	{
		std::cout << "There is no such file as " << fileName << std::endl;
		return (2);
	}

	std::ofstream fileToWrite(fileName + ".replace");
	if (!fileToWrite.is_open())
	{
		std::cout << "The " << fileName << ".replace file could not be created." << std::endl;
		return (3);
	}

	std::string buffer;
	std::string wholeFile = "";
	while (std::getline(fileToRead, buffer))
		wholeFile += (buffer + "\n");
	
	size_t location = 0;
	while ((location = wholeFile.find(target, location)) != std::string::npos)
	{
		wholeFile.erase(location, target.length());
		wholeFile.insert(location, replace);
		location += target.length();
	}

	fileToWrite << wholeFile;
}