#ifndef DOG_H
#define DOG_H
#include "Animal.h"

class Dog : public Animal {
    public:
        Dog();
        void makeSound() const;
};

#endif // DOG_H
