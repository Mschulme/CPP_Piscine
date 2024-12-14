#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"


void testSignExecution();

int main(void)
{
	std::srand(static_cast<unsigned>(time(NULL)));
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
    std::cout << "Testing execution on an unsigned form:" << std::endl;
    try
    {
        Bureaucrat Arthur("Arthur", 65);
        ShrubberyCreationForm form1("Garden");
        Arthur.executeForm(form1);  
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "---" << "\n" << "Testing sign and then execute:" << std::endl;
    try
    {
        Bureaucrat Arthur("Arthur", 65);
        ShrubberyCreationForm form2("Mandelbrot");
        Arthur.signForm(form2);
        Arthur.executeForm(form2);
    }
    catch (std::exception &e)
    {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    std::cout << "---" << "\n" << "Testing execution with insufficient grade to execute:" << std::endl;
    try
    {
        Bureaucrat Lancelot("Lancelot", 140);
        ShrubberyCreationForm form3("Castle");
        Lancelot.signForm(form3);
        Lancelot.executeForm(form3);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

	std::cout << "---" << "\n" << "Testing PresidentialPardonForm:" << std::endl;
    try
    {
        Bureaucrat Lancelot("Lancelot", 5);
        PresidentialPardonForm form4("Castle");
        Lancelot.signForm(form4);
        Lancelot.executeForm(form4);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

	std::cout << "---" << "\n" << "Testing RobotomyRequestForm:" << std::endl;
    try
    {
        Bureaucrat Lancelot("Lancelot", 5);
        RobotomyRequestForm form5("Castle");
        Lancelot.signForm(form5);
        Lancelot.executeForm(form5);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
