#include "Animal.h"
#include <iostream>

Animal::Animal()
{
    type = "Meta";
}

Animal::~Animal() {}

Animal::Animal(const Animal &other)
{
    this->type = other.type;
}

Animal &
Animal::operator=(const Animal &other)
{
    if (this != &other)
    {
        type = other.type;
    }
    return *this;
}
void
Animal::makeSound() const
{
    std::cout << "* Some generic animal sound" << std::endl;
}
std::string
Animal::getType() const
{
    return type;
}
