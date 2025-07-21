#include "Cat.h"

#include <iostream>

Cat::Cat()
{
    type = "Cat";
}

Cat::~Cat() {}

Cat::Cat(const Cat &other) : Animal(other)
{
    (void)other;
}

Cat &
Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        Animal::operator=(other);
    }
    return *this;
}
void
Cat::makeSound() const
{
    std::cout << "meow" << std::endl;
}
