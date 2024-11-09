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

// Minimum/Maximum functions

Fixed & Fixed::min(Fixed &other_1, Fixed &other_2)
{
	if (other_1.getRawBits() < other_2.getRawBits())
		return (other_1);
	return (other_2);
}

const Fixed & Fixed::min(Fixed const &other_1, Fixed const &other_2)
{
	if (other_1.getRawBits() < other_2.getRawBits())
		return (other_1);
	return (other_2);
}

Fixed &Fixed::max(Fixed &other_1, Fixed &other_2)
{
	if (other_1.getRawBits() > other_2.getRawBits())
		return (other_1);
	return (other_2);
}

const Fixed & Fixed::max(Fixed const &other_1, Fixed const &other_2)
{
	if (other_1.getRawBits() > other_2.getRawBits())
		return (other_1);
	return (other_2);
}

/*
Operator overloading
*/

// iostream overloading

std::ostream& operator<<(std::ostream &os, Fixed const &other)
{
	os << other.toFloat();
	return os;
}

// Arithmetic operators

Fixed Fixed::operator+(Fixed const &other) const
{
	Fixed ret(this->toFloat() + other.toFloat());
	return (ret);
}

Fixed Fixed::operator-(Fixed const &other) const
{
	Fixed ret(this->toFloat() - other.toFloat());
	return (ret);
}

Fixed Fixed::operator*( Fixed const &other) const
{
	Fixed ret(this->toFloat() * other.toFloat());
	return (ret);
}

Fixed Fixed::operator/( Fixed const &other) const
{
	if (other.toFloat() == 0)
	{
		std::cerr << "Division by zero" << std::endl;
		Fixed ret(69420);
		return (ret);
	}
	Fixed ret(this->toFloat() / other.toFloat());
	return (ret);
}


// Comparism operators

bool Fixed::operator>(Fixed const &other) const
{
	if (getRawBits() <= other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(Fixed const &other) const
{
	if (getRawBits() >= other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(Fixed const &other) const
{
	if (getRawBits() > other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(Fixed const &other) const
{
	if (getRawBits() > other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(Fixed const &other) const
{
	if (getRawBits() == other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(Fixed const &other) const
{
	if (getRawBits() != other.getRawBits())
		return (true);
	return (false);
}

// Increment/decrement operators

Fixed Fixed::operator++()
{
	FixedPointNumber += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->FixedPointNumber++;
	return (temp);
}

Fixed Fixed::operator--()
{
	FixedPointNumber -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->FixedPointNumber++;
	return (temp);
}