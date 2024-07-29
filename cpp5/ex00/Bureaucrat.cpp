#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &str, int grade)
{
    name_bureaucrat = str;
    grade_bureaucrat = grade;

}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destrucutor: " << name_bureaucrat << std::endl;
}


void Bureaucrat::increase_grade(int grade_change)
{
    try
    {
        if (grade_bureaucrat - grade_change < 0)
            throw std::invalid_argument("GradeTooLow");
        else if (grade_bureaucrat - grade_change > 150)
            throw std::invalid_argument("GradeTooLow");
        else grade_bureaucrat = grade_bureaucrat - grade_change;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void Bureaucrat::decrease_grade(int grade_change)
{
    try
    {
        if (grade_bureaucrat + grade_change < 0)
            throw std::invalid_argument("GradeTooLow");
        else if (grade_bureaucrat + grade_change > 150)
            throw std::invalid_argument("GradeTooLow");
        else grade_bureaucrat = grade_bureaucrat + grade_change;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}


const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return("The Grade is too low. Please enter a value between 0 and 150.");
}


const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return("The Grade is too  high. Please enter a value between 0 and 150.");
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
	o << "Bureaucrat " << a->getName() << ":\n\tgrade: " << a->getGrade() << std::endl;
	return (o);
}


std::string Bureaucrat::getName(void)
{
    return (name_bureaucrat);
}


int Bureaucrat::getGrade(void)
{
    return (grade_bureaucrat);
}
