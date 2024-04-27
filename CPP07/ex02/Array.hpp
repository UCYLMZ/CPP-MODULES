#pragma once

#include <iostream>

template <typename T> class Array
{
	private:
		T *array;
		unsigned int size;
	
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array & src);
		~Array(void);
		
		Array & operator=(const Array & src);
		T & operator[](int size);

		T * getArr(void);

		class OutOfBoundsException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
};


// Constructors, Destructor
template <typename T>
Array<T>::Array(void)
{
	this->array = new T[0];
	this->size = 0;
}


template <typename T>
Array<T>::Array(unsigned int size)
{
	this->array = new T[size];
	this->size = size;
}


template <typename T>
Array<T>::Array(const Array<T> & src)
{ *this = src; }


template <typename T>
Array<T>::~Array(void)
{ delete [] this->array; }


// Getter Funciton
template <typename T>
T * Array<T>::getArr(void)
{ return (this->array); }


// Operator Overload Functions
template <typename T>
Array<T> & Array<T>::operator=(const Array<T> & src)
{
	this->size = src.size;
	this->array = new T(this->size);
	for (unsigned int i = 0; i < this->size; i++)
		this->array[i] = src.array[i];
	return (*this);
}

template <typename T>
T& Array<T>::operator[](int i){
    if (i >= (int)this->size || i < 0)
        throw Array<T>::OutOfBoundsException();
    return array[i];
}


// Exception class
template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{ return "Index is out of bounds"; }