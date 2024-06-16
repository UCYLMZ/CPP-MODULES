#include "BitcoinExchange.hpp"

std::string getKey(std::string time, std::list<std::string> list)
{
	std::string backup;

	for (std::list<std::string>::iterator it = list.begin(); it != list.end(); it++)
	{
		if (*it >= time || it == list.end())
		{
			if (time == *it || it == list.end())
				backup = *it;
			break ;
		}
		backup = *it;
	}

	return backup;
}

void printExchange(std::string fileName, BitcoinExchange & dataBase)
{
	std::map<std::string, float> dataBaseMap = dataBase.getMap();

	std::ifstream fileToRead(fileName);
	if (!fileToRead)
		throw BitcoinExchange::FileOpenException();

	if (fileToRead.good())
	{
		std::cout << "   date   |   value\n";
		std::string line;
		// Forwarding first line
		std::getline(fileToRead, line);

		// Loop through all file
		while (!fileToRead.eof() && std::getline(fileToRead, line))
		{
			int poss = line.find('|');
			std::string date = line.substr(0, poss);
			date = BitcoinExchange::removeSpaces(date);

			std::string rate = line.substr(poss + 1);
			rate = BitcoinExchange::removeSpaces(rate);

			if (BitcoinExchange::checkDate(date, fileName))
			{
				if (BitcoinExchange::checkRate(rate, fileName))
				{
					std::string key = getKey(date, dataBase.getDates());
					float exchangeRate = dataBaseMap[key];
					float value = static_cast<float>(stof(rate));
					std::cout << date << " => " << value << " = " << value * exchangeRate << std::endl;
				}
			}
		}
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: Usage of Program (./BitcoinExchange 'file_to_read').\n";
		return (1);
	}

	// Creating database object
	BitcoinExchange dataBase;
	dataBase.readDataBase("data.csv");

	printExchange(av[1], dataBase);
}