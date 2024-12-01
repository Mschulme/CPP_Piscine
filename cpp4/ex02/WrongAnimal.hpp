#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <cstdlib>
#include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal();
        ~WrongAnimal();
        WrongAnimal(WrongAnimal const &other);
        WrongAnimal &operator=(const WrongAnimal &other);

        void makeSound(void) const;
        std::string getType(void) const;

    protected:
        std::string type;

};

#endif
