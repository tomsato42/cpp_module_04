#include "Character.h"
#include <iostream>

void
Character::init_moves()
{
    for (int i = 0; i < 4; ++i)
        moves[i] = NULL;
}

void
Character::copy_moves(AMateria **dst, AMateria *const *src)
{
    for (int i = 0; i < 4; ++i)
    {
        if (src[i])
            dst[i] = src[i]->clone();
        else
            dst[i] = NULL;
    }
}

void
Character::delete_moves()
{
    for (int i = 0; i < 4; ++i)
    {
        if (moves[i])
        {
            delete moves[i];
            moves[i] = NULL;
        }
    }
}

Character::Character() : name_("Ash")
{
    init_moves();
    std::cout << "\033[34mCharacter default constructor called. Name set to \033[1m" << name_ << "\033[0;34m.\033[0m" << std::endl;
}
Character::Character(std::string const &name) : name_(name)
{
    init_moves();
    std::cout << "\033[34mCharacter constructor called. Name set to \033[1m" << name_ << "\033[0;34m.\033[0m" << std::endl;
}

Character::~Character()
{
    delete_moves();
    std::cout << "\033[34mCharacter destructor called. Name was \033[1m" << name_ << "\033[0;34m.\033[0m" << std::endl;
}

Character::Character(const Character &other)
{
    name_ = other.name_;
    copy_moves(moves, other.moves);
    std::cout << "\033[34mCharacter copy constructor called. Name set to \033[1m" << name_ << "\033[0;34m.\033[0m" << std::endl;
}

Character &
Character::operator=(const Character &other)
{
    if (this != &other)
    {
        name_ = other.name_;
        delete_moves();
        copy_moves(moves, other.moves);
    }
    return *this;
}
std::string const &
Character::getName() const
{
    return name_;
}
void
Character::equip(AMateria *m)
{
    if (!m)
    {
        std::cout << "\033[34mCannot equip \033[1mNULL\033[0;34m materia.\033[0m" << std::endl;
        return;
    }
    for (int i = 0; i < 4; ++i)
    {
        if (!moves[i])
        {
            std::cout << "\033[34mEquipped \033[1m" << m->getType() << "\033[0;34m to slot \033[1m" << i << "\033[0;34m.\033[0m" << std::endl;
            moves[i] = m;
            return;
        }
    }
    std::cout << "\033[34mCannot equip \033[1m" << m->getType() << "\033[0;34m: inventory full.\033[0m" << std::endl;
}
void
Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
    {
        std::cout << "\033[34mInvalid index: \033[1m" << idx << "\033[0;34m. Must be between 0 and 3.\033[0m" << std::endl;
        return;
    }
    if (!moves[idx])
    {
        std::cout << "\033[34mCannot unequip \033[1mNULL\033[0;34m materia.\033[0m" << std::endl;
        return;
    }
    moves[idx] = NULL;
    std::cout << "\033[34mUnequipped materia from slot \033[1m" << idx << "\033[0;34m.\033[0m" << std::endl;
}
void
Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= 4)
    {
        std::cout << "\033[34mInvalid index: \033[1m" << idx << "\033[0;34m. Must be between 0 and 3.\033[0m" << std::endl;
        return;
    }
    if (!moves[idx])
    {
        std::cout << "\033[34mCannot use \033[1mNULL\033[0;34m materia.\033[0m" << std::endl;
        return;
    }
    std::cout << "\033[34m\033[1m" << name_ << "\033[0;34m uses \033[1m" << moves[idx]->getType() << "\033[0;34m on \033[1m"
              << target.getName() << "\033[0;34m.\033[0m" << std::endl;
    moves[idx]->use(target);
}
