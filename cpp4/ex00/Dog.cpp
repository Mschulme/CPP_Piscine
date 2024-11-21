#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog class: Default constructor called" << std::endl;
}


Dog::Dog(Dog const &other) : Animal(other)
{
    if(this != &other)
    {
        this->type = other.type;
    }
}


Dog::~Dog()
{
    std::cout << "Dog class: Destructor called" << std::endl;
}


Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}


void Dog::makeSound(void) const
{
    std::cout << "Dog Barks" << std::endl;
}


std::string Dog::getType(void) const
{
    return (type);
}
