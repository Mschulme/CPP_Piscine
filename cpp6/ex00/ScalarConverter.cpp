#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "Scalar Converter: Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &obj)
{
    if(this != &obj)
    {
        *this = obj;
    }
}

ScalarConverter::~ScalarConverter()
{
;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
    if (this != &obj)
    {

    }
    return (*this);
}


// member functions

void ScalarConverter::convert(const std::string &literal)
{
    char charValue = static_cast<char>(std::atoi(literal.c_str()));
    if (charValue > 18 and charValue < 127)
        std::cout << "char: " << charValue << std::endl;
    else
        std::cout << "Non displayable" << charValue << std::endl;

    int integerValue = static_cast<char>(std::atoi(literal.c_str()));
        std::cout << "int: " << integerValue << std::endl;

    float floatValue = static_cast<float>(std::atof(literal.c_str()));
        std::cout << "float: " << floatValue << std::endl;

    double doubleValue = static_cast<double>(std::atof(literal.c_str()));
        std::cout << "double: " << doubleValue << std::endl;

}
