#include "Fixed.hpp"

// Orthodox canonical form

Fixed::Fixed()
{
	FixedPointNumber = 0;
	std::cout << "Fixed: Default Constructor called." << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Fixed: Copy Constructor called." << std::endl;
	FixedPointNumber = other.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Fixed: Destructor called." << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Fixed: Copy assignment operator called." << std::endl;
	if (this != &other)
		setRawBits(other.getRawBits());
	return *this;
}

// Member functions

int Fixed::getRawBits( void ) const
{
	std::cout << "Fixed: getRawBits member function called." << std::endl;
	return (FixedPointNumber);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "Fixed: setRawBits member function called." << std::endl;
	FixedPointNumber = raw;
}
