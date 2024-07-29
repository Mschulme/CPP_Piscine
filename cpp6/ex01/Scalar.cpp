#include "Scalar.hpp"

Scalar::Scalar()
{
    std::cout << "Scalar Converter: Default constructor called" << std::endl;
}

Scalar::Scalar(Scalar const &obj)
{
    if(this != &obj)
    {
        *this = obj;
    }
}

Scalar::~Scalar()
{
;
}

Scalar &Scalar::operator=(const scalar &obj)
{
    if (this != &obj)
    {

    }
    return (*this);
}
