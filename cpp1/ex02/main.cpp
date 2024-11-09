#include <string>
#include <cstdlib>
#include <iostream>

int	main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "List of memory addresses:" << std::endl;
	std::cout << "\t The memory address of the string variable: " << &string << std::endl;
	std::cout << "\t The memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "\t The memory address held by stringREF " << &stringREF << std::endl;

	std::cout << "List of values:" << std::endl;
	std::cout << "\t The value of the string variable: " << string << std::endl;
	std::cout << "\t The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "\t The value pointed to by stringREF: " << stringREF << std::endl;

	return (EXIT_SUCCESS);
}
