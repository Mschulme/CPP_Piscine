#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include <cstdlib>
#include <string>

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(WrongCat const &obj);
        ~WrongCat();
        WrongCat &operator=(const WrongCat &obj);

        void makeSound(void) const;
        std::string getType(void) const;

    protected:
        std::string type;

};

#endif
