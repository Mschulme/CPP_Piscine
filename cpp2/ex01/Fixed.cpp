#include "Fixed.hpp"

// Orthodox canonical form

Fixed::Fixed(void)
{
	FixedPointNumber = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer_input)
{
	std::cout << "Integer constructor called" << std::endl;
	setRawBits(integer_input << number_of_fractional_bits);
}

Fixed::Fixed(const float float_input)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits((int)roundf(float_input * (1 << this->number_of_fractional_bits)));
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

// Functions

int Fixed::getRawBits( void ) const
{
	return (FixedPointNumber);
}

void	Fixed::setRawBits( int const raw )
{
	FixedPointNumber = raw;
}

float Fixed::toFloat(void) const
{
	float	f;

	f = (float)getRawBits() / (1 << number_of_fractional_bits);
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
