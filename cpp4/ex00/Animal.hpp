#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <cstdlib>
#include <string>

class Animal
{
    public:
        Animal();
        Animal(Animal const &obj);
        virtual ~Animal();
        Animal &operator=(const Animal &obj);

        virtual void makeSound(void) const;
        virtual std::string getType(void) const;

    protected:
        std::string type;

};

#endif
