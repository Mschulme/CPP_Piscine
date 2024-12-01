#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    type = "WrongAnimal";
    std::cout << "WrongAnimal class: Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other)
{
    if(this != &other)
    {
        this->type = other.type;
    }
    std::cout << "WrongAnimal class: Copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal class: Destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    std::cout << "WrongAnimal class: Assignment operator called" << std::endl;
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
