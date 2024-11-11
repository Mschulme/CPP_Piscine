#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Scalar Converter: Default constructor called" << std::endl;
}


ScalarConverter::ScalarConverter(ScalarConverter const &obj)
{
	*this = obj;
}


ScalarConverter::~ScalarConverter()
{
	std::cout << "Scalar Converter: Destructor called" << std::endl;
}


ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
	if (this != &obj)
	{
		;
	}
	return *this;
}


void ScalarConverter::convert(const std::string &input_string)
{
	Type type = ScalarConverter::type_of_input_string(input_string);

	std::cout << "The input is "<< input_string << " and the type of the input is " << ScalarConverter::TypeToString(type) << "." << std::endl;
	
	switch(type)
	{
		case CHARACTER:
			ScalarConverter::input_string_is_char(input_string);
			break;
	
		case INTEGER:
			ScalarConverter::input_string_is_int(input_string);
			break;

		case FLOAT:
			ScalarConverter::input_string_is_float(input_string);
			break;
		
		case DOUBLE:
			ScalarConverter::input_string_is_double(input_string);
			break;

		default:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
	}
}


std::string ScalarConverter::TypeToString(Type type)
{
	switch(type)
	{
		case CHARACTER: return "Character";
		case INTEGER: return "Integer";
		case FLOAT: return "Float";
		case DOUBLE: return "Double";
		default: return "Invalid";
	}
}


Type ScalarConverter::type_of_input_string(const std::string &input_string)
{
	if (input_string.length() == 1 && std::isprint(input_string[0]) && !std::isdigit(input_string[0]))
		return CHARACTER;
	if (input_string.find('.') == std::string::npos && input_string.find('f') == std::string::npos)
		return INTEGER;
	if (input_string.find('f') != std::string::npos)
		return FLOAT;
	if (input_string.find('.') != std::string::npos)
		return DOUBLE;
	return INVALID;
}


void ScalarConverter::input_string_is_char(const std::string &input_string)
{
	char charValue = static_cast<char>(std::atoi(input_string.c_str()));
	if (std::isprint(charValue))
		std::cout << "char: '" << charValue << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	int intValue = static_cast<int>(charValue);
	std::cout << "int: " << intValue << std::endl;

	float floatValue = static_cast<float>(charValue);
	std::cout << "float: " << floatValue << "f" << std::endl;

	double doubleValue = static_cast<double>(charValue);
	std::cout << "double: " << doubleValue << std::endl;
}


void ScalarConverter::input_string_is_int(const std::string &input_string)
{
	int intValue = std::atoi(input_string.c_str());
	if (intValue >= std::numeric_limits<char>::min() && intValue <= std::numeric_limits<char>::max())
	{
		char charValue = static_cast<char>(intValue);
		if (std::isprint(charValue))
		{
			std::cout << "char: '" << charValue << "'" << std::endl;
		}
		else
		{
			std::cout << "char: Non displayable" << std::endl;
		}
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
	}

	std::cout << "int: " << intValue << std::endl;
	
	float floatValue = static_cast<float>(intValue);
	std::cout << "float: " << floatValue << ".0f" << std::endl;

	double doubleValue = static_cast<double>(intValue);
	std::cout << "double: " << doubleValue << ".0" << std::endl;
}


void ScalarConverter::input_string_is_float(const std::string &input_string)
{
	float floatValue = std::atof(input_string.c_str());
	std::cout << "float: " << floatValue << "f" << std::endl;

	if (floatValue >= std::numeric_limits<char>::min() && floatValue <= std::numeric_limits<char>::max())
	{
		char charValue = static_cast<char>(floatValue);
		if (std::isprint(charValue))
			std::cout << "char: '" << charValue << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
	}

	int intValue = static_cast<int>(floatValue);
	std::cout << "int: " << intValue << std::endl;

	double doubleValue = static_cast<double>(floatValue);
	std::cout << "double: " << doubleValue << std::endl;
}


void ScalarConverter::input_string_is_double(const std::string &input_string)
{
	double doubleValue = std::atof(input_string.c_str());
	std::cout << "double: " << doubleValue << std::endl;

	if (doubleValue >= std::numeric_limits<char>::min() && doubleValue <= std::numeric_limits<char>::max())
	{
		char charValue = static_cast<char>(doubleValue);
		if (std::isprint(charValue))
			std::cout << "char: '" << charValue << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
	}

	int intValue = static_cast<int>(doubleValue);
	std::cout << "int: " << intValue << std::endl;

	float floatValue = static_cast<float>(doubleValue);
	std::cout << "float: " << floatValue << "f" << std::endl;
}
