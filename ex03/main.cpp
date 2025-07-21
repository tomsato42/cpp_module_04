#include "Character.h"
#include "Cure.h"
#include "ICharacter.h"
#include "IMateriaSource.h"
#include "Ice.h"
#include "MateriaSource.h"

#include <iostream>
int
main()
{
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    // src->learnMateria(new Ice());
    // src->learnMateria(new Cure());
    // AMateria *tmpIce = src->createMateria("ice");
    // src->learnMateria(tmpIce);
    // delete tmpIce;
    ICharacter *me = new Character("me");
    AMateria *tmp = NULL;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    // me->unequip(4);
    // me->equip(NULL);
    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    // tmp = src->createMateria("cure");
    // me->equip(tmp);
    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    // delete tmp;

    ICharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    // me->use(2, *bob);
    // me->use(5, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}
