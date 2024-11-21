#ifndef DOG_HPP
#define DOG_HPP

#include <cstdlib>
#include <iostream>
#include "Animal.hpp" 

class Dog : public Animal
{
    public:
        Dog();
        Dog(Dog const &other);
        ~Dog();
        Dog &operator=(const Dog &other);

        void makeSound(void) const;
        std::string getType(void) const;

    protected:
        std::string type;
};

#endif
