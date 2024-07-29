#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>


class ScalarConverter
{
    public:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &obj);
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &obj);

        // member functions
        static void convert(const std::string& literal);
};

#endif
