#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog class: Default constructor called" << std::endl;
}

Dog::Dog(Dog const &obj)
{
    if(this != &obj)
    {
        this->type = obj.type;
    }
}

Dog::~Dog()
{
    std::cout << "Dog class: Destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
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
