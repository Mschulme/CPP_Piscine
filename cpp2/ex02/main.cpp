#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << "Value of a is: " << a << std::endl;
	std::cout << "Value of b is: " << b << std::endl;

	
	std::cout << "Value of ++a is: " << ++a << std::endl;
	std::cout << "Value of a++ is: " << a++ << std::endl;

	std::cout << "Value of min(a, b) is: " << Fixed::min(a, b) << std::endl;
	std::cout << "Value of max(a, b) is: " << Fixed::max(a, b) << std::endl;

	std::cout << "Value of a + b is: " <<  a + b << std::endl;

	std::cout << "Value of a - b is: " <<  a - b << std::endl;

	Fixed c(2);
	Fixed d(0);
	std::cout << "Value of c is: " << c << std::endl;
	std::cout << "Value of d is: " << d << std::endl;
	std::cout << "Value of c / d is: " <<  c / d << std::endl;


	return (EXIT_SUCCESS);
}
