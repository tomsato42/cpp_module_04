#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"

#include <iostream>
int
main()
{
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;
    std::cout << "-------------------------" << std::endl;
    const WrongAnimal *wrongMeta = new WrongAnimal();
    const WrongAnimal *wrongJ = new WrongCat();
    std::cout << wrongJ->getType() << " " << std::endl;
    wrongJ->makeSound();
    wrongMeta->makeSound();
    delete wrongMeta;
    delete wrongJ;
    return 0;
}
