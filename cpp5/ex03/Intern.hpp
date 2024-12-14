#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <string>
#include <iostream>

class Intern
{
    private:
        static AForm* createShrubberyCreationForm(const std::string &t);
        static AForm* createRobotomyRequestForm(const std::string &t);
        static AForm* createPresidentialPardonForm(const std::string &t);

    public:
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();

        AForm *makeForm(const std::string &formName, const std::string &target) const;
};

#endif