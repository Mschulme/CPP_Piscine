#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <string>
#include <cstdlib>
#include <iostream>

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(WrongCat const &other);
        ~WrongCat();
        WrongCat &operator=(const WrongCat &other);

        void makeSound(void) const;
        std::string getType(void) const;

    protected:
        std::string type;
};

#endif
