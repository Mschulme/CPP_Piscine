#include "Span.hpp"


int	main(void)
{
	std::srand((unsigned)std::time(0));

	try{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		unsigned int Number_of_elements = 1000;
		Span sp_random = Span(Number_of_elements);
		sp_random.addRandomNumbers(Number_of_elements);

		std::cout << sp_random.shortestSpan() << std::endl;
		std::cout << sp_random.longestSpan() << std::endl;
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

	return (EXIT_SUCCESS);
}
