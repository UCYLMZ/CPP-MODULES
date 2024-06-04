#pragma once
#include <iostream>
#include <exception>
#include <list>

class Span
{
	private:
		const unsigned int N;
		std::list<int> list;
	
	public:
		Span(unsigned int N);
		Span(const Span & src);
		~Span(void);

		Span & operator=(const Span & src);

		void addNumber(const int elem);
		int longestSpan(void);
		int shortestSpan(void);
		void fillSpan(void);

		class ListIsEmptyException : public std::exception{
            public:
                virtual const char* what() const throw();
        };

		class TheListAlreadyFullException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
};