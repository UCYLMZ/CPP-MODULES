#include "RPN.hpp"

// Constructors, Destructor and Assignment Operator Overload
RPN::RPN(std::string input) : input(input) {};

RPN::RPN(const RPN & src) : input(src.input) { *this = src; };

RPN::~RPN(void) {};

RPN & RPN::operator=(const RPN & elem)
{
	this->input = elem.input;
	this->notationStack = elem.notationStack;
	this->result = elem.result;

	return (*this);
};


// Helper Functions
bool isOperator(char c)
{
    std::string operators = "+-*/";
    return operators.find(c) != std::string::npos;
}

bool checkInput(std::string input)
{
	int nbrCount = 0, optCount = 0;
	bool nbrFlag = false;

	for (int i = 0; input[i]; i++)
	{
		if (isdigit(input[i]))
		{
			if (nbrFlag == true)
			{
				std::cout << "Error\n";
				return false ;
			}
			nbrCount++;
			nbrFlag = true;
		}
		else
			nbrFlag = false;

		if (isOperator(input[i]))
			optCount++;
		else if (isspace(input[i]))
			continue ;
		else if (!isdigit(input[i]))
		{
			std::cout << "Error\n";
			return false ;
		}
	}
	if (nbrCount > 1 && nbrCount == optCount + 1)
		return true ;
	return false ;
};

int executeOperator(int a, int b, char opt)
{
	if (opt == '+')
		return a + b ;
	else if (opt == '-')
		return a - b ;
	else if (opt == '*')
		return a * b ;
	else
		return a / b ;
};


// Member Functions
void RPN::calculate(void)
{
	if (!checkInput(this->input))
		return ;

	for (int i = 0; this->input[i]; i++)
	{
		if (isdigit(this->input[i]))
			this->notationStack.push(static_cast<int>((int)this->input[i]) - 48);
		else if (isOperator(this->input[i]))
		{
			if (this->notationStack.size() < 2)
			{
				std::cout << "Error\n";
				return ;
			}
			else
			{
				int second = this->notationStack.top();
				this->notationStack.pop();
				int first = this->notationStack.top();
				this->notationStack.pop();
				this->notationStack.push(executeOperator(first, second, input[i]));
			}
		}
	}
	if (this->notationStack.size() != 1)
	{
		std::cout << "Error\n";
		return ;
	}
	this->result = this->notationStack.top();
	std::cout << result << std::endl;
}
