#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H
#include "IMateriaSource.h"

class MateriaSource : public IMateriaSource
{
public:
    MateriaSource();
    ~MateriaSource();

    MateriaSource(const MateriaSource &);
    MateriaSource &
    operator=(const MateriaSource &);

    void
    learnMateria(AMateria *);
    AMateria *
    createMateria(std::string const &type);

private:
    AMateria *move_srcs[4];
    int src_count;
    void
    copySrcs(const MateriaSource &other);
    void
    deleteSrcs() const;
};

#endif // MATERIASOURCE_H
