#include "Span.hpp"

Span::Span(unsigned int N) : N(N) {}

void	Span::addNumber(int num)
{
	if(data.size() < N)
	{
		data.push_back(num);
	} else 
	{
		throw std::out_of_range("Span is full");
	}
}


void	Span::addRandomNumbers(int count)
{
	for(int i = 0; i < count; ++i)
	{
		addNumber(std::rand() % 100000000);
	}
}


int	Span::shortestSpan() const
{
	if(data.size() < 2)
	{
		throw std::logic_error("Need at least 2 elements to compute span.");
	}
	std::vector<int> sortedData = data;
	std::sort(sortedData.begin(), sortedData.end());
	int shortest_distance = sortedData[1] - sortedData[0];
	for(size_t i = 2; i < sortedData.size(); ++i) {
		shortest_distance = std::min(shortest_distance, sortedData[i] - sortedData[i-1]);
	}
	return (shortest_distance);
}


int	Span::longestSpan() const
{
	if(data.size() < 2)
	{
		throw std::logic_error("Need at least 2 elements to compute span.");
	}
	int minElement = *std::min_element(data.begin(), data.end());
	int maxElement = *std::max_element(data.begin(), data.end());
	return (maxElement - minElement);
}
