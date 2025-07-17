#include "WrongCat.h"
#include <iostream>
#include "WrongAnimal.h"

WrongCat::WrongCat()
{
    type = "WrongCat";
}
void
WrongCat::makeSound() const
{
    std::cout << "meeeow" << std::endl;
}
