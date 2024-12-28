#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <cstdlib>
#include <iostream>
#include <stdint.h>


struct Data
{
    int identifier;
    std::string name; 
};


class Serializer
{
    private:
        Serializer();
        Serializer(Serializer const &other);
        Serializer &operator=(const Serializer &obj);
        ~Serializer();
   
    public:
        static uintptr_t serialize(Data *ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif
