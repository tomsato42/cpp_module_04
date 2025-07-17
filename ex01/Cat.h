#ifndef CAT_H
#define CAT_H
#include "Animal.h"
#include "Brain.h"

class Cat : public Animal
{
public:
    Cat();
    Cat(const Cat &other);
    ~Cat();
    void
    makeSound() const;

private:
    Brain *brain;
};

#endif // CAT_H
