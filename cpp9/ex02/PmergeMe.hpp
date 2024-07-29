#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cmath>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <map>

extern int counter;

std::vector<int> input_parsing_vector(int argc, char *argv[]);
std::vector<int> merge_insertion_sort_vector(std::vector<int> &A);

std::deque<int> input_parsing_deque(int argc, char *argv[]);
std::deque<int> merge_insertion_sort_deque(std::deque<int> &A);

#endif