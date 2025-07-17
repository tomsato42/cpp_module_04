#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"

#include <iostream>
int
main()
{
    {
        const Animal *animals[10];

        for (int i = 0; i < 10; i++)
        {
            if (i % 2 == 0)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
        }
        for (int i = 0; i < 10; i++)
        {
            animals[i]->makeSound();
            delete animals[i];
        }
    }
    std::cout << "------------------" << std::endl;
    {
        const Dog dog1 = Dog();
        const Dog dog2 = Dog(dog1);
        const Dog dog3 = Dog(dog2);
    }
}
