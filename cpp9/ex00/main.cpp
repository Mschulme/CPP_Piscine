#include "BitcoinExchange.hpp"


bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(const std::string &date)
{
    std::istringstream ss(date);
    int year, month, day;
    char dash1, dash2;

    if (!(ss >> year >> dash1 >> month >> dash2 >> day))
        return false;
    if (dash1 != '-' || dash2 != '-')
        return false;
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(year)) 
        daysInMonth[2] = 29;
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > daysInMonth[month])
        return false;

    return true; 
}

bool isValidValue(const std::string &value)
{
    std::istringstream ss(value);

    float val;
    if (!(ss >> val))
        return false;
    if (val < 0.0 || val > 1000.0)
        return false;
    return true;
}

int	main(int argc, char *argv[])
{
    if (argc != 2) 
    {
        std::cout << "Wrong number of arguments." << std::endl;
        return (EXIT_SUCCESS);
    }

    std::ifstream file(argv[1]);
    if (!file)
    {
        std::cerr << "Error: Could not open file " << argv[1] << "\n";
        return (EXIT_FAILURE);
    }
    
    std::string line;
    bool firstLine = true;

    while (std::getline(file, line))
    {
        if (firstLine)
        {
            firstLine = false;
            std::cout << line << '\n';
            continue;
        }

        std::istringstream ss(line);
        std::string date, value;
        char delimiter;

        if (!(ss >> date >> delimiter >> value))
        {
            std::cerr << line << " => Error: Invalid line format \n";
            continue;
        }

        if (delimiter != '|')
        {
            std::cerr << line << " => Error: Invalid line format \n";
            continue;
        }

        if (!isValidDate(date))
        {
            std::cerr << line << " => Error: Invalid date format \n";
            continue;;
        }

        if (!isValidValue(value))
        {
            std::cerr << line << " => Error: Invalid value \n";
            continue;
        }

        std::cout << line << '\n';
    }

    file.close();
    return (EXIT_SUCCESS);
}
