#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main(void)
{
    std::cout << "Test function for printBrain()" << std::endl;
    Cat *Cat_brain = new Cat();
    Cat_brain->printBrain();
    delete Cat_brain;


    std::cout << "\n" << "Test function for Ideas" << std::endl;

    const int numberOfAnimals = 10;

    Animal *animals[numberOfAnimals];

    for (size_t i = 0; i < numberOfAnimals / 2; ++i)
        animals[i] = new Dog();

    for (size_t i = numberOfAnimals / 2; i < numberOfAnimals; ++i)
        animals[i] = new Cat();

    for (int i = 0; i < numberOfAnimals; ++i)
        delete animals[i];

    // Test for deep copy

    Dog* dog1 = new Dog();
    Dog* dog2 = new Dog(*dog1); 
    *dog2 = *dog1;
    delete dog1;
    delete dog2;
    
    return (EXIT_SUCCESS);
}
