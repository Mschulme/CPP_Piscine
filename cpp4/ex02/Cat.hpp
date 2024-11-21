#ifndef Cat_HPP
#define Cat_HPP

#include <cstdlib>
#include <iostream>
#include "Brain.hpp"
#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(Cat const &obj);
        ~Cat();
        Cat &operator=(const Cat &obj);

        void makeSound(void) const;
        std::string getType(void) const;
        void printBrain(void) const;


    protected:
        std::string type;
        Brain *brain;
};

#endif
