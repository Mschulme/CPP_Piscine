#include "Dog.hpp"

Dog::Dog() : brain (new Brain())
{
    type = "Dog";
    std::cout << "Dog class: Default constructor called" << std::endl;
}

Dog::Dog(Dog const &obj) : Animal(obj), brain(new Brain(*obj.brain))
{
    if(this != &obj)
    {
        this->type = obj.type;
    }
    std::cout << "Dog class: Copy constructor called" << std::endl;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog class: Destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
        if (brain != NULL)
        {
            delete brain;
        }
        brain = new Brain(*obj.brain);
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

void Dog::printBrain(void) const
{
    brain->printIdeas();
}
