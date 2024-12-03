#include "WrongCat.hpp"


WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat class: Default constructor called" << std::endl;
}


WrongCat::WrongCat(WrongCat const &other) : WrongAnimal(other)
{
    if(this != &other)
    {
        this->type = other.type;
    }
    std::cout << "WrongCat class: Copy constructor called" << std::endl;
}


WrongCat::~WrongCat()
{
    std::cout << "WrongCat class: Destructor called" << std::endl;
}


WrongCat &WrongCat::operator=(const WrongCat &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    std::cout << "WrongCat class: Assignment operator called" << std::endl;
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
