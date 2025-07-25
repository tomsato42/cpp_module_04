#ifndef DOG_H
#define DOG_H
#include "Animal.h"

class Dog : public Animal
{
public:
    Dog();
    ~Dog();
    Dog(const Dog &other);
    Dog &
    operator=(const Dog &other);
    void
    makeSound() const;
};

#endif // DOG_H
