#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <cstdlib>

#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(Dog const &obj);
        ~Dog();
        Dog &operator=(const Dog &obj);

        void makeSound(void) const;
        std::string getType(void) const;

    protected:
        std::string type;
};

#endif
