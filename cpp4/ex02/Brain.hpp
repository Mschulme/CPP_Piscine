#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>
#include <sstream>

class Brain
{
    private:
        std::string ideas[100];
    
    public:
        Brain();                  
        Brain(const Brain &other);     
        Brain &operator=(const Brain &other); 
        ~Brain();                      

        void printIdeas(void) const;
};

#endif