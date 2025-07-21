#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

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
        // Animal animal = Animal(); //これは無効
        const Animal* tarou = new Dog();
        tarou->makeSound();
        delete tarou;
        // Animalは抽象クラスなので
        // 直接インスタンスにできないが、
        // 継承した派生クラスを多様性で
        // インスタンスを作ることはできる。

    }
    std::cout << "------------------" << std::endl;
}
