#include "Form.hpp"
#include "Bureaucrat.hpp"

void testConstruction();
void testSignExecution();

int main(void)
{
	try
	{
		testConstruction();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

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


void testConstruction()
{
	std::cout << "Testing Form construction:" << std::endl;
	try
	{
		Form Form_1("Form_1", 50, 50);
		std::cout << Form_1;

		Form Form_2("Form_2", -50, 50);
		std::cout << Form_2;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}


void testSignExecution()
{
	std::cout << "Testing invalid sign form:" << std::endl;
	try
	{
		Bureaucrat Merlin("Arthur", 65);
		Form Form_3("Form_3", 50, 50);
		Merlin.signForm(Form_3);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "---" << "\n" << "Testing valid sign form:" << std::endl;
	try
	{
		Bureaucrat Merlin("Arthur", 65);
		Form Form_3("Form_3", 100, 50);
		std::cout << Form_3;
		Merlin.signForm(Form_3);
		std::cout << Form_3;
		std::cout << "Check if Form is signed: " << (Form_3.getIsSigned() ? "true" : "false") << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
