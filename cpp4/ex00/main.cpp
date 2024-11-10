#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main(void)
{
    const Animal *meta = new Animal();
    std::cout << std::endl; 
    const Animal *j = new Dog();
    std::cout << std::endl;
    const Animal *i = new Cat();
    std::cout << std::endl;
    std::cout << "Type: " << j->getType() << " " << std::endl;
    std::cout << "Type: " << i->getType() << " " << std::endl;
    std::cout << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();   
    std::cout << std::endl;
    delete meta, i, j;


    // Functions without virtual keyword

    std::cout << std::endl;
    const WrongAnimal *wrong_animal = new WrongAnimal();
    std::cout << std::endl;
    const WrongAnimal *wrong_i = new WrongCat();
    std::cout << std::endl;
    wrong_animal->makeSound();
    wrong_i->makeSound();
    std::cout << std::endl;
    delete wrong_animal, wrong_i;

    return (EXIT_SUCCESS);
}
