#include "Span.hpp"

int main(void)
{
	// Subject test
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl;

	
	// More
	Span elem1(4);
	elem1.addNumber(10);
	elem1.addNumber(8);
	elem1.addNumber(-2);

	Span elem2(elem1);
	elem2.addNumber(-3);
	std::cout << "longestSpan of elem2: " << elem2.longestSpan() << std::endl;
	std::cout << "shortestSpan of elem2: " << elem2.shortestSpan() << std::endl << std::endl;

	try{
		elem2.addNumber(100);
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}

	Span elem3(1);
	elem3.addNumber(1);
	try{
		elem3.longestSpan();
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}

	Span elem4(10001);
	elem4.fillSpan();
	std::cout << "\nlongestSpan of elem4: " << elem4.longestSpan() << std::endl;
	std::cout << "shortestSpan of elem4: " << elem4.shortestSpan() << std::endl;
}