
#include "PmergeMe.hpp"

bool isPositiveInteger(const char* str)
{
	while(*str != 0)
	{
		if(!isdigit(*str))
		{
			return false;
		}
		str++;
	}
	return (true);
}


std::vector<int> input_parsing_vector(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "Not enough arguments." << '\n';
		throw std::runtime_error("");
	}

	std::vector<int> A;
	std::map<int, int> freq;

	for(int i = 1; i < argc; ++i)
	{
		if(isPositiveInteger(argv[i]))
		{
			int num = atoi(argv[i]);
			freq[num]++;
			if(freq[num] > 1)
			{
				std::cout << "Input " << num << " is not unique." << '\n';
				throw std::runtime_error("");
			}
			else
			{
				A.push_back(num);
			}
		}
		else
		{
			std::cout << "Input " << argv[i] << " is not a positive integer." << '\n';
			throw std::runtime_error("");
		}
	}
	return (A);
}


std::deque<int> input_parsing_deque(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "Not enough arguments." << '\n';
		throw std::runtime_error("");
	}

	std::deque<int> A;
	std::map<int, int> freq;

	for(int i = 1; i < argc; ++i)
	{
		if(isPositiveInteger(argv[i]))
		{
			int num = atoi(argv[i]);
			freq[num]++;
			if(freq[num] > 1)
			{
				std::cout << "Input " << num << " is not unique." << '\n';
				throw std::runtime_error("");
			}
			else
			{
				A.push_back(num);
			}
		}
		else
		{
			std::cout << "Input " << argv[i] << " is not a positive integer." << '\n';
			throw std::runtime_error("");
		}
	}
	return (A);
}
