#include "Span.hpp"

int	main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	unsigned int Number_of_elements = 50000;
	Span sp_random = Span(Number_of_elements);
	sp_random.addRandomNumbers(Number_of_elements);

	std::cout << sp_random.shortestSpan() << std::endl;
	std::cout << sp_random.longestSpan() << std::endl;

	Span sp_iterator = Span(5);
	std::vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(4);
	numbers.push_back(5);
	sp_iterator.addNumbers(numbers.begin(), numbers.end());

	std::cout << sp_iterator.shortestSpan() << std::endl;
	std::cout << sp_iterator.longestSpan() << std::endl;

	return (EXIT_SUCCESS);
}
