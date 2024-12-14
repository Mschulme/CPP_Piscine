#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called." << std::endl;
}


Intern::Intern(const Intern &other)
{
    std::cout << "Intern copy constructor called" << std::endl;
    (void) other;
}


Intern &Intern::operator=(const Intern &other)
{
    std::cout << "Intern assignment operator called." << std::endl;
    (void)other;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called." << std::endl;
}


AForm* Intern::createShrubberyCreationForm(const std::string &t) {
    return new ShrubberyCreationForm(t);
}


AForm* Intern::createRobotomyRequestForm(const std::string &t) {
    return new RobotomyRequestForm(t);
}


AForm* Intern::createPresidentialPardonForm(const std::string &t) {
    return new PresidentialPardonForm(t);
}


AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    const std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*formCreators[3])(const std::string &) = {
        &Intern::createShrubberyCreationForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm
    };

    for (int i = 0; i < 3; ++i)
    {
        if (formName == formNames[i])
        {
            AForm *form = formCreators[i](target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }
    std::cerr << "Error: Form name \"" << formName << "\" does not exist." << std::endl;
    return NULL;
}
