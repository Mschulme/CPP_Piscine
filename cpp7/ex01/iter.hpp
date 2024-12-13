#ifndef ITER_HPP
#define ITER_HPP

#include <vector>
#include <cstdlib>
#include <iostream>
#include <stdexcept>


template <typename T, typename Function>
void applyFunction(T array[], size_t size, Function f)
{
	try
	{
		for (size_t i = 0; i < size; ++i)
			array[i] = f(array[i]);
	}
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}

#endif
