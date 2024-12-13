#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <cstdlib>
#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
	private:
		unsigned int size_array;
		T* data = NULL;
	
	public:
		// orthodox canonical form
		Array(void);
		Array(unsigned int size);
		Array(const Array& other);
		~Array(void);
   	 	T	&operator=(const Array<T> &other);

		// member functions
		T	&operator[](unsigned int i) const;
		unsigned int	size(void) const; 

};

#endif
