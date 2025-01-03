#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : name_bureaucrat("Default"), grade_bureaucrat(42)
{
    std::cout << "Constructor called." << std::endl;
}


Bureaucrat::Bureaucrat(const std::string &str, int grade)
    : name_bureaucrat(str), grade_bureaucrat(grade)
{
    std::cout << "Parametrized constructor called: " << name_bureaucrat << std::endl;
    if (grade_bureaucrat < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade_bureaucrat > 150)
        throw Bureaucrat::GradeTooLowException();
}


Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called: " << name_bureaucrat << std::endl;
}


Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name_bureaucrat(other.name_bureaucrat), grade_bureaucrat(other.grade_bureaucrat)
{
    std::cout << "Copy constructor called" << std::endl;
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
    if (grade_bureaucrat - grade_change < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade_bureaucrat - grade_change > 150)
        throw Bureaucrat::GradeTooLowException();
    grade_bureaucrat -= grade_change;
}


void Bureaucrat::decrease_grade(int grade_change)
{
    if (grade_bureaucrat + grade_change < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade_bureaucrat + grade_change > 150)
        throw Bureaucrat::GradeTooLowException();
    grade_bureaucrat += grade_change;
}


std::string Bureaucrat::getName(void) const
{
    return (name_bureaucrat);
}


int Bureaucrat::getGrade(void) const
{
    return (grade_bureaucrat);
}


void Bureaucrat::signForm(Form &form)
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


const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("The Grade is too low. Please enter a value between 1 and 150.");
}


const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("The Grade is too  high. Please enter a value between 1 and 150.");
}


std::ostream	&operator<<(std::ostream &o, const Bureaucrat &a)
{
	o << a.getName() << ", bureaucrat grade " << a.getGrade() << "." << std::endl;
	return (o);
}
