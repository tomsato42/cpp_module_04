#include "Dog.h"
#include <iostream>

Dog::Dog()
{
    type = "Dog";
    brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other)
{
    brain = new Brain(*other.brain);
}

Dog &
Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog()
{
    delete brain;
}

void
Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}
