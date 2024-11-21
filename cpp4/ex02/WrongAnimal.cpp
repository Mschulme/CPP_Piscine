#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    type = "WrongAnimal";
    std::cout << "WrongAnimal class: Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &obj)
{
    if(this != &obj)
    {
        this->type = obj.type;
    }
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal class: Destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return (*this);
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "Generic WrongAnimal sound.." << std::endl;
}

std::string WrongAnimal::getType(void) const 
{
    return (type);
}
