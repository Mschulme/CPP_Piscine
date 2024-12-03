#include <vector>
#include <iostream>
#include <iterator>
#include <stdexcept>

class Span
{
	private:
		unsigned int N;
		std::vector<int> data;

	public:
		Span(unsigned int N);

		void addNumber(int num);
		void addRandomNumbers(int count);

		template<typename Iterator>
		void addNumbers(Iterator begin, Iterator end)
		{
			while (begin != end)
			{
				addNumber(*begin);
				++begin;
			}
		}

		int shortestSpan() const;
		int longestSpan() const;
};


