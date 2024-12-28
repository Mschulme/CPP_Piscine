#include "iter.hpp"


int power(int x)
{
	return (x * x);
}


int main(void)
{
	try
	{
		size_t number_of_elements = 10;
		std::vector<int> array_int(number_of_elements);
		for (size_t i = 0; i < number_of_elements; i++)
		{
			array_int[i] = static_cast<int>(i);
		}

		std::cout << "Input data: ";
		for (size_t i = 0; i < number_of_elements; ++i)
		{
			std::cout << array_int[i] << ' ';
		}
		std::cout << std::endl;

		// Apply power function
		std::cout << "Applying power function (square each element):" << std::endl;
		applyFunction(&array_int[0], number_of_elements, power);

		std::cout << "After power: ";
		for (size_t i = 0; i < number_of_elements; ++i)
		{
			std::cout << array_int[i] << ' ';
		}
		std::cout << std::endl;

		// Increment all values by one
		std::cout << "Applying increment function:" << std::endl;
		applyFunction(&array_int[0], number_of_elements, addOne<int>);

		std::cout << "After increment: ";
		for (size_t i = 0; i < number_of_elements; ++i)
		{
			std::cout << array_int[i] << ' ';
		}
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "An exception occurred: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	catch (...)
	{
		std::cerr <<  "An unknown exception occurred." << std::endl;
		return EXIT_FAILURE;
	}

	return (EXIT_SUCCESS);
}
