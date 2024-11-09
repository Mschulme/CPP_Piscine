#include "Fixed.hpp"


Fixed::Fixed(void)
{
	FixedPointNumber = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer_input)
{
	std::cout << "Integer constructor called" << std::endl;
	//visualizeBitShift_integer(integer_input);
	setRawBits(integer_input << number_of_fractional_bits);
}

Fixed::Fixed(const float float_input)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits((int)roundf(float_input * pow(2, this->number_of_fractional_bits))); // Scale float by 2^8
}

Fixed::Fixed(const Fixed& other)
{
	FixedPointNumber = other.FixedPointNumber;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		FixedPointNumber = other.FixedPointNumber;
	}
	return *this;
}

int Fixed::getRawBits(void) const
{
	return (FixedPointNumber);
}

void	Fixed::setRawBits(int const raw)
{
	FixedPointNumber = raw;
}

float Fixed::toFloat(void) const
{
	float	f;

	f = (float)getRawBits() / (pow(2, number_of_fractional_bits));
	return (f);
}

int Fixed::toInt(void) const
{
	return (getRawBits() >> number_of_fractional_bits);
}

std::ostream& operator<<(std::ostream &os, Fixed const &other)
{
    os << other.toFloat();
    return os;
}

// Visualization of the bitshift 

void Fixed::visualizeBitShift_integer(int integer_input)
{
    std::cout << "Original integer: " << integer_input << std::endl;
    std::cout << "Binary representation: " << std::bitset<32>(integer_input) << std::endl;

    int shifted_value = integer_input << number_of_fractional_bits;

    std::cout << "After left shift by " << number_of_fractional_bits << " bits: " << std::endl;
    std::cout << "Binary representation: " << std::bitset<32>(shifted_value) << std::endl;
}
