#include "Dog.h"

#include <iostream>

Dog::Dog()
{
    type = "Dog";
}

Dog::~Dog() {}

Dog::Dog(const Dog &other) : Animal(other)
{
    (void)other;
}

Dog &
Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        Animal::operator=(other);
    }
    return *this;
}
void
Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}
