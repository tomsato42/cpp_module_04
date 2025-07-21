#ifndef CHARACTER_H
#define CHARACTER_H

#include "AMateria.h"
#include "ICharacter.h"
#include <string>

class Character : public ICharacter
{
public:
    Character();
    Character(std::string const &name);
    ~Character();

    Character(const Character &);
    Character &
    operator=(const Character &);

    std::string const &
    getName() const;
    void
    equip(AMateria *m);
    void
    unequip(int idx);
    void
    use(int idx, ICharacter &target);

private:
    std::string name_;
    AMateria *moves[4];

    void
    init_moves();
    static void
    copy_moves(AMateria **dst, AMateria *const *src);
    void
    delete_moves();
};

#endif // CHARACTER_H
