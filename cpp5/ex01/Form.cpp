#include "Form.hpp"

Form::Form(void) : name("default"), isSigned(false), gradeToSign(42), gradeToExecute(42)
{
    std::cout << "Constructor called." << std::endl;
}


Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150)
        throw Form::GradeTooLowException();
    else if (gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToExecute > 150)
        throw Form::GradeTooLowException();
}


Form::~Form()
{
    std::cout << "Destrucutor called: " << name << std::endl;
}


Form::Form(const Form &other): name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    std::cout << "Copy constructor called" << std::endl;
}


Form &Form::operator=(const Form &other)
{
    std::cout << "Assignment operator called" << std::endl;
    if (this != &other)
    {
        isSigned = other.isSigned;
        // Note: name, gradeToSign, and gradeToExecute are const and cannot be assigned
    }
    return *this;
}


void Form::beSigned(Bureaucrat &bureaucrat)
{ 
    if (bureaucrat.getGrade() > gradeToSign) 
    { 
        throw Form::GradeTooLowException();
    }
    isSigned = true;
}

std::string Form::getName(void)
{
    return name;
} 


bool Form::getIsSigned(void)
{
    return isSigned;
} 


int Form::getGradeToSign(void)
{
    return gradeToSign;
} 


int Form::getGradeToExecute(void)
{ 
    return gradeToExecute;
}


const char *Form::GradeTooLowException::what(void) const throw()
{
    return ("The Grade is too low to sign / execute. Please enter a value between 1 and 150.");
}


const char *Form::GradeTooHighException::what(void) const throw()
{
    return ("The Grade is too high to sign / execute. Please enter a value between 1 and 150.");
}


std::ostream	&operator<<(std::ostream &o, Form *a)
{
	o << "Name: " << a->getName() << " is signed: " <<a->getIsSigned() << " Grade to sign: " << a->getGradeToSign() << " Grade to execute: " << a->getGradeToExecute()  << std::endl;
	return (o);
}
