#include "ScalarConverter.hpp"


// Constructors, Destructor and Assignment Operator Overload functions
ScalarConverter::ScalarConverter(void) {std::cout << "ScalarConverter Default Constructor called!" << std::endl; }

ScalarConverter::ScalarConverter(ScalarConverter const & elem)
{ (void)elem; std::cout << "ScalarConverter Copy Constructor called!" << std::endl; }

ScalarConverter::~ScalarConverter(void) { std::cout << "ScalarConverter Destructor called!" << std::endl; }

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & elem) { (void)elem; return (*this); }


// Member functions
void ScalarConverter::convert(std::string str)
{
	char type = getType(str);

	if ((type == 'f' || type == 'd' || type == 'i')
		&& static_cast<float>(stof(str)) == 0 && str[0] == '-')
		str.erase(0, 1);

	if (type == 0)
		std::cerr << "Wrong Argument Type Error!" << std::endl;
	else if (type == 'c')
		convertChar(str[0]);
	else if (type == 'i')
		convertInt(str);
	else if (type == 'f')
		convertFloat(str);
	else if (type == 'd')
		convertDouble(str);
	else if (type == 'n')
		convertNan();
	else if (type == '-' || type == '+')
		convertInf(str);
}

char ScalarConverter::getType(std::string str)
{
	unsigned long length = str.length();
	
	if (length == 1)
		return 'c';

	else if (str == "nan" || str == "nanf")
		return 'n';
	
	else if (str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
		return str[0];

	char typeFlag = 'i';
	unsigned long i = -1;
	if (str[0] == '-')
		i = 0;
	while (str[++i])
	{
		if (!isdigit(str[i]))
		{
			if (str[i] == '.' && typeFlag == 'i')
				typeFlag = 'd';
			else if (str[i] == 'f' && i == length - 1 && typeFlag == 'd')
				typeFlag = 'f';
			else
			{
				typeFlag = 0;
				break ;
			}
		}
	}
	return typeFlag;
}

void ScalarConverter::convertChar(char c)
{
	int iValue = static_cast<int>(c);
	char cValue = static_cast<char>(c);
	float fValue = static_cast<float>(c);
	double dValue = static_cast<double>(c);
	
	if (iValue > 31)
		std::cout << "char: '" << cValue << "'" << std::endl;
	else
		std::cout << "char: Non Displayable" << std::endl;
	std::cout << "int: " << iValue << std::endl;
	std::cout << "float: " << fValue << ".0f" << std::endl;
	std::cout << "double: " << dValue << ".0" << std::endl;
}

void ScalarConverter::convertInt(std::string str)
{
	int iValue = static_cast<int>(stoi(str));
	float fValue = static_cast<float>(stof(str));
	double dValue = static_cast<double>(stod(str));

	if (iValue <= 255 && iValue >= 0)
	{
		char cValue = static_cast<char>(iValue);
		if (iValue < 32)
			std::cout << "char: Non Displayable" << std::endl;
		else
			std::cout << "char: '" << cValue << "'" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << iValue << std::endl;
	std::cout << "float: " << fValue << ".0f" << std::endl;
	std::cout << "double: " << dValue << ".0" << std::endl;
}

void ScalarConverter::convertFloat(std::string str)
{
	int floatFlag = 0;
	for (unsigned long i = 0; i < str.length(); i++)
	{
		if (str[i] == '.')
		{
			for (unsigned long j = i + 1; str[j] != 'f'; j++)
			{
				if (str[j] != '0')
					floatFlag = 1;
			}
		}
	}
	float fValue = static_cast<float>(stof(str));
	int iValue = static_cast<int>(stoi(str));
	double dValue = static_cast<double>(stod(str));
	if (iValue <= 255 && iValue >= 0 && !floatFlag)
	{
		char cValue = static_cast<char>(fValue);
		if (iValue < 32)
			std::cout << "char: Non Displayable" << std::endl;
		else
			std::cout << "char: '" << cValue << "'" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << iValue << std::endl;
	std::cout << "float: " << fValue;
	if (!floatFlag)
		std::cout << ".0";
	std::cout << 'f' << std::endl;
	std::cout << "double: " << dValue;
	if (!floatFlag)
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::convertDouble(std::string str)
{
	int floatFlag = 0;
	for (unsigned long i = 0; i < str.length(); i++)
	{
		if (str[i] == '.')
		{
			for (unsigned long j = i + 1; str[j] != '\0'; j++)
			{
				if (str[j] != '0')
					floatFlag = 1;
			}
		}
	}
	float fValue = static_cast<float>(stof(str));
	int iValue = static_cast<int>(stoi(str));
	double dValue = static_cast<double>(stod(str));
	if (iValue <= 255 && iValue >= 0 && !floatFlag)
	{
		char cValue = static_cast<char>(fValue);
		if (iValue < 32)
			std::cout << "char: Non Displayable" << std::endl;
		else
			std::cout << "char: '" << cValue << "'" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << iValue << std::endl;
	std::cout << "float: " << fValue;
	if (!floatFlag)
		std::cout << ".0";
	std::cout << 'f' << std::endl;
	std::cout << "double: " << dValue;
	if (!floatFlag)
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::convertNan(void)
{
	float f = std::numeric_limits<float>::quiet_NaN();
	double d = std::numeric_limits<double>::quiet_NaN();

	std::cout << "char: " << "Impossible" << std::endl;
	std::cout << "int: " << "Impossible" << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertInf(std::string str)
{
	float f = std::numeric_limits<float>::infinity();
	double d = std::numeric_limits<double>::infinity();
	if (str[0] == '-')
	{
		f *= -1;
		d *= -1;
	}
	std::cout << "char: " << "Impossible" << std::endl;
	std::cout << "int: " << "Impossible" << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}