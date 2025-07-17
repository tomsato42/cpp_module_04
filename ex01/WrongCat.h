#ifndef WRONGCAT_H
#define WRONGCAT_H
#include "WrongAnimal.h"

class WrongCat : public WrongAnimal {
public:
    WrongCat();
    void makeSound() const;
};

#endif // WRONGCAT_H
