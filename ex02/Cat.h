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
    Cat &
    operator=(const Cat &other);
    void
    makeSound() const;

    Brain* getBrain() const;

private:
    Brain *brain;
};

#endif // CAT_H
