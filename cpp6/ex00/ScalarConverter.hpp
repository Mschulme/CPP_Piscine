#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

#include <cmath>
#include <limits>
#include <cstdio>
#include <cstdlib>
#include <iostream>


enum Type {CHARACTER, INTEGER, FLOAT, DOUBLE, INVALID};


class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &obj);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &obj);

		static void convert(const std::string& literal);

		static Type			type_of_input_string(const std::string &input_string);
		static std::string	TypeToString(Type type);
		static void			input_string_is_char(const std::string &input_string);
		static void			input_string_is_int(const std::string &input_string);
		static void			input_string_is_float(const std::string &input_string);
		static void			input_string_is_double(const std::string &input_string);
};

#endif
