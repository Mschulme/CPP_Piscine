#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat class: Default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &obj) : WrongAnimal(obj)
{
    if(this != &obj)
    {
        this->type = obj.type;
    }
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat class: Destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return (*this);
}

void WrongCat::makeSound(void) const
{
    std::cout << "Generic WrongCat sound.." << std::endl;
}

std::string WrongCat::getType(void) const 
{
    return (type);
}
