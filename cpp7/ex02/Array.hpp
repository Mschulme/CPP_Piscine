#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>
#include <ostream>
#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
	private:
		unsigned int size_array;
		T* data;
	
	public:
		Array(void);
		Array(unsigned int size);
		Array(const Array& other);
		~Array(void);
   	 	Array	&operator=(const Array<T> &other);

		T	&operator[](unsigned int i);
		const T& operator[](unsigned int i) const;
		unsigned int	size(void) const; 
};

#include "Array.tpp"

#endif
