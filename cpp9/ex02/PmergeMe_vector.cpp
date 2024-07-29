#include "PmergeMe.hpp"



std::vector<int>::iterator lower_bound(std::vector<int>& vec, int start, int end, int target)
{
	while (start < end)
	{
		int mid = start + (end - start) / 2;
		counter += 1;
		if (vec[mid] < target)
		{
			start = mid + 1;
		}
		else
		{
			end = mid;
		}
	}
	return (vec.begin() + start);
}


std::vector<int> create_sorted_list(std::vector<std::vector<int> >& pairs, int straggler, bool hasStraggler)
{
	std::vector<int> pend_chain;
	std::vector<int> main_chain;

	for (unsigned int i = 0; i < pairs.size(); ++i)
	{
		pend_chain.push_back(pairs[i][0]);
		main_chain.push_back(pairs[i][1]);
	}
	main_chain.insert(main_chain.begin(), pend_chain[0]);

	for (unsigned int index = 1; index < pend_chain.size(); ++index)
	{
		std::vector<int>::iterator insertion_point;
		int item = pend_chain[index];

		int upper_bound_insert_position = 0;
		while (pairs[index][1] != main_chain[upper_bound_insert_position])
			upper_bound_insert_position += 1;
		insertion_point = lower_bound(main_chain, 0, upper_bound_insert_position, item);
		main_chain.insert(insertion_point, item);
	}
	if (hasStraggler == true)
	{
		std::vector<int>::iterator insertion_point = insertion_point;
		insertion_point = lower_bound(main_chain, 0, main_chain.size(), straggler);
		main_chain.insert(insertion_point, straggler);
	}
	return (main_chain);
}


std::vector<int> extract_larger_values(std::vector<std::vector<int> >& pairs)
{
	std::vector<int>  array_larger_values;
	for (unsigned int i = 0; i < pairs.size(); ++i)
		array_larger_values.push_back(pairs[i][1]);
	return (array_larger_values);
}


std::vector<std::vector<int> > created_sorted_pairs(std::vector<int> &A)
{
	std::vector<std::vector<int> > split_array;
	for (std::vector<int>::size_type i = 0; i < A.size(); i += 2)
	{
		std::vector<int> pair;
		pair.push_back(A[i]);
		if (i + 1 < A.size())
			pair.push_back(A[i + 1]);
		split_array.push_back(pair);
	}

	for(unsigned int i = 0; i < split_array.size(); ++i)
	{
		counter += 1;
		if(split_array[i][0] > split_array[i][1])
		{
			std::swap(split_array[i][0], split_array[i][1]);
		}
	}
	return (split_array);
}


std::vector<int> merge_insertion_sort_vector(std::vector<int> &A)
{
	if (A.size() == 1)
		return (A);
	if (A.size() == 2)
	{
		counter += 1;
		if (A[0] > A[1])
		{
			std::swap(A[0], A[1]);
		}
		return (A);
	}
	else
	{
		bool hasStraggler = A.size() % 2 != 0;
		int straggler = 0;
		if (hasStraggler)
		{
			straggler = A.back();
			A.pop_back();
		}

		std::vector<std::vector<int> > pairs = created_sorted_pairs(A);

		std::map<int, int> hashmap;
		for (unsigned int i = 0; i < pairs.size(); ++i)
			hashmap[pairs[i][1]] = pairs[i][0];

		std::vector<int> array_larger_values = extract_larger_values(pairs);
		std::vector<int> return_vector;
		if (array_larger_values.size() >= 1)
		{
			return_vector = merge_insertion_sort_vector(array_larger_values);
			for (unsigned int i = 0; i < pairs.size(); ++i)
			{
				pairs[i][0] = hashmap[return_vector[i]];
				pairs[i][1] = return_vector[i];
			}
		}
		return (create_sorted_list(pairs, straggler, hasStraggler));
	}
}

/*
void debug_print_function(std::string str, std::vector<std::vector<int> > pairs)
{
	std::cout << '\n' << str << std::endl;
	for (std::vector<std::vector<int> >::size_type i = 0; i != pairs.size(); ++i)
	{
		for (std::vector<int>::size_type j = 0; j != pairs[i].size(); ++j)
		{
			std::cout << pairs[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}
*/
