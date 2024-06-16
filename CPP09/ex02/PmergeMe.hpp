#include <iostream>
#include <deque>
#include <vector>
#include <chrono>

class PmergeMe
{
	private:
		double dequeTime;
		double vectorTime;
		std::deque<int> nbrsDeque;
		std::vector<int> nbrsVector;
	
	public:	
		// Constructors, Destructor and Assignment Operator Overload
		PmergeMe(void);
		PmergeMe(const PmergeMe & src);
		~PmergeMe(void);
		PmergeMe & operator=(const PmergeMe & elem);

		// Member Functions
		bool getNumbers(char **args);
		void sort(void);
		void printNumbers(void);
		void printInfos(void);
};