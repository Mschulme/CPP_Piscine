#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target(target)
{
    std::cout << "Constructor called: RobotomyRequestForm" << std::endl;
}


RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "Destructor called: RobotomyRequestForm" << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target(other.target)
{
    std::cout << "Copy Constructor called: RobotomyRequestForm" << std::endl;
}


RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    std::cout << "Assignment operator called: RobotomyRequestForm" << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}


void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if(getIsSigned() == false)
    {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute())
    {
        throw GradeTooLowException();
    }
    std::cout << "* BZZZZZZZ... DRRRRRRRR... *" << std::endl;

    int outcome = std::rand() % 2;
    if (outcome == 0)
    {
        std::cout << target << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "Robotomy failed on " << target << "!" << std::endl;
    }
}
