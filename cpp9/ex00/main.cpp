#include "BitcoinExchange.hpp"


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Wrong number of arguments." << std::endl;
        std::cout << "Usage: " << argv[0] << " input.txt" << std::endl;
        return EXIT_SUCCESS;
    }
    
    BitcoinExchange exchange;
    if (!exchange.loadData("data.csv"))
        return EXIT_FAILURE;

    exchange.processInputFile(argv[1]);

    return EXIT_SUCCESS;
}
