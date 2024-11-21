#include "Cat.hpp"

Cat::Cat() : brain (new Brain())
{
    type = "Cat";
    std::cout << "Cat class: Default constructor called" << std::endl;
}

Cat::Cat(Cat const &other) : Animal(other) ,brain(new Brain(*other.brain))
{
    if(this != &other)
    {
        this->type = other.type;
    }
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat class: Destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
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
    std::cout << "Cat class: Assignment operator called" << std::endl;
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Cat Meows" << std::endl;
}

std::string Cat::getType(void) const 
{
    return (type);
}

void Cat::printBrain(void) const
{
    brain->printIdeas();
}
