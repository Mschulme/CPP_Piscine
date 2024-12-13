#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <set>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm> // std::find
#include <stdexcept>


// Template for sequential containers, like list and vector
template <typename T>
typename T::iterator easyfind(T &container, int value)  // Reference to container
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) // If std::find cannot locate the element, it returns container.end()
        throw std::runtime_error("Value not found");
    return it;
}


// Template for set (associative containers)
template <typename Key, typename Compare, typename Alloc>
typename std::set<Key, Compare, Alloc>::iterator easyfindAssociative(std::set<Key, Compare, Alloc> &container, const Key &value)
{
    typename std::set<Key, Compare, Alloc>::iterator it = container.find(value); // Use find function from set container
    if (it == container.end())
        throw std::runtime_error("Value not found in set");
    return it;
}

#endif
