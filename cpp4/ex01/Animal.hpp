#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <cstdlib>
#include <iostream>

class Animal
{
    public:
        Animal();
        Animal(Animal const &other);
        virtual ~Animal();
        Animal &operator=(const Animal &other);

        virtual void makeSound(void) const;
        virtual std::string getType(void) const;

    protected:
        std::string type;
};

#endif
