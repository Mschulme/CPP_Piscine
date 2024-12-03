#include "Dog.hpp"

Dog::Dog() : brain (new Brain())
{
    type = "Dog";
    std::cout << "Dog class: Default constructor called" << std::endl;
}

Dog::Dog(Dog const &other) : Animal(other) ,brain(new Brain(*other.brain))
{
    if(this != &other)
    {
        this->type = other.type;
    }
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog class: Destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        this->type = other.type;
        if (brain != NULL)
        {
            delete brain;
        }
        brain = new Brain(*other.brain);
    }
    std::cout << "Dog class: Assignment operator called" << std::endl;
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "Dog Meows" << std::endl;
}

std::string Dog::getType(void) const 
{
    return (type);
}

void Dog::printBrain(void) const
{
    brain->printIdeas();
}
