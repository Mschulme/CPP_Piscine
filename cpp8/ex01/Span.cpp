#include "Span.hpp"


Span::Span() : N(0)
{
	std::cout << "Default constructor called." << std::endl;
}


Span::Span(unsigned int N) : N(N)
{

	std::cout << "Parametrized constructor called." << std::endl;
}


Span::Span(const Span &other) : N(other.N), data(other.data)
{
	// N and data are copied from other
}


Span &Span::operator=(const Span &other)
{
	if (this != &other) {
		this->N = other.N;
		this->data = other.data;
	}
	return *this;
}


Span::~Span()
{
	std::cout << "Destructor called." << std::endl;
}


void	Span::addNumber(int num)
{
	if (data.size() < N)
	{
		data.push_back(num);
	} else 
	{
		throw std::out_of_range("Span is full.");
	}
}


void	Span::addRandomNumbers(int count)
{
	if (static_cast<unsigned int>(count) > N -data.size())
	{
		throw std::out_of_range("Not enough space to add all random numbers");
	}
	for (int i = 0; i < count; ++i)
	{
		addNumber(std::rand() % 100000000);
	}
}


int	Span::shortestSpan() const
{
	if (data.size() < 2)
	{
		throw std::logic_error("Need at least 2 elements to compute span.");
	}
	std::vector<int> sortedData = data;
	std::sort(sortedData.begin(), sortedData.end());

	int shortest_distance = sortedData[1] - sortedData[0];
	for (size_t i = 2; i < sortedData.size(); ++i)
	{
		int diff = sortedData[i] - sortedData[i - 1];
		if (diff < shortest_distance)
		{
			shortest_distance = diff;
		}
	}
	return (shortest_distance);
}


int	Span::longestSpan() const
{
	if (data.size() < 2)
	{
		throw std::logic_error("Need at least 2 elements to compute span.");
	}

	int minElement = *std::min_element(data.begin(), data.end());
	int maxElement = *std::max_element(data.begin(), data.end());
	
	return (maxElement - minElement);
}
