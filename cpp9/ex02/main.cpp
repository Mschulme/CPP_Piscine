#include "PmergeMe.hpp"
#include <ctime>
#include <cmath>
#include <vector>
#include <deque>
#include <iostream>
#include <stdexcept>

int counter;

static double my_log2(double x)
{
    return std::log(x) / std::log(2.0);
}


double worst_case_number_of_comparison(double n)
{
    return n * std::ceil(my_log2(0.75 * n))
           - std::floor(std::pow(2, std::floor(my_log2(6 * n))) / 3.0)
           + std::floor(my_log2(6 * n) / 2.0);
}

int main(int argc, char *argv[])
{
    try
    {
        // Input parsing
        std::vector<int> unsortedVector = input_parsing_vector(argc, argv);
        unsigned int lengthOfVector = (unsigned int)unsortedVector.size();

        std::deque<int> unsortedDeque = input_parsing_deque(argc, argv);
        unsigned int lengthOfDeque = (unsigned int)unsortedDeque.size();

        // Print the unsorted list
        std::cout << "Unsorted list:\n";
        for (unsigned int i = 0; i < lengthOfVector; ++i)
            std::cout << unsortedVector[i] << ' ';
        std::cout << "\n\n---Performance benchmarking---\n";

        // Sort with std::vector
        clock_t start = clock();
        std::vector<int> sortedVector = merge_insertion_sort_vector(unsortedVector);
        clock_t end = clock();
        double runtime = 1000.0 * (end - start) / CLOCKS_PER_SEC;

        std::cout << "\nSorted list (Merge-Insertion) - std::vector:\n";
        for (unsigned int i = 0; i < lengthOfVector; ++i)
            std::cout << sortedVector[i] << ' ';
        std::cout << "\nTime to process " << lengthOfVector << " elements: " << runtime << " ms\n";
        std::cout << "Number of comparisons: " << counter 
                  << " (<= worst case bound of " << worst_case_number_of_comparison((double)lengthOfVector) << ")\n";

        // Sort with std::deque
        counter = 0;
        start = clock();
        std::deque<int> sortedDeque = merge_insertion_sort_deque(unsortedDeque);
        end = clock();
        runtime = 1000.0 * (end - start) / CLOCKS_PER_SEC;

        std::cout << "\nSorted list (Merge-Insertion) - std::deque:\n";
        for (unsigned int i = 0; i < lengthOfDeque; ++i)
            std::cout << sortedDeque[i] << ' ';
        std::cout << "\nTime to process " << lengthOfDeque << " elements: " << runtime << " ms\n";
        std::cout << "Number of comparisons: " << counter
                  << " (<= worst case bound of " << worst_case_number_of_comparison((double)lengthOfDeque) << ")\n";
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
