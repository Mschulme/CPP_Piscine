#include "PmergeMe.hpp"


static const int GROUP_SIZES[] = {2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366, 2730, 5462, 10922, 21846, 43690, 87382, 174762, 349526, 699050, 1398102};
static const size_t GROUP_COUNT = sizeof(GROUP_SIZES)/sizeof(GROUP_SIZES[0]);


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
    std::vector<bool> inserted(pend_chain.size(), false);
    inserted[0] = true;

    std::vector<int> uninserted;
    for (size_t i = 1; i < pend_chain.size(); ++i)
    {
        if (!inserted[i])
        {
            uninserted.push_back((int)i);
        }
    }

    std::vector< std::vector<int> > groups; 
    {
        size_t start = 0;
        size_t remain = uninserted.size();
        size_t g_idx = 0;
        while (remain > 0 && g_idx < GROUP_COUNT)
        {
            int g_size = GROUP_SIZES[g_idx];
            if ((size_t)g_size > remain)
                g_size = (int)remain;

            std::vector<int> group;
            for (int k = 0; k < g_size; ++k)
            {
                group.push_back(uninserted[start + k]);
            }
            groups.push_back(group);
            start += g_size;
            remain -= g_size;
            g_idx++;
        }
    }
    for (size_t i = 0; i < groups.size(); ++i)
    {
        std::reverse(groups[i].begin(), groups[i].end());
    }

	size_t upper_bound = 0;
    for (size_t g = 0; g < groups.size(); ++g)
    {
		upper_bound = pow(2, g + 2) - 1;
        for (size_t el = 0; el < groups[g].size(); ++el)
        {
            int idx = groups[g][el];
            int item = pend_chain[(size_t)idx];

			if (upper_bound > main_chain.size())
				upper_bound = main_chain.size();
            std::vector<int>::iterator insertion_point = lower_bound(main_chain, 0, upper_bound, item);
            main_chain.insert(insertion_point, item);
            inserted[(size_t)idx] = true;
        }
    }

    if (hasStraggler == true)
    {
        std::vector<int>::iterator insertion_point = lower_bound(main_chain, 0, (int)main_chain.size(), straggler);
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
