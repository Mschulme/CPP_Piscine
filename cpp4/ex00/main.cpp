#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main(void)
{
    std::cout << "Construction Animal Class" << std::endl;
    const Animal *meta = new Animal();
    std::cout << "Construction Dog Class" << std::endl;
    const Animal *j = new Dog();
    std::cout << "Construction Cat Class" << std::endl;
    const Animal *i = new Cat();

    std::cout << std::endl;
    std::cout << "Type: " << j->getType() << std::endl;
    std::cout << "Type: " << i->getType() << std::endl;
    std::cout << std::endl;

    std::cout << "Animal sounds: " << std::endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();
    std::cout << std::endl;
    delete i;
    delete j;
    delete meta;

    // Functions without virtual keyword
    std::cout << "\n" << "---WrongCat and WrongAnimal---" << std::endl;

    std::cout << "Construction WrongAnimal Class" << std::endl;
    const WrongAnimal *wrong_animal = new WrongAnimal();
    std::cout << "Construction WrongCat Class" << std::endl;
    const WrongAnimal *wrong_i = new WrongCat();
    std::cout << std::endl;
    wrong_animal->makeSound();
    wrong_i->makeSound();
    std::cout << std::endl;
    delete wrong_animal;
    delete wrong_i;

    return (EXIT_SUCCESS);
}
