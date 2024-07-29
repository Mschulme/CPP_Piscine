#include "Array.tpp"

// Orthodox canoncial form

template <class T>
Array<T>::Array(void)
{
	try
	{
		size_array = 0;
		data = new T[0]();
	}
	catch(const std::bad_alloc &e)
	{
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
	}
}


template <class T>
Array<T>::Array(unsigned int size)
{
	try
	{
		size_array = size;
		data = new T[size]();
	}
	catch(const std::bad_alloc &e)
	{
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
	}
}


template <class T>
Array<T>::Array(const Array<T> &other)
{
	size_array = other.size_array;
	data = new T[size_array];
	for (unsigned int i = 0; i < size_array; ++i)
	{
		data[i] = other.data[i];
	}
}


template<class T>
Array<T>::~Array(void)
{
	delete[] data;
}

template <class T>
T	&Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		delete[] data;
		size_array = other.size_array;
		data = new T[size_array];
		for (unsigned int i = 0; i < size_array; ++i)
		{
			data[i] = other.data[i];
		}
	}
	return *this;
}



// member functions 

template <class T>
unsigned int	Array<T>::size(void) const
{
	return (size_array);
}

// Index operator

template <class T>
T	&Array<T>::operator[](unsigned int index) const
{
	if (index >= size_array)
	{
		std::cout << "Array index out of bound, exiting";
		exit(0);
	}
	return data[index];
}
