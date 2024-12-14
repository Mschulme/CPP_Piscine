#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    std::cout << "Constructor called: ShrubberyCreationForm" << std::endl;
}


ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "Destructor called: ShrubberyCreationForm" << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target)
{
    std::cout << "Copy Constructor called: ShrubberyCreationForm" << std::endl;
}


ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    std::cout << "Assignment operator called: ShrubberyCreationForm" << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}


void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if(getIsSigned() == false)
    {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute())
    {
        throw GradeTooLowException();
    }
    ShrubberyCreationForm::createShrubberyFile();
}


void ShrubberyCreationForm::createShrubberyFile(void) const
{
    std::ofstream ofs((target + "_shrubbery").c_str());
    if (ofs.is_open())
    {
        ofs << "_                                      =   (\n";
        ofs << "                                        255,\n";
        ofs << "                                      lambda\n";
        ofs << "                               V       ,B,c\n";
        ofs << "                             :c   and Y(V*V+B,B,  c\n";
        ofs << "                               -1)if(abs(V)<6)else\n";
        ofs << "               (              2+c-4*abs(V)**-0.4)/i\n";
        ofs << "                 )  ;v,      x=1500,1000;C=range(v*x\n";
        ofs << "                  );import  struct;P=struct.pack;M,\\\n";
        ofs << "            j  ='<QIIHHHH',open('M.bmp','wb').write\n";
        ofs << "for X in j('BM'+P(M,v*x*3+26,26,12,v,x,1,24))or C:\n";
        ofs << "            i  ,Y=_;j(P('BBB',*(lambda T:(T*80+T**9\n";
        ofs << "                  *i-950*T  **99,T*70-880*T**18+701*\n";
        ofs << "                 T  **9     ,T*i**(1-T**45*2)))(sum(\n";
        ofs << "               [              Y(0,(A%3/3.+X%v+(X/v+\n";
        ofs << "                               A/3/3.-x/2)/1j)*2.5\n";
        ofs << "                             /x   -2.7,i)**2 for  \\\n";
        ofs << "                               A       in C\n";
        ofs << "                                      [:9]])\n";
        ofs << "                                        /9)\n";
        ofs << "                                       )   )\n";
    }
    else
    {
        std::cerr << "Error: Could not create file " << target << "_shrubbery" << std::endl;
    }
}
