#ifndef Dog_HPP
#define Dog_HPP


#include "Brain.hpp"
#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(Dog const &other);
        ~Dog();
        Dog &operator=(const Dog &other);

        void makeSound(void) const;
        std::string getType(void) const;
        void printBrain(void) const;

    private:
        std::string type;
        Brain *brain;
};

#endif
