#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"


void testSignExecution();

int main()
{
    std::srand(static_cast<unsigned>(std::time(NULL)));

    Intern someRandomIntern;
    AForm *form;

    form = someRandomIntern.makeForm("shrubbery creation", "Home");
    if (form)
    {
        Bureaucrat bob("Bob", 1);
        bob.signForm(*form);
        bob.executeForm(*form);
        delete form;
    }

    std::cout << "-------------------" << std::endl;

    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form)
    {
        Bureaucrat tina("Tina", 45);
        tina.signForm(*form);
        tina.executeForm(*form);
        delete form;
    }

    std::cout << "-------------------" << std::endl;

    form = someRandomIntern.makeForm("presidential pardon", "Marvin");
    if (form)
    {
        Bureaucrat arthur("Arthur", 1);
        arthur.signForm(*form);
        arthur.executeForm(*form);
        delete form;
    }

    std::cout << "-------------------" << std::endl;

    form = someRandomIntern.makeForm("undefined form", "Nowhere");
    if (form)
    {
        delete form;
    }

    return EXIT_SUCCESS;
}