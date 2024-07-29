#include "PmergeMe.hpp"

/*
 ./PmergeMe `shuf -i 1-30 -n 30 | tr "\n" " "`
*/

int counter = 0;

double worst_case_number_of_comparison(double n)
{
    return n * std::ceil(log2(0.75 * n)) - std::floor(pow(2, std::floor(log2(6 * n))) / 3.0) + std::floor(log2(6 * n) / 2.0);	
}

int main(int argc, char *argv[])
{
	try
	{
		// Input parsing
		std::vector<int> Unsorted_vector = input_parsing_vector(argc, argv);
		unsigned int length_of_vector = Unsorted_vector.size();

		std::deque<int> Unsorted_deque = input_parsing_deque(argc, argv);
		unsigned int length_of_deque = Unsorted_deque.size();

		// Print the unsorted list
		std::cout << "Unsorted list: \n";
		for (unsigned int i=0; i < length_of_vector; ++i)
			std::cout << Unsorted_vector[i] << ' ';

		std::cout << '\n' << "\n---Performance benchmarking---" << '\n';

		// std::vector

		clock_t start = clock();
		std::vector<int>sorted_vector = merge_insertion_sort_vector(Unsorted_vector);
		clock_t end = clock();
		double runtime = 1000.0 * (end - start) / CLOCKS_PER_SEC;
		std::cout << '\n' << "Sorted list - MergeInsertion - std::vector \n";
		for (unsigned int i=0; i < length_of_vector; ++i)
			std::cout << sorted_vector[i] << ' ';
		std::cout << '\n' << "Time to process a range of " << length_of_vector << " elements: " << runtime << " ms" << '\n';
		std::cout << "Number of comparison for " << length_of_vector << " elements is " << counter << " and is less than or equal as worst case bound of " << worst_case_number_of_comparison(length_of_vector) << " comparison.\n";

		// std::deque
		counter = 0;
		start = clock();
		std::deque<int>sorted_deque = merge_insertion_sort_deque(Unsorted_deque);
		end = clock();
		runtime = 1000.0 * (end - start) / CLOCKS_PER_SEC;
		std::cout << '\n' << "Sorted list - MergeInsertion - std::deque \n";
		for (unsigned int i=0; i < length_of_vector; ++i)
			std::cout << sorted_deque[i] << ' ';
		std::cout << '\n' << "Time to process a range of " << length_of_deque << " elements: " << runtime << " ms" << '\n';
		std::cout << "Number of comparison for " << length_of_vector << " elements is " << counter << " and is less than or equal to the worst case bound of " << worst_case_number_of_comparison(length_of_vector) << " comparison.\n";
	}
	catch(const std::runtime_error& e)
	{
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
