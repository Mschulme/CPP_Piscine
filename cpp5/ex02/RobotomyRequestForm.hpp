#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <ctime>
#include <cstdlib>
#include <fstream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private: 
        std::string target;

    public:
        RobotomyRequestForm(const std::string &target);
        virtual ~RobotomyRequestForm(void);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

        virtual void execute(Bureaucrat const &executor) const;
};

#endif
