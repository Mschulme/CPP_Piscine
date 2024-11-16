#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <bitset>
#include <string>
#include <cstdlib>
#include <iostream>

class Fixed
{
	private:
		int FixedPointNumber;
		static const int number_of_fractional_bits = 8;

	public:
		Fixed();
		Fixed(int const integer_input);
		Fixed(float const float_input);
		~Fixed();
		Fixed(const Fixed& other);
		Fixed& operator = (const Fixed& other);
		
		int getRawBits(void) const;
		void setRawBits(int const raw);

		int toInt(void) const;
		float toFloat(void) const;

		void visualizeBitShift_integer(int integer_input);
};

std::ostream &operator<<(std::ostream &os, Fixed const &other);

#endif
