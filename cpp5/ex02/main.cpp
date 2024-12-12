#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

void testSignExecution();

int main(void)
{
	try
	{
		testSignExecution();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (EXIT_SUCCESS);
}


void testSignExecution()
{
	std::cout << "Testing invalid sign form:" << std::endl;
	try
	{
		Bureaucrat Merlin("Arthur", 65);
		ShrubberyCreationForm Form_3("Hero");
        Form_3.createShrubberyFile();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << "\n" << "Testing valid sign form:" << std::endl;
}
