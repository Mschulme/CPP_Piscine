#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(Cat const &other);
        ~Cat();
        Cat &operator=(const Cat &other);

        void makeSound(void) const;
        std::string getType(void) const;

    private:
        std::string type;
};

#endif
