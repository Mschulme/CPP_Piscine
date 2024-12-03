#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat class: Default constructor called" << std::endl;
}

Cat::Cat(Cat const &other) : Animal(other)
{
    if(this != &other)
    {
        this->type = other.type;
    }
    std::cout << "Cat class: Copy constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat class: Destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        this->type = other.type;
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
