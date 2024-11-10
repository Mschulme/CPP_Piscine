#include "Cat.hpp"

Cat::Cat() : brain (new Brain())
{
    type = "Cat";
    std::cout << "Cat class: Default constructor called" << std::endl;
}


Cat::Cat(Cat const &obj) : Animal(obj), brain(new Brain(*obj.brain))
{
    if(this != &obj)
    {
        this->type = obj.type;
    }
    std::cout << "Cat class: Copy constructor called" << std::endl;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat class: Destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &obj)
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
    std::cout << "Cat class: Assignment operator called" << std::endl;
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Cat Barks" << std::endl;
}

std::string Cat::getType(void) const
{
    return (type);
}

void Cat::printBrain(void) const
{
    brain->printIdeas();
}
