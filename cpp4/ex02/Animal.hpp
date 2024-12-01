#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <cstdlib>
#include <iostream>

class Animal
{
    public:
        Animal();
        virtual ~Animal();
        Animal(Animal const &other);
        Animal &operator=(const Animal &other);

        virtual void makeSound(void) const = 0;
        virtual std::string getType(void) const;

    protected:
        std::string type;
};

#endif
