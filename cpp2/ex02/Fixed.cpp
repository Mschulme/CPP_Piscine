#include "Fixed.hpp"

Fixed::Fixed(void)
{
    FixedPointNumber = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer_input)
{
    std::cout << "Integer constructor called" << std::endl;
    setRawBits(integer_input * (1 << number_of_fractional_bits));
}

Fixed::Fixed(const float float_input)
{
    std::cout << "Float constructor called" << std::endl;
    this->setRawBits((int)roundf(float_input * (1 << number_of_fractional_bits)));
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

void    Fixed::setRawBits( int const raw )
{
    FixedPointNumber = raw;
}

float Fixed::toFloat(void) const
{
    float   f;

    f = (float)getRawBits() / (1 << number_of_fractional_bits);
    return (f);
}

int Fixed::toInt(void) const
{
    return (getRawBits() >> number_of_fractional_bits);
}


// Minimum/Maximum functions


Fixed &Fixed::min(Fixed &other_1, Fixed &other_2)
{
    if (other_1.getRawBits() < other_2.getRawBits())
        return (other_1);
    return (other_2);
}

const Fixed &Fixed::min(Fixed const &other_1, Fixed const &other_2)
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

const Fixed &Fixed::max(Fixed const &other_1, Fixed const &other_2)
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
    return os << other.toFloat();
}


// Arithmetic operators


Fixed Fixed::operator+(Fixed const &other) const
{ 
    return Fixed(this->toFloat() + other.toFloat());
}


Fixed Fixed::operator-(Fixed const &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(Fixed const &other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(Fixed const &other) const
{
    if (other.toFloat() == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed(0);
    }
    return Fixed(this->toFloat() / other.toFloat());
}


// Comparison operators


bool Fixed::operator>(Fixed const &other) const
{
    return getRawBits() > other.getRawBits();
}

bool Fixed::operator<(Fixed const &other) const
{
    return getRawBits() < other.getRawBits();
}

bool Fixed::operator<=(Fixed const &other) const
{
    return getRawBits() <= other.getRawBits();
}

bool Fixed::operator>=(Fixed const &other) const
{
    return getRawBits() >= other.getRawBits();
}

bool Fixed::operator==(Fixed const &other) const
{
    return getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(Fixed const &other) const
{
    return getRawBits() != other.getRawBits();
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
    this->FixedPointNumber--;
    return (temp);
}
