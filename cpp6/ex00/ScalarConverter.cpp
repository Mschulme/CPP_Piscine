#include "ScalarConverter.hpp"


void ScalarConverter::convert(const std::string &input)
{
    Type type = detectType(input);
    switch (type)
    {
        case CHARACTER:
            convertCharacter(input);
            break;
        case INTEGER:
            convertInteger(input);
            break;
        case FLOAT:
            convertFloat(input);
            break;  
        case DOUBLE:
            convertDouble(input);
            break;
        default:
            std::cout << "char: impossible"   << std::endl;
            std::cout << "int: impossible"    << std::endl;
            std::cout << "float: impossible"  << std::endl;
            std::cout << "double: impossible" << std::endl;
            break;
    }
}


Type ScalarConverter::detectType(const std::string &input)
{
    if (isCharacter(input))
        return CHARACTER;
    if (isInteger(input))
        return INTEGER;
    if (isFloat(input))
        return FLOAT;
    if (isDouble(input))
        return DOUBLE;
    return INVALID;
}


bool ScalarConverter::isCharacter(const std::string &input)
{
    if (input.size() == 1 && std::isprint(static_cast<unsigned char>(input[0])) && !std::isdigit(static_cast<unsigned char>(input[0])))
    {
        return true;
    }
    return false;
}


bool ScalarConverter::isInteger(const std::string &input)
{
    std::string::size_type start = 0;
    if (!input.empty() && (input[0] == '+' || input[0] == '-'))
        start = 1;

    if (start == input.size())
        return false;

    for (std::string::size_type i = start; i < input.size(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(input[i])))
            return false;
    }
    return !input.empty();
}


bool ScalarConverter::isFloat(const std::string &input)
{
    if (input.empty() || input[input.length() - 1] != 'f')
        return false;

    std::string without_f = input.substr(0, input.size() - 1);

    return isDouble(without_f);
}


bool ScalarConverter::isDouble(const std::string &input)
{
    if (input == "inf" || input == "+inf" || input == "-inf" || input == "nan")
        return true;

    std::string::size_type start = 0;
    if (!input.empty() && (input[0] == '+' || input[0] == '-'))
        start = 1;

    bool dotFound   = false;
    bool digitFound = false;

    for (std::string::size_type i = start; i < input.size(); ++i)
    {
        if (input[i] == '.')
        {
            if (dotFound)
                return false;
            dotFound = true;
        }
        else if (std::isdigit(static_cast<unsigned char>(input[i])))
        {
            digitFound = true;
        }
        else
        {
            return false;
        }
    }
    return digitFound;
}


int ScalarConverter::countDecimalDigits(const std::string &input)
{
    std::string tmp = input;
    if (!tmp.empty() && tmp[tmp.length() - 1] == 'f')
        tmp.resize(tmp.size() - 1);

    if (tmp == "inf" || tmp == "+inf" || tmp == "-inf" || tmp == "nan")
        return 1;

    std::size_t dotPos = tmp.find('.');
    if (dotPos == std::string::npos)
    {
        return 1;
    }
    else
    {
        int digitsAfter = static_cast<int>(tmp.size() - dotPos - 1);
        if (digitsAfter <= 0)
            digitsAfter = 1;
        return digitsAfter;
    }
}


void ScalarConverter::convertCharacter(const std::string &input)
{
    char c = input[0];
    double value = static_cast<double>(c);

    printCharacter(value);
    printInteger(value);
    printFloat(static_cast<float>(value));
    printDouble(value);
}


