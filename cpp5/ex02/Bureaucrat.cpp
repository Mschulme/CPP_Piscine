#include "AForm.hpp"
#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat()
{
    std::cout << "Constructor called." << std::endl;
}


Bureaucrat::Bureaucrat(const std::string &str, int grade)
{
    std::cout << "Parametrized constructor called: " << name_bureaucrat << std::endl;
    name_bureaucrat = str;
    grade_bureaucrat = grade;
    if (grade_bureaucrat < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade_bureaucrat > 150)
        throw Bureaucrat::GradeTooLowException();
}


Bureaucrat::~Bureaucrat()
{
    std::cout << "Destrucutor called: " << name_bureaucrat << std::endl;
}


Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    std::cout << "Copy constructor called" << std::endl;
    name_bureaucrat = other.name_bureaucrat;
    grade_bureaucrat = other.grade_bureaucrat;
}


Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Assignment operator called" << std::endl;
    if (this != &other)
    {
        name_bureaucrat = other.name_bureaucrat;
        grade_bureaucrat = other.grade_bureaucrat;
    }
    return *this;
}


void Bureaucrat::increase_grade(int grade_change)
{
    try
    {
        if (grade_bureaucrat - grade_change < 1)
            throw Bureaucrat::GradeTooHighException();
        else if (grade_bureaucrat - grade_change > 150)
            throw Bureaucrat::GradeTooLowException();
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
        if (grade_bureaucrat + grade_change < 1)
          throw Bureaucrat::GradeTooHighException();
        else if (grade_bureaucrat + grade_change > 150)
          throw Bureaucrat::GradeTooLowException();
        else grade_bureaucrat = grade_bureaucrat + grade_change;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}


std::string Bureaucrat::getName(void)
{
    return (name_bureaucrat);
}


int Bureaucrat::getGrade(void) const
{
    return (grade_bureaucrat);
}


void Bureaucrat::signForm(AForm &form)
{
    try
    { 
        form.beSigned(*this); 
        std::cout << name_bureaucrat << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << name_bureaucrat << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    } 
    
}


void Bureaucrat::executeForm(AForm const &form) const
{
    try
    {
        form.execute(*this);
        std::cout << name_bureaucrat << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << name_bureaucrat << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
    }
}


const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("The Grade is too low. Please enter a value between 1 and 150.");
}


const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("The Grade is too  high. Please enter a value between 1 and 150.");
}


std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
	o << a->getName() << ", bureaucrat grade " << a->getGrade() << "." << std::endl;
	return (o);
}
