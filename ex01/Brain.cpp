#include "Brain.h"

Brain::Brain() {}

Brain::~Brain() {}

Brain::Brain(const Brain& other)
{
    (void)other;
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
    }
    return *this;
}
