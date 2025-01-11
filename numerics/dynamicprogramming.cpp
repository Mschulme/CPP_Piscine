#include<bits/stdc++.h>
using namespace std;


// Example with custom sort function
int main(void)
{
    // Use .first and .second to access the elements of pair data type
    
    vector<pair<int, string>> students =
    {
        {85, "Alice"}, {92, "Bob"}, {55, "Charlie"}
    };

    /*
        In a lambda expression in C++ specifies which variables from the surrounding scope the lambda should "capture" 
        and make available inside its body.
        & capture by reference
        = capture by value

        Capture clause is empty, because the comparison lambda doesnt need any external or local variables from 
        the surrounding function scope.
    */

    sort(students.begin(), students.end(), [](auto &a, auto &b)
    {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    });

    cout << "Students sorted by (score desc, name asc):" << endl;
    for (auto &st : students)
    {
        cout << st.first << " - " << st.second << endl;
    }
    return 0;

}



/*
    template <class Random It, class Compare>
    void sort(RandomIt first, RandomIt last, Compare comp)

What comp Must do:

    Acccept two parameters (const references if possible)

    Return true if the first paramter is considered less than the second paramter

    Return false otherwise

    => strict weak ordering



    [](auto &a, auto &b) template parameter deduction (C++ 14 and later.)

    Example capture with external variable.

    int multiplier = 2;

    std::sort(vec.begin(), vec.end(), [multiplier](int a, int b)
    {
        return (a * multiplier) < (b * multiplier);
    });

*/