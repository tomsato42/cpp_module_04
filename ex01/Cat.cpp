#include "Cat.h"
#include <iostream>

Cat::Cat()
{
    type = "Cat";
    brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
    brain = new Brain(*other.brain);
}

Cat::~Cat()
{
    delete brain;
}

void
Cat::makeSound() const
{
    std::cout << "meow" << std::endl;
}
