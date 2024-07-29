#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <cstdlib>
#include <string>

class WrongAnimal
{
    public:
        WrongAnimal();
        WrongAnimal(WrongAnimal const &obj);
        ~WrongAnimal();
        WrongAnimal &operator=(const WrongAnimal &obj);

        void makeSound(void) const;
        std::string getType(void) const;

    protected:
        std::string type;

};

#endif
