#include "Bureaucrat.hpp"

void testValidConstruction();
void testInvalidConstruction();
void testGradeIncrementDecrement();


int main(void)
{
    try
    {
        testValidConstruction();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "---" << std::endl;

    try
    {
        testInvalidConstruction();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "---" << std::endl;

    try
    {
        testGradeIncrementDecrement();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return (EXIT_SUCCESS);
}


void testValidConstruction()
{
    std::cout << "Testing valid Bureaucrat construction:" << std::endl;
    try
    {
        Bureaucrat b1("Alice", 1);
        std::cout << b1.getName() << " has grade " << b1.getGrade() << std::endl;
        
        Bureaucrat b2("Bob", 150);
        std::cout << b2.getName() << " has grade " << b2.getGrade() << std::endl;
        
        Bureaucrat b3("Charlie", 75);
        std::cout << b3.getName() << " has grade " << b3.getGrade() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}


void testInvalidConstruction()
{
    std::cout << "Testing invalid Bureaucrat construction:" << std::endl;
    try
    {
        Bureaucrat b4("David", 0);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b5("Eve", 151);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}


void testGradeIncrementDecrement()
{
    std::cout << "Testing grade incrementing and decrementing:" << std::endl;
    try
    {
        Bureaucrat b6("Frank", 2);
        std::cout << b6.getName() << " has grade " << b6.getGrade() << std::endl;

        b6.increase_grade(1);
        std::cout << b6.getName() << " has grade " << b6.getGrade() << std::endl;

        b6.decrease_grade(1);
        std::cout << b6.getName() << " has grade " << b6.getGrade() << std::endl;
        
        b6.increase_grade(1);
        std::cout << b6.getName() << " has grade " << b6.getGrade() << std::endl;
        b6.increase_grade(1);
        std::cout << b6.getName() << " has grade " << b6.getGrade() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    try
    {
        Bureaucrat b7("Grace", 149);
        std::cout << b7.getName() << " has grade " << b7.getGrade() << std::endl;

        b7.decrease_grade(1);
        std::cout << b7.getName() << " has grade " << b7.getGrade() << std::endl;

        b7.decrease_grade(1);
        std::cout << b7.getName() << " has grade " << b7.getGrade() << std::endl;
        
        b7.decrease_grade(1);
        std::cout << b7.getName() << " has grade " << b7.getGrade() << std::endl;

    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
}
