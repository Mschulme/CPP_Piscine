#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Not enough arguments..." << std::endl;
        return (EXIT_SUCCESS);
    }

    std::string str = argv[1];
    
    RPN_calculator(str);

    return (EXIT_SUCCESS);
}
