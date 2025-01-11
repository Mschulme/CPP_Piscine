#include <bits/stdc++.h>
using namespace std;


int main(void)
{
    vector<int> v = { 1 ,4 ,5 ,9, 8, 11, 15 };

    vector<int> evens, odds;

    evens.reserve(v.size());
    odds.reserve(v.size());


    partition_copy(v.begin(), v.end(), back_inserter(evens), back_inserter(odds), [](int x)
    {
        return x % 2 == 0;
    });

}
