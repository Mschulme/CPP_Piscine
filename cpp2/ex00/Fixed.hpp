#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
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
		~Fixed();
		Fixed(const Fixed& other);
		Fixed& operator = (const Fixed& other);
		
		// member functions

		int getRawBits(void) const;
		void setRawBits(int const raw);

};

#endif
