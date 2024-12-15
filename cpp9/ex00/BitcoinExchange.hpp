#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <list>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <iostream>


class BitcoinExchange
{
    private:
        std::list<std::pair<std::string, float> > exchangeRates;
        
        bool isLeapYear(int year) const;
        bool isValidDate(const std::string &date) const;
        bool isValidValue(const std::string &value) const;
        float getRateForDate(const std::string &date, bool &found) const;

    public:
        BitcoinExchange();
        ~BitcoinExchange();

        bool loadData(const std::string &dataFileName);
        void processInputFile(const std::string &inputFileName);
};

#endif