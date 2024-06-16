# pragma once

#include <iostream>
#include <stack>

class RPN
{
	private:
		std::stack<int> notationStack;
		std::string input;
		int result;

	public:
		// Constructors, Destructor and Assignment Operater Overload
		RPN(std::string input);
		RPN(const RPN & src);
		~RPN(void);
		RPN & operator=(const RPN & elem);

		// Member Functions
		void calculate(void);
};	