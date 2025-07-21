#include "Brain.h"

Brain::Brain() {}

Brain::~Brain() {}

Brain::Brain(const Brain& other)
{
    for (int i = 0; i < IDEA_COUNT; ++i) {
        ideas[i] = other.ideas[i];
    }
}

Brain &
Brain::operator=(const Brain &other)
{
    if (this != &other)
    {
        for (int i = 0; i < IDEA_COUNT; ++i)
        {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}
void
Brain::setIdea(unsigned int index, const std::string idea)
{
    if (index < IDEA_COUNT)
    {
        ideas[index] = idea;
    }
}
std::string
Brain::getIdea(unsigned int index) const
{
    if (index < IDEA_COUNT)
    {
        return ideas[index];
    }
    return std::string();
}
