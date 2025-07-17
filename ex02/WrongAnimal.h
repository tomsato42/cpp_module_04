#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H
#include <string>

class WrongAnimal
{
protected:
    std::string type;

public:
    WrongAnimal();
    ~WrongAnimal();

    WrongAnimal(const WrongAnimal &);
    WrongAnimal &
    operator=(const WrongAnimal &);
    void
    makeSound() const;
    std::string
    getType() const;

private:
};

#endif // WRONGANIMAL_H
