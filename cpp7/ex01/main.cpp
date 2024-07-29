#include "iter.hpp"

int	increment(int x)
{
	return (x + 5);
}

int power(int x)
{
	return (x * x);
}

int main()
{
	int* array_int = new int[10];
	for (size_t i = 0; i < 10; i++)
		array_int[i] = i;

	size_t number_of_elements = 10;

	std::cout << "Input data: ";
	for (size_t i = 0; i < number_of_elements; ++i)
		std::cout << array_int[i] << ' ';
	std::cout << std::endl;

	applyFunction(array_int, number_of_elements, increment);
	for (size_t i = 0; i < number_of_elements; ++i)
		std::cout << array_int[i] << ' ';
	std::cout << std::endl;

	applyFunction(array_int, number_of_elements, power);
	for (size_t i = 0; i < number_of_elements; ++i)
		std::cout << array_int[i] << ' ';
	std::cout << std::endl;

	return (EXIT_SUCCESS);
}
