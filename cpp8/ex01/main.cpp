#include "Span.hpp"


int	main(void)
{
	std::srand((unsigned)std::time(0));

	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		unsigned int Number_of_elements = 1000000;
		Span sp_random = Span(Number_of_elements);
		sp_random.addRandomNumbers(Number_of_elements);

		std::cout << sp_random.shortestSpan() << std::endl;
		std::cout << sp_random.longestSpan() << std::endl;


		std::vector<int> range_of_values(5000, 1);
		range_of_values[4999] = 42;
		Span sp_range = Span(5000);
		sp_range.addNumbers(range_of_values.begin(), range_of_values.end());

		std::cout << sp_range.shortestSpan() << std::endl;
		std::cout << sp_range.longestSpan() << std::endl;

	}
	catch (const std::out_of_range &e)
	{
		std::cerr << "Out_of_range error: " << e.what() << std::endl;
	}
	catch (const std::logic_error &e)
	{
		std::cerr << "Logic_error: " << e.what() << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << "Runtime_error: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "An unknown exception occurred." << std::endl;
	}


	try
	{
		Span sp_one_element = Span(1);
		sp_one_element.addNumber(5);
		std::cout << sp_one_element.shortestSpan() << std::endl;
	}
	catch (const std::logic_error &e)
	{
		std::cerr << "Logic_error: " << e.what() << std::endl;
	}
	return (EXIT_SUCCESS);
}
