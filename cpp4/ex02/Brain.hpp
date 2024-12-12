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
        ~Brain();                      
        Brain(const Brain &other);     
        Brain &operator=(const Brain &other); 

        void printIdeas(void) const;
};

#endif