#include "MateriaSource.h"

#include <iostream>

MateriaSource::MateriaSource()
{
    src_count = 0;
    for (int i = 0; i < 4; i++)
    {
        move_srcs[i] = NULL;
    }
}

void
MateriaSource::deleteSrcs() const
{
    for (int i = 0; i < 4; i++)
    {
        if (move_srcs[i] != NULL)
        {
            delete move_srcs[i];
        }
    }
}
MateriaSource::~MateriaSource()
{
    deleteSrcs();
}

void
MateriaSource::copySrcs(const MateriaSource &other)
{
    for (int i = 0; i < 4; i++)
    {
        move_srcs[i] = other.move_srcs[i]->clone();
    }
}
MateriaSource::MateriaSource(const MateriaSource &other)
{
    src_count = other.src_count;
    copySrcs(other);
}

MateriaSource &
MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        src_count = other.src_count;
        deleteSrcs();
        copySrcs(other);
    }
    return *this;
}
void
MateriaSource::learnMateria(AMateria *src)
{
    if (src == NULL)
    {
        std::cout << "\033[31mMateriaSource::learnMateria(\033[1mNULL\033[0;31m) failed: Materia is NULL.\033[0m" << std::endl;
        return;
    }
    if (4 <= src_count)
    {
        std::cout << "\033[31mMateriaSource::learnMateria(\033[1m" << src->getType() << "\033[0;31m) failed: Inventory full.\033[0m" << std::endl;
        return;
    }
    move_srcs[src_count] = src;
    src_count++;
}
AMateria *
MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (move_srcs[i] == NULL)
            continue;
        if (move_srcs[i]->getType() == type)
        {
            std::cout << "\033[31mMateriaSource::createMateria(\033[1m" << type << "\033[0;31m)\033[0m" << std::endl;
            return move_srcs[i]->clone();
        }
    }
    std::cout << "\033[31mMateriaSource::createMateria(\033[1m" << type << "\033[0;31m) failed: Materia not found.\033[0m" << std::endl;
    return NULL;
}
