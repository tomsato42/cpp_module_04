#ifndef WRONGCAT_H
#define WRONGCAT_H
#include "WrongAnimal.h"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    ~WrongCat();
    WrongCat(const WrongCat &other);
    WrongCat &
    operator=(const WrongCat &other);
    void
    makeSound() const;
};

#endif // WRONGCAT_H
