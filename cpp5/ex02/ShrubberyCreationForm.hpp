#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private: 
        std::string target;
        void createShrubberyFile(void) const;

    public:
        ShrubberyCreationForm(const std::string &target);
        virtual ~ShrubberyCreationForm(void);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

        virtual void execute(Bureaucrat const &executor) const;
    
};

#endif
