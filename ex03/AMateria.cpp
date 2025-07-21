#include "AMateria.h"
#include <iostream>

AMateria::AMateria()
{
    type_ = std::string("unknown");
    std::cout << "\033[1;33m* constructed AMateria *\033[0m" << std::endl;
}
AMateria::AMateria(std::string const &type)
{
    type_ = type;
    std::cout << "\033[1;33m* constructed AMateria of type " << type_ << " *\033[0m" << std::endl;
}

AMateria::~AMateria()
{
    std::cout << "\033[1;33m* destructed AMateria of type "<< type_ <<" *\033[0m" << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
    type_ = other.type_;
}

AMateria &
AMateria::operator=(const AMateria &other)
{
    if (this != &other)
    {
        type_ = other.type_;
    }
    return *this;
}

std::string const &
AMateria::getType() const
{
    return type_;
}
void
AMateria::use(ICharacter &target)
{
    std::cout << "You try to use Meta Materia on " << target.getName() << ", but it has no effect..." << std::endl;
}
