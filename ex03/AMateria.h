#ifndef AMATERIA_H
#define AMATERIA_H
#include "ICharacter.h"

#include <string>

class ICharacter;

class AMateria {
protected:
    std::string type_;
public:
    AMateria();
    AMateria(std::string const & type);
    virtual ~AMateria();

    AMateria(const AMateria&);
    AMateria& operator=(const AMateria&);

    std::string const & getType() const; //Returns the materia type

    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif // AMATERIA_H
