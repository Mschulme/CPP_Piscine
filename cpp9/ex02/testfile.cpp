#include <iostream>
#include <vector>
#include <algorithm> // for std::lower_bound, std::sort
#include <cmath>     // for std::abs if needed
#include <cstdlib>   // for EXIT_SUCCESS

// Create pairs from the given vector A, mimicking the Python logic
static std::vector< std::vector<int> > create_pairs(const std::vector<int> &a)
{
    std::vector< std::vector<int> > split_array;
    std::vector<int> temp_array;

    // The Python code used enumerate starting at 1, but we can ignore that and just use indices
    for (size_t i = 0; i < a.size(); ++i)
    {
        int value = a[i];
        size_t temp_length = temp_array.size();

        if (temp_length == 1)
        {
            // If we already have one element in temp_array, add the second and form a pair
            temp_array.push_back(value);
            split_array.push_back(temp_array);
            temp_array.clear();
        }
        else if (split_array.size() * 2 == a.size() - 1)
        {
            // If we are at the last odd element (straggler scenario)
            std::vector<int> single;
            single.push_back(value);
            split_array.push_back(single);
        }
        else if (temp_length == 0)
        {
            // Start a new pair
            temp_array.push_back(value);
        }
    }

    return split_array;
}

// Sort each pair so that the smaller element is first
static std::vector< std::vector<int> > sort_each_pair(std::vector< std::vector<int> > split_array)
{
    for (size_t i = 0; i < split_array.size(); ++i)
    {
        std::vector<int> &pair = split_array[i];
        if (pair.size() == 2 && pair[0] > pair[1])
        {
            int temp = pair[0];
            pair[0] = pair[1];
            pair[1] = temp;
        }
    }
    return split_array;
}

// Insert function used by insertion_sort_pairs
// This recursively inserts a pair into a vector of pairs sorted by their larger element
static void insert_pair(const std::vector<int> &element, std::vector< std::vector<int> > &A, int n)
{
    // element is a pair, A is sorted by their second (larger) element
    // This is a recursive insertion as in Python code
    if (n < 0)
    {
        A.insert(A.begin(), element);
    }
    else if (element[1] >= A[(size_t)n][1])
    {
        if ((size_t)n == A.size() - 1)
        {
            A.push_back(element);
        }
        else
        {
            A.insert(A.begin() + n + 1, element);
        }
    }
    else
    {
        // shift A[n] forward
        if ((size_t)n == A.size() - 1)
        {
            A.push_back(A[(size_t)n]);
            A[(size_t)n] = element;
        }
        else
        {
            std::vector<int> temp = A[(size_t)n];
            A[(size_t)n + 1] = temp;
            insert_pair(element, A, n - 1);
        }
    }
}

// Recursively sort pairs by their largest element using insertion sort logic
static void insertion_sort_pairs(std::vector< std::vector<int> > &A, int n)
{
    if (n < 1)
        return;
    insertion_sort_pairs(A, n - 1);
    std::vector<int> element = A[(size_t)n];
    A.erase(A.begin() + n);
    insert_pair(element, A, n - 1);
}

