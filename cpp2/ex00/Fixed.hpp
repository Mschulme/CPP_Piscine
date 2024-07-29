#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>

class Fixed
{
	private:
		int FixedPointNumber;
		static const int number_of_fractional_bits = 8;
	public:
		Fixed(); // Constructor
		~Fixed(); // Destructor
		Fixed(const Fixed& other); // Copy constructor
		Fixed& operator = (const Fixed& other); // Assignment operator
		
		// member functions

		int getRawBits(void) const;
		void setRawBits(int const raw);

};

#endif
