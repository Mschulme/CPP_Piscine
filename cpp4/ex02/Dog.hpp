#ifndef Dog_HPP
#define Dog_HPP

#include <cstdlib>
#include <iostream>

#include "Brain.hpp"
#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        ~Dog();
        Dog(Dog const &other);
        Dog &operator=(const Dog &other);

        void makeSound(void) const;
        std::string getType(void) const;
        void printBrain(void) const;

    private:
        std::string type;
        Brain *brain;
};

#endif
