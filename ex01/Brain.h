#ifndef BRAIN_H
#define BRAIN_H
#include <string>

#define IDEA_COUNT 100

class Brain {
public:
    Brain();
    ~Brain();

    Brain(const Brain&);
    Brain& operator=(const Brain&);

    void setIdea(unsigned int index, std::string idea);
    std::string getIdea(unsigned int index) const;
private:
    std::string ideas[100];
};

#endif // BRAIN_H
