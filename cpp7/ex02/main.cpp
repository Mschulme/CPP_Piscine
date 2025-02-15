#include "Array.hpp"

#define MAX_VAL 15

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));

    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand() % 100;
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        for (int i = 0; i < MAX_VAL; i++)
        {
            std::cout << numbers[i] << " ";
        }
        std::cout << std::endl;

        Array<int> tmp = numbers;
        for (int i = 0; i < MAX_VAL; i++)
        {
            std::cout << tmp[i] << " ";
        }
        std::cout << std::endl;

        Array<int> test(tmp);
        for (int i = 0; i < MAX_VAL; i++)
        {
            std::cout << test[i] << " ";
        }
        std::cout << std::endl;

        for (int i = 0; i < MAX_VAL; i++)
        {
            std::cout << numbers[i] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand() % 100;
        if (i != 0 && i % 10 == 0)
            std::cout << numbers[i] << ' ' << std::endl;
        else
            std::cout << numbers[i] << ' ';
    }
    std::cout << std::endl;

    delete [] mirror;
    return EXIT_SUCCESS;
}
