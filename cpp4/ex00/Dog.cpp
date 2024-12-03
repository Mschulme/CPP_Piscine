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
    std::cout << "Dog class: Copy constructor called" << std::endl;
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
    std::cout << "Dog class: Assignment operator called" << std::endl;
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
