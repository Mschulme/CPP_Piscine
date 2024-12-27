#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

#include <cmath>
#include <string>
#include <limits>
#include <cerrno>
#include <cctype>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <stdexcept>


enum Type {CHARACTER, INTEGER, FLOAT, DOUBLE, INVALID};


class ScalarConverter
{
	public:
		static void	convert(const std::string& literal);
	
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &obj);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &obj);

		static Type detectType(const std::string &input);

		static bool isCharacter(const std::string &input);
		static bool isInteger(const std::string &input);
		static bool isFloat(const std::string &input);
		static bool isDouble(const std::string &input);

		static void convertCharacter(const std::string &input);
		static void convertInteger(const std::string &input);
		static void convertFloat(const std::string &input);
		static void convertDouble(const std::string &input);

		static void printCharacter(double value);
		static void printInteger(double value);

		static void printFloat(float value);
		static void printFloat(float value, int precision);
		static void printDouble(double value);
		static void printDouble(double value, int precision);

		static int countDecimalDigits(const std::string &input);
};

#endif
