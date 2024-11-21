#include "Animal.hpp"

Animal::Animal()
{
    type = "Animal";
    std::cout << "Animal class: Default constructor called" << std::endl;
}


Animal::Animal(Animal const &other)
{
    if(this != &other)
    {
        this->type = other.type;
    }
}


Animal::~Animal()
{
    std::cout << "Animal class: Destructor called" << std::endl;
}


Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}


void Animal::makeSound(void) const
{
    std::cout << "Generic animal sound.." << std::endl;
}


std::string Animal::getType(void) const 
{
    return (type);
}
