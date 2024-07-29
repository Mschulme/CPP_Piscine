#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <exception>

class Fixed
{
	private:
		int FixedPointNumber;
		static const int number_of_fractional_bits = 8;

	public:
		Fixed();
		Fixed(int const integer_input);
		Fixed(float const float_input);

		Fixed(const Fixed& other); // Copy constructor
		~Fixed(); // Destructor
		Fixed& operator = (const Fixed& other); // Assignment operator

		int getRawBits(void) const;
		void setRawBits(int const raw);

		int toInt(void) const;
		float toFloat(void) const;

		// min/max overloaded functions

		static Fixed & min(Fixed &other_1, Fixed &other_2);
		static const Fixed & min(Fixed const &other_1, Fixed const &other_2);
		static Fixed & max(Fixed &other_1, Fixed &other_2);
		static const Fixed & max(Fixed const &other_1, Fixed const &other_2);

		// Operator overloading

		//Arithmetic operators
		Fixed operator+(Fixed const &other) const;
		Fixed operator-(Fixed const &other) const;
		Fixed operator*(Fixed const &other) const;
		Fixed operator/(Fixed const &other) const;

		// Comparism operators
		bool operator>(Fixed const &other) const;
		bool operator<(Fixed const &other) const;
		bool operator>=(Fixed const &other) const;
		bool operator<=(Fixed const &other) const;
		bool operator==(Fixed const &other) const;
		bool operator!=(Fixed const &other) const;

		// Increment/decrement operators
		// https://learn.microsoft.com/de-de/cpp/cpp/increment-and-decrement-operator-overloading-cpp?view=msvc-170
		Fixed operator++();
		Fixed operator++(int);
		Fixed operator--();
		Fixed operator--(int);

};

std::ostream &operator<<(std::ostream &os, Fixed const &other);


#endif
