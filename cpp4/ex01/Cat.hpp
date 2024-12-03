#ifndef CAT_HPP
#define CAT_HPP

#include "Brain.hpp"
#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        ~Cat();
        Cat(Cat const &other);
        Cat &operator=(const Cat &other);

        void makeSound(void) const;
        std::string getType(void) const;
        void printBrain(void) const;

    private:
        std::string type;
        Brain *brain;
};

#endif
