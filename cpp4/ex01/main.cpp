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
    delete meta;
    delete i;
    delete j;


    // Functions without virtual keyword

    std::cout << std::endl;
    const WrongAnimal *wrong_animal = new WrongAnimal();
    std::cout << std::endl;
    const WrongAnimal *wrong_i = new WrongCat();
    std::cout << std::endl;
    wrong_animal->makeSound();
    wrong_i->makeSound();
    std::cout << std::endl;
    delete wrong_animal;
    delete wrong_i;


    // Additions for ex01

    // Test for brain function

    Cat *Cat_brain = new Cat();
    Cat_brain->printBrain();
    delete Cat_brain;

    // 

    const int numberOfAnimals = 10;

    Animal *animals[numberOfAnimals];

    for (size_t i = 0; i < numberOfAnimals / 2; ++i)
    {
        animals[i] = new Dog();
    }
    for (size_t i = numberOfAnimals / 2; i < numberOfAnimals; ++i)
    {
        animals[i] = new Cat();
    }

    for (int i = 0; i < numberOfAnimals; ++i)
    {
        delete animals[i];
    }

    // Test for deep copy

    Dog* dog1 = new Dog();
    Dog* dog2 = new Dog(*dog1); 
    *dog2 = *dog1;
    delete dog1;
    delete dog2;
    


    return (EXIT_SUCCESS);
}
