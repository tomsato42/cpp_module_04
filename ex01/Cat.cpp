#include "Cat.h"
#include <iostream>

Cat::Cat()
{
    type = "Cat";
    brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
    //ここをコメントアウトすると検証できるよ
    brain = new Brain(*other.brain);
}

Cat &
Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
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
Brain *
Cat::getBrain() const
{
    return brain;
}