void ScalarConverter::convertInteger(const std::string &input)
{
    errno = 0;
    const char *str = input.c_str();
    char *endPtr    = NULL;
    long val        = std::strtol(str, &endPtr, 10);

    if (errno != 0 || *endPtr != '\0')
    {
        std::cout << "char: impossible"   << std::endl;
        std::cout << "int: impossible"    << std::endl;
        std::cout << "float: impossible"  << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    double value = static_cast<double>(val);

    printCharacter(value);
    printInteger(value);
    printFloat(static_cast<float>(value));
    printDouble(value);
}


void ScalarConverter::convertFloat(const std::string &input)
{
    errno = 0;
    std::string without_f = input.substr(0, input.size() - 1);
    const char *str = without_f.c_str();
    char *endPtr    = NULL;
    double tempVal  = std::strtod(str, &endPtr);

    if (without_f == "inf" || without_f == "+inf")
        tempVal =  std::numeric_limits<double>::infinity();
    else if (without_f == "-inf")
        tempVal = -std::numeric_limits<double>::infinity();
    else if (without_f == "nan")
        tempVal =  std::numeric_limits<double>::quiet_NaN();

    if (errno != 0 || *endPtr != '\0')
    {
        std::cout << "char: impossible"   << std::endl;
        std::cout << "int: impossible"    << std::endl;
        std::cout << "float: impossible"  << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    if (std::fabs(tempVal) > std::numeric_limits<float>::max() && !std::isinf(tempVal))
    {
        std::cout << "char: impossible"   << std::endl;
        std::cout << "int: impossible"    << std::endl;
        std::cout << "float: impossible"  << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    float valueF = static_cast<float>(tempVal);

    int precision = countDecimalDigits(input);

    printCharacter(tempVal);    
    printInteger(tempVal);
    printFloat(valueF, precision);
    printDouble(tempVal, precision);
}


void ScalarConverter::convertDouble(const std::string &input)
{
    errno = 0;
    const char *str = input.c_str();
    char *endPtr    = NULL;
    double val      = std::strtod(str, &endPtr);

    if (input == "inf"  || input == "+inf")
        val =  std::numeric_limits<double>::infinity();
    else if (input == "-inf")
        val = -std::numeric_limits<double>::infinity();
    else if (input == "-nan")
        val =  std::numeric_limits<double>::quiet_NaN(); 

    if (errno != 0 || *endPtr != '\0')
    {
        std::cout << "char: impossible"   << std::endl;
        std::cout << "int: impossible"    << std::endl;
        std::cout << "float: impossible"  << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    int precision = countDecimalDigits(input);

    printCharacter(val);
    printInteger(val);
    printFloat(static_cast<float>(val), precision);
    printDouble(val, precision);
}


void ScalarConverter::printCharacter(double value)
{
    if (std::isnan(value) || std::isinf(value) ||
        value > static_cast<double>(std::numeric_limits<char>::max()) ||
        value < static_cast<double>(std::numeric_limits<char>::min()))
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }

    char c = static_cast<char>(value);
    if (std::isprint(static_cast<unsigned char>(c)))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}


void ScalarConverter::printInteger(double value)
{
    if (std::isnan(value) || std::isinf(value) ||
        value > static_cast<double>(std::numeric_limits<int>::max()) ||
        value < static_cast<double>(std::numeric_limits<int>::min()))
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }

    int i = static_cast<int>(value);
    std::cout << "int: " << i << std::endl;
}


void ScalarConverter::printFloat(float value)
{
    if (std::isnan(value))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(value))
        std::cout << "float: " << (value < 0 ? "-inff" : "inff") << std::endl;
    else
    {
        std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
    }
}


void ScalarConverter::printDouble(double value)
{
    if (std::isnan(value))
        std::cout << "double: nan" << std::endl;
    else if (std::isinf(value))
        std::cout << "double: " << (value < 0 ? "-inf" : "inf") << std::endl;
    else
    {
        std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
    }
}


void ScalarConverter::printFloat(float value, int precision)
{
    if (std::isnan(value))
    {
        std::cout << "float: nanf" << std::endl;
    }
    else if (std::isinf(value))
    {
        std::cout << "float: " << (value < 0 ? "-inff" : "inff") << std::endl;
    }
    else
    {
        std::cout << std::fixed << std::setprecision(precision) << "float: " << value << "f" << std::endl;
    }
}


void ScalarConverter::printDouble(double value, int precision)
{
    if (std::isnan(value))
    {
        std::cout << "double: nan" << std::endl;
    }
    else if (std::isinf(value))
    {
        std::cout << "double: " << (value < 0 ? "-inf" : "inf") << std::endl;
    }
    else
    {
        std::cout << std::fixed << std::setprecision(precision) << "double: " << value << std::endl;
    }
}

