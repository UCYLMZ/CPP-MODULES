#include "BitcoinExchange.hpp"


// Constructors, Destructor and Assignment Operator Overload
BitcoinExchange::BitcoinExchange(void) {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange & src)
{ *this = src; };

BitcoinExchange::~BitcoinExchange(void) {};



// Helper Functions
std::string BitcoinExchange::removeSpaces(std::string str)
{
	// Erasing spaces from the begining and the end
	int i;
	for (i = 0; ::isspace(str[i]); i++);
	str.erase(0, i);

	for (i = str.size() - 1; ::isspace(str[i]); i--);
	str.erase(i + 1, str.size());

	return str;
}

bool BitcoinExchange::checkDay(int year, int month, int day)
{
    if (month < 1 || month > 12 || day < 1 || year < 1)
        return false;

    if (month == 2) {
        // Check for February
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            // Leap year
            return day <= 29;
        } else {
            // Non-leap year
            return day <= 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        // Months with 30 days
        return day <= 30;
    } else {
        // Months with 31 days
        return day <= 31;
    }
}

bool BitcoinExchange::checkDate(std::string date, std::string filename)
{
	int scoreCount = 0;
	for (std::string::iterator iter = date.begin(); iter != date.end(); iter++)
	{
		if (*iter == '-')
			scoreCount++;
		else if(!::isdigit(*iter))
		{
			std::cout << "Error: bad input => " + date + " in '" << filename << "'" << std::endl;
			return false;
		}
	}
	if (scoreCount != 2 || date.size() != 10)
	{
		std::cout << "Error: bad input => " + date + " in '" << filename << "'" << std::endl;
		return false;
	}
	int scorePos = date.find('-');

	std::string year = date.substr(0, scorePos);
	int y = static_cast<int>(std::stoi(year));

 	std::string month = date.substr(scorePos + 1, (date.find('-', scorePos + 1) - scorePos - 1));
	int m = static_cast<int>(std::stoi(month));

	scorePos = date.find('-', scorePos + 1);
	std::string day = date.substr(scorePos + 1, date.size() - scorePos - 1);
	int d = static_cast<int>(std::stoi(day));

	if (BitcoinExchange::checkDay(y, m, d) && year.size() == 4 && month.size() == 2 && day.size() == 2)
		return true;

	std::cout << "Error: bad input => " + date + " in '" << filename << "'" << std::endl;
	return false;
}

bool BitcoinExchange::checkRate(std::string rate, std::string filename)
{
	int dotCount = 0;
	for (std::string::iterator iter = rate.begin(); iter != rate.end(); iter++)
	{
		if (*iter == '.')
			dotCount++;
		else if (!::isdigit(*iter))
		{
			std::cout << "Error: not a positive number => " + rate + " in '" << filename << "'" << std::endl;
			return false;
		}
	}
	if (dotCount > 1)
	{
		std::cout << "Error: not a positive number => " + rate + " in '" << filename << "'" << std::endl;
		return false;
	}

	double r = static_cast<float>(std::stod(rate));
	if (filename != "data.csv" && (r > 1000 || r < 0 || rate.size() > 9))
	{
		std::cout << "Error: too large a number => " + rate + " in '" << filename << "'" << std::endl;
		return false;
	}
	return true;
}



// Memeber Functions
void BitcoinExchange::readDataBase(std::string fileName)
{
	std::ifstream fileToRead(fileName);
	if (!fileToRead)
		throw BitcoinExchange::FileOpenException();

	if (fileToRead.good())
	{
		std::string line;
		// Forwarding first line
		std::getline(fileToRead, line);

		// Loop through all file
		while (!fileToRead.eof() && std::getline(fileToRead, line))
		{
			int poss = line.find(',');
			std::string date = line.substr(0, poss);
			date = removeSpaces(date);

			std::string rate = line.substr(poss + 1);
			rate = removeSpaces(rate);

			if (BitcoinExchange::checkDate(date, fileName))
			{
				if (checkRate(rate, fileName))
				{
					this->dates.push_back(date);
					this->bitcoinMap[date] = static_cast<float>(std::stod(rate));
					// std::cout << "fromMap: " << date << " / " << this->bitcoinMap[date] << std::endl;;
				}
			}
		}
	}
	// for (std::list<std::time_t>::const_iterator iter = dates.begin(); iter != dates.end(); ++iter) {
    //     std::time_t t = *iter;
    //     std::tm* tm = std::localtime(&t);
    //     if (tm != nullptr)
	// 	{
	// 		std::string year = std::to_string((tm->tm_year + 1900));
	// 		std::string month = std::to_string((tm->tm_mon + 1));
	// 		if (month.size() == 1)
	// 			month = "0" + month;
	// 		std::string day =  std::to_string(tm->tm_mday);
	// 		if (day.size() == 1)
	// 			day = "0" + day;

	// 		std::string fulldate = year + "-" + month + "-" + day;

    //         std::cout << fulldate << " | " << this->bitcoinMap[fulldate] << std::endl;
    //     }
    // }
}

// Getters
std::list<std::string> BitcoinExchange::getDates(void)
{ return this->dates; }

std::map<std::string, float> BitcoinExchange::getMap(void)
{ return this->bitcoinMap; }


// Operator Overload Functions
BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & src)
{
	this->bitcoinMap = src.bitcoinMap;
	this->dates = src.dates;

	return (*this);
}

// Exception Classes
const char* BitcoinExchange::FileOpenException::what() const throw()
{ return ("Could not open file. "); }
