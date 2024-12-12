#include "AForm.hpp"

AForm::AForm(void) : name("default"), isSigned(false), gradeToSign(42), gradeToExecute(42)
{
    std::cout << "Constructor called." << std::endl;
}


AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150)
        throw AForm::GradeTooLowException();
    else if (gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}


AForm::~AForm()
{
    std::cout << "Destrucutor called: " << name << std::endl;
}


AForm::AForm(const AForm &other): name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    std::cout << "Copy constructor called" << std::endl;
}


AForm &AForm::operator=(const AForm &other)
{
    std::cout << "Assignment operator called" << std::endl;
    if (this != &other)
    {
        isSigned = other.isSigned;
        // Note: name, gradeToSign, and gradeToExecute are const and cannot be assigned
    }
    return *this;
}


void AForm::beSigned(Bureaucrat &bureaucrat)
{ 
    if (bureaucrat.getGrade() > gradeToSign) 
    { 
        throw AForm::GradeTooLowException();
    }
    isSigned = true;
}

std::string AForm::getName(void) const
{
    return name;
} 


bool AForm::getIsSigned(void) const
{
    return isSigned;
} 


int AForm::getGradeToSign(void) const
{
    return gradeToSign;
} 


int AForm::getGradeToExecute(void) const
{ 
    return gradeToExecute;
}


void AForm::execute(Bureaucrat const &executor) const
{
    (void) executor;
}


const char *AForm::GradeTooLowException::what(void) const throw()
{
    return ("The Grade is too low to sign / execute. Please enter a value between 1 and 150.");
}


const char *AForm::GradeTooHighException::what(void) const throw()
{
    return ("The Grade is too high to sign / execute. Please enter a value between 1 and 150.");
}


std::ostream	&operator<<(std::ostream &o, AForm *a)
{
	o << "Name: " << a->getName() << " is signed: " <<( a->getIsSigned() ? "true" : "false") << " Grade to sign: " << a->getGradeToSign() << " Grade to execute: " << a->getGradeToExecute()  << std::endl;
	return (o);
}
