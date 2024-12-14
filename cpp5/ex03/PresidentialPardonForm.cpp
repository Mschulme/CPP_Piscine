#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
 : AForm("PresidentialPardonForm", 25, 5), target(target)
{
    std::cout << "Parametrized constructor called: PresidentialPardonForm" << std::endl;
}


PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "Destructor called: PresidentialPardonForm" << std::endl;
}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other), target(other.target)
{
    std::cout << "Copy Constructor called: PresidentialPardonForm" << std::endl;
}


PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    std::cout << "Assignment operator called: PresidentialPardonForm" << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}


void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if(getIsSigned() == false)
    {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute())
    {
        throw GradeTooLowException();
    }
    PresidentialPardonForm::announcePardon();
}


void PresidentialPardonForm::announcePardon(void) const
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
