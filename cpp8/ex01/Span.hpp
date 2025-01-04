#include <ctime>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <stdexcept>

class Span
{
	private:
		unsigned int N;
		std::vector<int> data;

	public:
		Span();
		Span(unsigned int N);

		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int num);
		void addRandomNumbers(int count);

		template<typename Iterator>
		void addNumbers(Iterator begin, Iterator end)
		{
			size_t count = 0;
			for (Iterator it = begin; it != end; ++it)
			{
				++count;
			}
			
			if (count > (N - data.size()))
			{
				throw std::out_of_range("Not enough space to add all elements from range");
			}

			while (begin != end)
			{
				addNumber(*begin);
				++begin;
			}
		}

		int shortestSpan() const;
		int longestSpan() const;
};
