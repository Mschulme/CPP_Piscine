#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat class: Default constructor called" << std::endl;
}

Cat::Cat(Cat const &obj)
{
    if(this != &obj)
    {
        this->type = obj.type;
    }
}

Cat::~Cat()
{
    std::cout << "Cat class: Destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
    }
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
