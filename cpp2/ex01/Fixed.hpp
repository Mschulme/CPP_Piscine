#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <string>
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

		Fixed(const Fixed& other);
		~Fixed();
		Fixed& operator = (const Fixed& other);
		
		int getRawBits(void) const;
		void setRawBits(int const raw);

		int toInt(void) const;
		float toFloat(void) const;		
};

std::ostream &operator<<(std::ostream &os, Fixed const &other);

#endif
