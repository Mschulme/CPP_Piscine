#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main(void)
{
    /*
    std::cout << "Turn into abstract class" << std::endl;
    Animal *animal = new Animal();
    delete animal;
    */

    std::cout << "---Example for abstract class---" << std::endl;
    Animal *cat = new Cat();
    delete cat;

    return (EXIT_SUCCESS);
}
