#pragma once 

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

		iterator begin()
		{ return this->container.begin(); }

        const_iterator begin() const
		{ return this->container.begin(); }

        iterator end()
		{ return this->container.end(); }

        const_iterator end() const
		{ return this->container.end(); }
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
