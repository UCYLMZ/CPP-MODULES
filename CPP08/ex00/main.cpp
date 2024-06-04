#include "easyfind.hpp"
#include <vector>
#include <list>
#include <set>
#include <deque>


int main(void)
{
	// list
	std::cout << "\n### LIST ###" << std::endl;
	try
	{
		std::list<int> list;
		list.push_back(1);
		list.push_back(3);
		list.push_back(5);
		list.push_back(3);
		list.push_back(7);
		list.push_back(9);

		std::cout << "is '3' in list: " << *easyfind(list, 3) << std::endl;
		std::cout << "is '2' in list: " << *easyfind(list, 2) << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// vector
	std::cout << "\n\n### VECTOR ###" << std::endl;
	try
	{
		std::vector<int> vector;
		vector.push_back(1);
		vector.push_back(3);
		vector.push_back(5);
		vector.push_back(3);
		vector.push_back(7);
		vector.push_back(9);

		std::cout << "is '3' in vector: " << *easyfind(vector, 3) << std::endl;
		std::cout << "is '2' in vector: " << *easyfind(vector, 2) << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// set
	std::cout << "\n\n### SET ###" << std::endl;
	try
	{
		std::set<int> set;
		set.insert(1);
		set.insert(3);
		set.insert(5);
		set.insert(3);
		set.insert(7);
		set.insert(9);

		std::cout << "is '3' in set: " << *easyfind(set, 3) << std::endl;
		std::cout << "is '2' in set: " << *easyfind(set, 2) << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// deque
	std::cout << "\n\n### DEQUE ###" << std::endl;
	try
	{
		std::deque<int> deque;
		deque.push_back(1);
		deque.push_back(3);
		deque.push_back(5);
		deque.push_back(3);
		deque.push_back(7);
		deque.push_back(9);

		std::cout << "is '3' in deque: " << *easyfind(deque, 3) << std::endl;
		std::cout << "is '2' in deque: " << *easyfind(deque, 2) << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}