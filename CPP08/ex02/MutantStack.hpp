#pragma once 

# include <iostream>
# include <stack>
# include <iterator>
# include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		MutantStack(void);
		~MutantStack(void);
		MutantStack(const MutantStack<T> &src);

        MutantStack<T>& operator=(const MutantStack<T> &src);

		// The 'c' in here is a internal container which defined in 
		// stack class as protected so we can use it from deriven classes
		// to override cotainer methods.

		// Simplified version of stack class:
		// template <typename T, typename Container = std::deque<T>>
		// class stack {
		// 	protected:
    	// 		Container c;
		// 	public:
    			// stack member functions
		// };
	
		iterator begin()
		{ return this->c.begin(); }

        const_iterator begin() const
		{ return this->c.begin(); }

        iterator end()
		{ return this->c.end(); }

        const_iterator end() const
		{ return this->c.end(); }
};

template <typename T>
MutantStack<T>::MutantStack(void) {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &source)
{ *this = source; }

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T> &source)
{
    if (this != &source){
        std::stack<T>::operator=(source);
    }
    return *this;
}
