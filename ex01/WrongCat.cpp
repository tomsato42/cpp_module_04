#include "WrongCat.h"
#include "WrongAnimal.h"
#include <iostream>

WrongCat::WrongCat()
{
    type = "WrongCat";
}

WrongCat::~WrongCat() {}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
}

WrongCat &
WrongCat::operator=(const WrongCat &other)
{
    if (this != &other)
    {
        WrongAnimal::operator=(other);
    }
    return *this;
}

void
WrongCat::makeSound() const
{
    std::cout << "meeeow" << std::endl;
}
