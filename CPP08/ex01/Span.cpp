#include "Span.hpp"

// Constructors, Destructor and Operator Overload
Span::Span(unsigned int N) : N(N) {};

Span::Span(const Span & src) : N(src.N)
{ *this = src; };

Span::~Span(void) {};

Span & Span::operator=(const Span & src)
{
	this->list.clear();
	for(std::list<int>::const_iterator iter = src.list.begin(); iter != src.list.end(); iter++)
	{
		try{
			this->addNumber(*iter);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}		
	}
	return (*this);
};


// Member Functions
void Span::addNumber(const int elem)
{
	if (this->N <= this->list.size())
		throw Span::TheListAlreadyFullException();
	this->list.push_back(elem);
};

int Span::longestSpan(void)
{
	if (this->N <= 1)
		throw Span::ListIsEmptyException();
	std::list<int> temp = this->list;
	temp.sort();
	return (temp.back() - temp.front());
};

int Span::shortestSpan(void)
{
	if (this->N <= 1)
		throw Span::ListIsEmptyException();

	std::list<int> temp = this->list;
	temp.sort();

	int min = INT_MAX;
	int previous = temp.front();
	for (std::list<int>::iterator iter = std::next(temp.begin()); iter!= temp.end(); iter++)
	{
		if (*iter - previous < min)
			min = *iter - previous;
		previous = *iter;
	}
	return min;
}

void Span::fillSpan(void)
{
	srand(time(NULL));
	this->list.resize(this->N);
	for (std::list<int>::iterator iter = this->list.begin(); iter != this->list.end(); iter++)
		*iter = rand();
}


// Exception Classes Definitions
const char* Span::ListIsEmptyException::what() const throw()
{ return ("***Error: There is no range because of the size!"); }

const char* Span::TheListAlreadyFullException::what() const throw()
{ return ("***Error: Size of List in The Class is Already Full!"); }