#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>

class Animal {
protected:
    std::string type;
public:
    Animal();
    virtual ~Animal();

    Animal(const Animal&);
    Animal& operator=(const Animal&);
    virtual void makeSound() const = 0;
    std::string getType() const;
private:
};

#endif // ANIMAL_H
