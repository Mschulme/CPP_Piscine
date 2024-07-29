#include "PmergeMe.hpp"


std::deque<int>::iterator lower_bound_deque(std::deque<int>& vec, int start, int end, int target)
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


std::deque<int> create_sorted_list_deque(std::deque<std::deque<int> >& pairs, int straggler, bool hasStraggler)
{
	std::deque<int> pend_chain;
	std::deque<int> main_chain;

	for (unsigned int i=0; i<pairs.size(); ++i)
	{
		pend_chain.push_back(pairs[i][0]);
		main_chain.push_back(pairs[i][1]);
	}
	main_chain.insert(main_chain.begin(), pend_chain[0]);

	for (unsigned int index = 1; index < pend_chain.size(); ++index)
	{
		std::deque<int>::iterator insertion_point;
		int item = pend_chain[index];

		int upper_bound_insert_position = 0;
		while (pairs[index][1] != main_chain[upper_bound_insert_position])
			upper_bound_insert_position += 1;

		insertion_point = lower_bound_deque(main_chain, 0, upper_bound_insert_position, item);
		main_chain.insert(insertion_point, item);
	}

	if (hasStraggler == true)
	{
		std::deque<int>::iterator insertion_point;
		insertion_point = lower_bound_deque(main_chain, 0, main_chain.size(), straggler);
		main_chain.insert(insertion_point, straggler);
	}
	return (main_chain);
}


std::deque<int> extract_larger_values_deque(std::deque<std::deque<int> >& pairs)
{
	std::deque<int>  array_larger_values;
	for (unsigned int i = 0; i < pairs.size(); ++i)
		array_larger_values.push_back(pairs[i][1]);
	return (array_larger_values);
}


std::deque<std::deque<int> > created_sorted_pairs_deque(std::deque<int> &A)
{
	std::deque<std::deque<int> > split_array;
	for (std::deque<int>::size_type i = 0; i < A.size(); i += 2)
	{
		std::deque<int> pair;
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


std::deque<int> merge_insertion_sort_deque(std::deque<int> &A)
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

		std::deque<std::deque<int> > pairs = created_sorted_pairs_deque(A);

		std::map<int, int> hashmap;
		for (unsigned int i = 0; i < pairs.size(); ++i)
			hashmap[pairs[i][1]] = pairs[i][0];

		std::deque<int> array_larger_values = extract_larger_values_deque(pairs);
		std::deque<int> return_vector;
		if (array_larger_values.size() >= 1)
		{
			return_vector = merge_insertion_sort_deque(array_larger_values);
			for (unsigned int i = 0; i < pairs.size(); ++i)
			{
				pairs[i][0] = hashmap[return_vector[i]];
				pairs[i][1] = return_vector[i];
			}
		}
		return (create_sorted_list_deque(pairs, straggler, hasStraggler));
	}
}
