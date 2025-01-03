#include "Serializer.hpp"

Serializer::Serializer() 
{
    std::cout << "Serializer: Default constructor called." << std::endl;
}


Serializer::~Serializer()
{
    std::cout << "Serializer: Destructor called." << std::endl;
}


Serializer::Serializer(const Serializer& other)
{
    std::cout << "Serializer: Copy constructor called." << std::endl;
    (void) other;
}


Serializer& Serializer::operator=(const Serializer& other)
{   
    std::cout << "Serializer: Assignment operator called." << std::endl;
    if (this != &other)
    {
        ;
    }
    return *this;
}


uintptr_t Serializer::serialize(Data* ptr)   //Guaranteed to be able to hold a pointer value on your platform.
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