// Compute the nth Jacobsthal number recursively
static int jacobsthal(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

// Build the jacobsthal insertion sequence for the given array length
static std::vector<int> build_jacob_insertion_sequence(const std::vector<int> &array)
{
    int array_len = (int)array.size();
    std::vector<int> end_sequence;
    int jacob_index = 3; // start from 3 as in Python code

    while (jacobsthal(jacob_index) < array_len - 1)
    {
        end_sequence.push_back(jacobsthal(jacob_index));
        jacob_index += 1;
    }

    return end_sequence;
}

// Sort the larger half of pairs recursively
static void sort_by_larger_value(std::vector< std::vector<int> > &sorted_split_array)
{
    insertion_sort_pairs(sorted_split_array, (int)sorted_split_array.size() - 1);
}

// Equivalent of Python's bisect.bisect, we use std::lower_bound
// We'll not count comparisons exactly the same way as python code did, just mimic behavior
static int bisect_insertion_point(const std::vector<int> &S, int item)
{
    std::vector<int>::const_iterator it = std::lower_bound(S.begin(), S.end(), item);
    return (int)(it - S.begin());
}

static std::vector<int> create_s(std::vector< std::vector<int> > &sorted_split_array, int straggler, bool print_comparision_estimation)
{
    std::vector<int> S;
    std::vector<int> pend;
    int comparisions_made = 0;

    // Split pairs into S (larger) and pend (smaller)
    for (size_t i = 0; i < sorted_split_array.size(); ++i)
    {
        S.push_back(sorted_split_array[i][1]);
        pend.push_back(sorted_split_array[i][0]);
    }

    // Insert the first element of pend at start of S
    S.insert(S.begin(), pend[0]);

    // Build the valid Jacobsthal insertion sequence
    std::vector<int> jacob_insertion_sequence = build_jacob_insertion_sequence(pend);

    int iterator = 1; // We already inserted pend[0], so start from 1
    int jacobindex = 3;
    std::string last = "default";
    std::vector<int> indexSequence;
    indexSequence.push_back(1); // already inserted pend[0]

    // We'll mimic the python logic: while iterator <= len(pend)
    // Actually, python code might run into issues if iterator surpasses size.
    // We'll just follow the logic as is.
    while (iterator <= (int)pend.size())
    {
        int item;
        if (!jacob_insertion_sequence.empty() && last != "jacob")
        {
            // Use a jacob index
            int j_idx = jacob_insertion_sequence[0];
            jacob_insertion_sequence.erase(jacob_insertion_sequence.begin());
            item = pend[(size_t)(j_idx - 1)];
            indexSequence.push_back(j_idx);
            last = "jacob";
        }
        else
        {
            // fill with the next element not in indexSequence
            // Actually python code checks if (iterator in indexSequence).
            // We'll check if iterator is already in indexSequence:
            bool inIndexSeq = false;
            for (size_t k = 0; k < indexSequence.size(); ++k)
            {
                if (indexSequence[k] == iterator)
                {
                    inIndexSeq = true;
                    break;
                }
            }

            while (inIndexSeq && iterator <= (int)pend.size())
            {
                iterator++;
                inIndexSeq = false;
                for (size_t k = 0; k < indexSequence.size(); ++k)
                {
                    if (indexSequence[k] == iterator)
                    {
                        inIndexSeq = true;
                        break;
                    }
                }
            }
            if (iterator > (int)pend.size()) 
            {
                // We've inserted all pend elements
                break;
            }

            item = pend[(size_t)(iterator - 1)];
            indexSequence.push_back(iterator);
            last = "not-jacob";
            iterator++;
            jacobindex++;
        }

        // Now insert item into S using binary search
        int insertion_point = bisect_insertion_point(S, item);
        S.insert(S.begin() + insertion_point, item);

        // The Python code increments comparisons_made by 2 for each insertion
        comparisions_made += 2;
    }

    // Insert the straggler if exists
    if (straggler != 0)
    {
        int insertion_point = bisect_insertion_point(S, straggler);
        S.insert(S.begin() + insertion_point, straggler);
        comparisions_made += 2;
    }

    if (print_comparision_estimation)
    {
        std::cout << "Approximate Comparisions Made:" << std::endl;
        std::cout << comparisions_made << std::endl;
    }

    return S;
}

static std::vector<int> merge_insertion_sort(std::vector<int> A)
{
    std::cout << "Starting Array:" << std::endl;
    for (size_t i = 0; i < A.size(); ++i)
        std::cout << A[i] << (i+1==A.size()?'\n':' ');
    std::cout << std::endl;

    bool hasStraggler = (A.size() % 2 != 0);
    int straggler = 0;
    if (hasStraggler)
    {
        straggler = A.back();
        A.pop_back();
    }
    else
        straggler = 0;

    // Create pairs
    std::vector< std::vector<int> > split_array = create_pairs(A);

    // Sort each pair
    std::vector< std::vector<int> > sorted_split_array = sort_each_pair(split_array);

    // Recursively sort by larger value
    sort_by_larger_value(sorted_split_array);

    // Create main and pend sequences and do Jacobsthal-based insertion
    std::vector<int> S = create_s(sorted_split_array, straggler, true);

    std::cout << "Sorted Array:" << std::endl;
    for (size_t i = 0; i < S.size(); ++i)
        std::cout << S[i] << (i+1==S.size()?'\n':' ');
    std::cout << std::endl;

    return S;
}

int main()
{
    // Example usage:
    // You can modify this to read from stdin or use a fixed array
    std::vector<int> A;
    A.push_back(9);
    A.push_back(7);
    A.push_back(4);
    A.push_back(8);
    A.push_back(2);
    A.push_back(5);
    A.push_back(6);
    A.push_back(10);
    A.push_back(3);
    A.push_back(1);

    std::vector<int> result = merge_insertion_sort(A);

    return EXIT_SUCCESS;
}
