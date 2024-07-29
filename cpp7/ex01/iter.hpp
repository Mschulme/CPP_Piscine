#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstdlib>

template <typename T, typename Function>
void applyFunction(T array[], std::size_t size, Function f)
{
	try
	{
		for (std::size_t i = 0; i < size; ++i)
			array[i] = f(array[i]);
	}
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}

#endif
