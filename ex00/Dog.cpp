#include "Dog.h"
#include <iostream>

Dog::Dog()
{
    type = "Dog";
}
void
Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}
