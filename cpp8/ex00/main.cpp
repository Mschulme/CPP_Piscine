#include "easyfind.hpp"

int main()
{
    // Test case 1: Searching in a std::vector
    {
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);

        try
        {
            std::vector<int>::iterator it = easyfind(vec, 20);
            std::cout << "Found value " << *it << " in vector at position: "  << (it - vec.begin()) << std::endl;
        }
        catch (const std::runtime_error &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        try
        {
            std::vector<int>::iterator it = easyfind(vec, 40);
            std::cout << "Found value " << *it << " in vector." << std::endl;
        }
        catch (const std::runtime_error &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    // Test case 2: Searching in a std::list
    {
        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(15);
        lst.push_back(25);

        try
        {
            std::list<int>::iterator it = easyfind(lst, 5);
            std::cout << "Found value " << *it << " in list." << std::endl;
        } catch (const std::runtime_error &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        try
        {
            std::list<int>::iterator it = easyfind(lst, 35);
            std::cout << "Found value " << *it << " in list." << std::endl;
        }
        catch (const std::runtime_error &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    // Test case 3: empty vector
    {
        std::vector<int> emptyVec;

        try
        {
            std::vector<int>::iterator it = easyfind(emptyVec, 10);
            std::cout << "Found value " << *it << " in empty vector." << std::endl;
        }
        catch (const std::runtime_error &e)
        {
            std::cerr << "Error: " << e.what() << " (empty vector test)" << std::endl;
        }
    }

    // Test case 4: Associative container - set
    {
        std::set<int> s;
        s.insert(10);
        s.insert(20);
        s.insert(30);

        try
        {
            std::set<int>::iterator itSet = easyfindAssociative(s, 10);
            std::cout << "Found value " << *itSet << " set." << std::endl;
        }
        catch (const std::runtime_error &e)
        {
            std::cerr << "Error: " << e.what() << " (set)" << std::endl;
        }
    }

    return (EXIT_SUCCESS);
}
