#include "Bureaucrat.hpp"
#include "Form.hpp"

void testConstruction();


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

    return (EXIT_SUCCESS);
}


void testConstruction()
{
    std::cout << "Testing Form construction:" << std::endl;
    try
    {
        Form b1("Arthur", 50, 50);
        std::cout << &b1;

        Form b2("Merlin", -50, 50);
        std::cout << &b2;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}


