#include "Animal.h"
#include <iostream>

Animal::Animal()
{
    type = "Meta";
}

Animal::~Animal() {}

Animal::Animal(const Animal& other)
{
    (void)other;
}

Animal &
Animal::operator=(const Animal &other)
{
    if (this != &other)
    {
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
