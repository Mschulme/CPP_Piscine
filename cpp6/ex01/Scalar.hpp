#ifndef Scalar_HPP
#define Scalar_HPP

#include <iostream>
#include <cstdlib>

class Scalar
{
    public:
        Scalar();
        Scalar(Scalar const &obj);
        ~Scalar();
        Scalar &operator=(const Scalar &obj);

    private:
};

#endif
