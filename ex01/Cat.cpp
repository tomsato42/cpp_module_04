#include "Cat.h"
#include <iostream>

Cat::Cat()
{
    type = "Cat";
}
void
Cat::makeSound() const
{
    std::cout << "meow" << std::endl;
}
