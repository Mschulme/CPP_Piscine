#include "BitcoinExchange.hpp"



BitcoinExchange::BitcoinExchange()
{
    std::cout << "Default constructor called" << std::endl;
}


BitcoinExchange::~BitcoinExchange()
{
    std::cout << "Destructor called" << std::endl;
}


bool BitcoinExchange::loadData(const std::string &dataFileName)
{
    std::ifstream dataFile(dataFileName.c_str());
    if (!dataFile)
    {
        std::cerr << "Error: Could not open " << dataFileName << "\n";
        return false;
    }

    std::string line;
    bool header = true;
    while (std::getline(dataFile, line))
    {
        if (header)
        {
            header = false;
            continue;
        }

        std::istringstream ss(line);
        std::string dateString;
        std::string rateString;

        if (!std::getline(ss, dateString, ','))
        {
            std::cout << "invalid" << std::endl;
            continue;
        }

        if (!std::getline(ss, rateString))
        {
            std::cout << "invalid" << std::endl;
            continue;
        }

        std::istringstream rs(rateString);
        float rate;
        if (!(rs >> rate))
        {
            std::cout << "invalid rate" << std::endl;
            continue;
        }
        exchangeRates.push_back(std::make_pair(dateString, rate));
    }

    /*
    for (std::list<std::pair<std::string, float> >::const_iterator it = exchangeRates.begin();
        it != exchangeRates.end(); ++it)
    {
        std::cout << it->first << " => " << it->second << std::endl;
    }
    */

    dataFile.close();
    return true;
}


void BitcoinExchange::processInputFile(const std::string &inputFileName)
{
    std::ifstream file(inputFileName.c_str());
    if (!file) {
        std::cerr << "Error: Could not open file " << inputFileName << "\n";
        return;
    }

    std::string line;
    bool firstLine = true;

    while (std::getline(file, line))
    {
        if (firstLine)
        {
            std::cout << line << '\n';
            firstLine = false;
            continue;
        }

        std::istringstream ss(line);
        std::string date, value;
        char delimiter;

        if (!(ss >> date >> delimiter >> value))
        {
            std::cerr << line << " => Error: Invalid line format\n";
            continue;
        }

        if (delimiter != '|')
        {
            std::cerr << line << " => Error: Invalid line format\n";
            continue;
        }


        if (!isValidDate(date))
        {
            std::cerr << line << " => Error: Invalid date format\n";
            continue;
        }


        if (!isValidValue(value))
        {
            continue;
        }

        float val;
        {
            std::istringstream vs(value);
            vs >> val;
        }

        bool found = true;
        float rate = getRateForDate(date, found);
        if (!found)
        {
            // No previous data
            std::cerr << line << " => Error: No previous data available for " << date << "\n";
            continue;
        }

        float result = val * rate;
        std::cout << date << " => " << val << " * " << rate << " = " << result << '\n';
    }

    file.close();
}


float BitcoinExchange::getRateForDate(const std::string &date, bool &found) const
{
    std::list<std::pair<std::string, float> >::const_iterator it = exchangeRates.begin();
    std::list<std::pair<std::string, float> >::const_iterator best = exchangeRates.end();

    for (; it != exchangeRates.end(); ++it) {
        const std::string &d = it->first;
        if (d == date)
        {
            // Exact match
            found = true;
            return it->second;
        }
        if (d <= date) {
            // Update best candidate
            best = it;
        } else {
            // We've found a date greater than 'date'
            // No need to continue since list is sorted
            break;
        }
    }

    if (best == exchangeRates.end()) {
        // No date <= requested date
        found = false;
        return 0.0f;
    }

    // best now points to the closest past date
    found = true;
    return best->second;
}


bool BitcoinExchange::isValidValue(const std::string &value) const
{
    std::istringstream ss(value);
    float val;
    if (!(ss >> val))
    {
        std::cerr << " => Error: Invalid value\n";
        return false;
    }
    if (val < 0.0f)
    {
        std::cerr << "Error: not a positive number.\n";
        return false;
    }
    if (val > 1000.0f)
    {
        std::cerr << "Error: too large a number.\n";
        return false;
    }
    return true;
}


bool BitcoinExchange::isLeapYear(int year) const
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


bool BitcoinExchange::isValidDate(const std::string &date) const
{
    std::istringstream ss(date);
    int year, month, day;
    char dash1, dash2;

    if (!(ss >> year >> dash1 >> month >> dash2 >> day))
        return false;
    if (dash1 != '-' || dash2 != '-')
        return false;
    if (year < 0)
        return false;

    int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(year))
        daysInMonth[2] = 29;
    if (month < 1 || month > 12 || day < 1 || day > daysInMonth[month])
        return false;

    return true;
}
