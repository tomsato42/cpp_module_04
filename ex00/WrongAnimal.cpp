#include "WrongAnimal.h"

#include <iostream>

WrongAnimal::WrongAnimal()
{
    type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal() {}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    this->type = other.type;
}

WrongAnimal &
WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}
void
WrongAnimal::makeSound() const
{
    std::cout << "* Some generic wrong animal sound" << std::endl;
}
std::string
WrongAnimal::getType() const
{
    return type;
}
